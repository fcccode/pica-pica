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
#ifndef CONTACTLISTWIDGET_H
#define CONTACTLISTWIDGET_H

#include <QListWidget>
#include "contacts.h"
#include <QAction>

#include "chatwindow.h" //debug remove

class ContactListWidget : public QListWidget
{
	Q_OBJECT
public:
	explicit ContactListWidget(QWidget *parent = 0);
	~ContactListWidget();

	QAction *addcontactAct;
	QAction *delcontactAct;
	QAction *startchatAct;
	QAction *viewcertAct;
	QAction *showidAct;
	QAction *sendfileAct;
protected:
	void contextMenuEvent(QContextMenuEvent *event);

private:
	void setContactsStorage(Contacts *ct);
	Contacts* storage;
	QList<Contacts::ContactRecord> contact_records;
	QMap<QListWidgetItem*, Contacts::ContactRecord*> wgitem_to_recs;

	//ChatWindow *cw_debug_remove;

signals:

public slots:
	void Reload();

private slots:
	void add_contact();
	void del_contact();
	void start_chat();
	void view_cert();
	void show_id();
	void send_file();

	//void debug_onmsginput(QString msg, ChatWindow *sender_window);//debug remove after debug
};

#endif // CONTACTLISTWIDGET_H
