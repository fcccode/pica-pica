/*
	(c) Copyright  2012 - 2018 Anton Sviridenko
	https://picapica.im

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "picasystray.h"
#include "globals.h"
#include "picaactioncenter.h"
#include "accounts.h"

#ifdef PACKAGE_VERSION
#define VERSION_STRING "v"PACKAGE_VERSION
#else
#define VERSION_STRING ""
#endif

PicaSysTray::PicaSysTray(QObject *parent) :
	QObject(parent), emptyicon_(32, 32)
{
	systrayMenu_ = new QMenu();

	//Unity cannot into doubleclick on tray icon...  :(
	QAction *activate = new QAction(tr("&Activate"), this);
	connect(activate, SIGNAL(triggered()), this, SIGNAL(doubleclicked()));


	systrayMenu_->addAction(action_center->AboutAct());
	systrayMenu_->addAction(action_center->MuteSoundsAct());
	systrayMenu_->addAction(activate);
	systrayMenu_->addSeparator();
	systrayMenu_->addAction(action_center->ExitAct());

	systray_ = new QSystemTrayIcon(picapica_ico_sit);
	systray_->setContextMenu(systrayMenu_);
	systray_->setToolTip("Pica Pica Messenger "VERSION_STRING);
	systray_->show();

	connect(systray_, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(systray_activated(QSystemTrayIcon::ActivationReason)));
	connect(skynet, SIGNAL(BecameSelfAware()), this, SLOT(skynet_became_self_aware()));
	connect(skynet, SIGNAL(LostSelfAwareness()), this, SLOT(skynet_lost_self_awareness()));

	emptyicon_.fill(Qt::transparent);

}

void PicaSysTray::systray_activated(QSystemTrayIcon::ActivationReason r)
{
	if (r == QSystemTrayIcon::DoubleClick)
	{
		emit doubleclicked();
	}
}

void PicaSysTray::skynet_became_self_aware()
{
	systray_->setIcon(picapica_ico_fly);
	systray_->setToolTip(Accounts::GetCurrentAccount().name + " - Pica Pica Messenger "VERSION_STRING);
}

void PicaSysTray::skynet_lost_self_awareness()
{
	systray_->setIcon(picapica_ico_sit);
}

void PicaSysTray::StartBlinking()
{
	blink_ = systray_->icon();
	timer_id_ = startTimer(300);
}

void PicaSysTray::StopBlinking()
{
	killTimer(timer_id_);
	systray_->setIcon(blink_);
}

void PicaSysTray::timerEvent(QTimerEvent *event)
{
	static int blinker;

	blinker++ % 2 ? systray_->setIcon(blink_)
	:
	systray_->setIcon(QIcon(emptyicon_));

}
