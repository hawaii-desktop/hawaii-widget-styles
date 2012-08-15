#ifndef __QTCURVECONFIG_H__
#define __QTCURVECONFIG_H__

/*
  Vanish (C) Craig Drummond, 2007 - 2010 craig.p.drummond@gmail.com

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

#include <ui_vanishconfigbase.h>
#include "ui_stylepreview.h"
#include <QMap>
#include <QComboBox>
#include <KDE/KXmlGuiWindow>
#include "common.h"

class QComboBox;
class KDoubleNumInput;
#ifdef QTC_STYLE_SUPPORT
class CExportThemeDialog;
#endif
class VanishConfig;
class VanishKWinConfig;
class QStyle;
class QMdiSubWindow;
class CWorkspace;
class CStylePreview;
class CImagePropertiesDialog;
class KAboutData;
class KComponentData;

class CGradientPreview : public QWidget
{
    Q_OBJECT

public:

    CGradientPreview(VanishConfig *c, QWidget *p);
    ~CGradientPreview();

    QSize sizeHint() const;
    QSize minimumSizeHint() const;
    void paintEvent(QPaintEvent *);
    void setGrad(const Gradient &g);

public Q_SLOTS:

    void setColor(const QColor &col);

private:

    VanishConfig *cfg;
    QColor        color;
    Gradient      grad;
    QStyle        *style;
};

struct Preset {
    Preset(const Options &o, const QString &f = QString()) : loaded(true), opts(o), fileName(f) { }
    Preset(const QString &f = QString()) : loaded(false), fileName(f) { }

    bool    loaded;
    Options opts;
    QString fileName;
};

class CStylePreview : public KXmlGuiWindow, public Ui::StylePreview
{
    Q_OBJECT

public:

    CStylePreview(QWidget *parent = 0);
    ~CStylePreview();

    void closeEvent(QCloseEvent *e);
    QSize sizeHint() const;

Q_SIGNALS:

    void closePressed();

private:

    KAboutData     *aboutData;
    KComponentData *componentData;
};

class VanishConfig : public QWidget, private Ui::VanishConfigBase
{
    Q_OBJECT

public:

    VanishConfig(QWidget *parent);
    virtual ~VanishConfig();

    QSize    sizeHint() const;
    EShading currentShading() const {
        return (EShading)shading->currentIndex();
    }

Q_SIGNALS:

    void changed(bool);

public Q_SLOTS:

    void save();
    void defaults();

private Q_SLOTS:

    void setPreset();
    void updateChanged();
    void gtkButtonOrderChanged();
    void reorderGtkButtonsChanged();
    void focusChanged();
    void roundChanged();
    void savePreset();
    void deletePreset();
    void importPreset();
    void exportPreset();
    void exportTheme();
    void emboldenToggled();
    void defBtnIndicatorChanged();
    void buttonEffectChanged();
    void coloredMouseOverChanged();
    void shadeSlidersChanged();
    void shadeMenubarsChanged();
    void shadeCheckRadioChanged();
    void customMenuTextColorChanged();
    void menuStripeChanged();
    void shadePopupMenuChanged();
    void progressColorChanged();
    void comboBtnChanged();
    void sortedLvChanged();
    void crColorChanged();
    void stripedProgressChanged();
    void shadingChanged();
    void activeTabAppearanceChanged();
    void tabMoChanged();
    void passwordCharClicked();
    void unifySpinBtnsToggled();
    void unifySpinToggled();
    void sliderThumbChanged();
    void sliderWidthChanged();
    void menubarHidingChanged();
    void xbarChanged();
    void windowBorder_colorTitlebarOnlyChanged();
    void windowBorder_blendChanged();
    void windowBorder_menuColorChanged();
    void thinSbarGrooveChanged();
    void borderSbarGrooveChanged();
    void borderProgressChanged();
    void squareProgressChanged();
    void fillProgressChanged();
    void titlebarButtons_customChanged();
    void titlebarButtons_useHoverChanged();
    void bgndAppearanceChanged();
    void bgndImageChanged();
    void menuBgndAppearanceChanged();
    void menuBgndImageChanged();
    void configureBgndAppearanceFile();
    void configureBgndImageFile();
    void configureMenuBgndAppearanceFile();
    void configureMenuBgndImageFile();
    void groupBoxChanged();
    void changeStack();
    void gradChanged(int i);
    void borderChanged(int i);
    void editItem(QTreeWidgetItem *i, int col);
    void itemChanged(QTreeWidgetItem *i, int col);
    void addGradStop();
    void removeGradStop();
    void updateGradStop();
    void stopSelected();
    void exportKDE3();
    void exportQt();
    void menubarTitlebarBlend();
    void updatePreview();
    void copyGradient(QAction *act);
    void previewControlPressed();

public:

    bool savePreset(const QString &name);
    QString getPresetName(const QString &cap, QString label, QString def, QString name = QString());
    void setupStack();
    void setupPresets(const Options &currentStyle, const Options &defaultStyle);
    void setupPreview();
    void setupGradientsTab();
    void setupShadesTab();
    void setupShade(KDoubleNumInput *w, int shade);
    void setupAlpha(KDoubleNumInput *w, int alpha);
    void populateShades(const Options &opts);
    bool diffShades(const Options &opts);
    bool haveImages();
    bool diffImages(const Options &opts);
    void setPasswordChar(int ch);
    int  getTitleBarButtonFlags();
    void setOptions(Options &opts);
    void setWidgetOptions(const Options &opts);
    int  getDwtSettingsFlags();
    int  getSquareFlags();
    int  getWindowBorderFlags();
    int  getGroupBoxLabelFlags();
    int  getThinFlags();
    bool diffTitleBarButtonColors(const Options &opts);
    bool settingsChanged(const Options &opts);
    bool settingsChanged() {
        return settingsChanged(presets[currentText].opts);
    }

private:

    Options                previewStyle;
    CWorkspace             *workSpace;
    CStylePreview          *stylePreview;
    QMdiSubWindow          *mdiWindow;
    QMap<QString, Preset>  presets;
#ifdef QTC_STYLE_SUPPORT
    CExportThemeDialog     *exportDialog;
#endif
    CGradientPreview       *gradPreview;
    GradientCont           customGradient;
    KDoubleNumInput        *shadeVals[NUM_STD_SHADES],
                           *alphaVals[NUM_STD_ALPHAS];
    QString                currentText,
                           defaultText;
    VanishKWinConfig      *kwin;
    int                    kwinPage;
    bool                   readyForPreview;
    CImagePropertiesDialog *bgndPixmapDlg,
                           *menuBgndPixmapDlg,
                           *bgndImageDlg,
                           *menuBgndImageDlg;
};

#endif
