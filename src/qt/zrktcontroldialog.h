// Copyright (c) 2017-2018 The ROCKETFUNDCOIN developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZRKTCONTROLDIALOG_H
#define ZRKTCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zrkt/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZRktControlDialog;
}

class CZRktControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZRktControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZRktControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZRktControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZRktControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZRktControlDialog(QWidget *parent);
    ~ZRktControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZRktControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZRktControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZRKTCONTROLDIALOG_H
