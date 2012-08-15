#ifndef QTC_CONFIG_FILE_H
#define QTC_CONFIG_FILE_H

#include "common.h"

#define MAX_CONFIG_FILENAME_LEN   1024
#define MAX_CONFIG_INPUT_LINE_LEN 256

#define QTC_MENU_FILE_PREFIX   "menubar-"
#define QTC_STATUS_FILE_PREFIX "statusbar-"

#define qtcMenuBarHidden(A)         qtcBarHidden((A), QTC_MENU_FILE_PREFIX)
#define qtcSetMenuBarHidden(A, H)   qtcSetBarHidden((A), (H), QTC_MENU_FILE_PREFIX)
#define qtcStatusBarHidden(A)       qtcBarHidden((A), QTC_STATUS_FILE_PREFIX)
#define qtcSetStatusBarHidden(A, H) qtcSetBarHidden((A), (H), QTC_STATUS_FILE_PREFIX)

extern bool qtcBarHidden(const QString &app, const char *prefix);
extern void qtcSetBarHidden(const QString &app, bool hidden, const char *prefix);

extern void qtcLoadBgndImage(QtCImage *img);

extern const char *qtcGetHome();
extern const char *qtcConfDir();
extern void qtcSetRgb(color *col, const char *str);
extern void qtcDefaultSettings(Options *opts);
extern void qtcCheckConfig(Options *opts);
extern bool qtcReadConfig(const QString &file, Options *opts, Options *defOpts = 0L, bool checkImages = true);
extern WindowBorders qtcGetWindowBorderSize(bool force = false);

#ifdef CONFIG_WRITE
class KConfig;
extern bool qtcWriteConfig(KConfig *cfg, const Options &opts, const Options &def, bool exportingStyle = false);
#endif

#endif
