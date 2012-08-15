/*
  Vanish (C) Craig Drummond, 2003 - 2010 craig.p.drummond@gmail.com

  ----

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public
  License version 2 as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; see the file COPYING.  If not, write to
  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  Boston, MA 02110-1301, USA.
*/

#include <QDir>
#include <QGridLayout>
#include <QLabel>

#include "exportthemedialog.h"
#include "../config_file.h"

CExportThemeDialog::CExportThemeDialog(QWidget *parent)
    : QDialog(parent)
{
    QWidget *page = new QWidget(this);
    QGridLayout *layout = new QGridLayout(page);

    setButtons(Ok | Cancel);
    setDefaultButton(Ok);
    setCaption(tr("Export Theme"));
    layout->setSpacing(spacingHint());
    layout->setMargin(0);
    layout->addWidget(new QLabel(tr("Name:"), page), 0, 0);
    layout->addWidget(new QLabel(tr("Comment:"), page), 1, 0);
    layout->addWidget(new QLabel(tr("Destination folder:"), page), 2, 0);
    layout->addWidget(themeName = new QLineEdit(page), 0, 1);
    layout->addWidget(themeComment = new QLineEdit(tr("Vanish based theme"), page), 1, 1);
    layout->addWidget(themeUrl = new KUrlRequester(page), 2, 1);
    layout->addItem(new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Expanding), 3, 1);

    themeUrl->setMode(KFile::Directory | KFile::ExistingOnly | KFile::LocalOnly);
    themeUrl->lineEdit()->setReadOnly(true);
    themeUrl->setUrl(QDir::homePath());
    setMainWidget(page);
}

void CExportThemeDialog::run(const Options &o)
{
    opts = o;
    exec();
}

QSize CExportThemeDialog::sizeHint() const
{
    return QSize(400, 120);
}

void CExportThemeDialog::slotButtonClicked(int button)
{
    if (Ok == button) {
        QString name(themeName->text().trimmed().toLower());

        if (name.isEmpty())
            KMessageBox::error(this, tr("Name is empty!"));
        else {
            QString fileName(themeUrl->url().path() + "/"THEME_PREFIX + name + ".themerc");

            KConfig cfg(fileName, KConfig::SimpleConfig);
            bool    rv(cfg.isConfigWritable(false));

            if (rv) {
                cfg.group("Misc").writeEntry("Name", themeName->text().trimmed());
                cfg.group("Misc").writeEntry("Comment", themeComment->text());
                cfg.group("KDE").writeEntry("WidgetStyle", THEME_PREFIX + name);

                rv = qtcWriteConfig(&cfg, opts, opts, true);
            }

            if (rv) {
                QDialog::accept();
                KMessageBox::information(this, tr("Succesfully created:\n%1", fileName));
            } else
                KMessageBox::error(this, tr("Failed to create file: %1", fileName));
        }
    } else
        QDialog::reject();
}

#include "moc_exportthemedialog.cpp"
