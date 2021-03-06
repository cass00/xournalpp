/*
 * Xournal++
 *
 * Dialog to select a Image (to insert as background)
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __IMAGESDIALOG_H__
#define __IMAGESDIALOG_H__

#include "../GladeGui.h"
#include <XournalType.h>

class Document;
class Settings;
class BackgroundImage;

class ImagesDialog: public GladeGui
{
public:
	ImagesDialog(GladeSearchpath* gladeSearchPath, Document* doc,
	             Settings* settings);
	virtual ~ImagesDialog();

public:
	virtual void show(GtkWindow* parent);

	void setBackgroundWhite();

	void setSelected(int selected);

	BackgroundImage getSelectedImage();
	bool shouldShowFilechooser();

	Settings* getSettings();
private:
	void layout();
	void updateOkButton();

	static void sizeAllocate(GtkWidget* widget, GtkRequisition* requisition,
	                         ImagesDialog* dlg);
	static void okButtonCallback(GtkButton* button, ImagesDialog* dlg);
	static void filechooserButtonCallback(GtkButton* button, ImagesDialog* dlg);

private:
	XOJ_TYPE_ATTRIB;

	bool backgroundInitialized;

	Settings* settings;

	int selected;
	int lastWidth;

	int selectedPage;

	GList* images;

	GtkWidget* scrollPreview;
	GtkWidget* widget;
};

#endif /* __IMAGESDIALOG_H__ */
