/*
 * Xournal++
 *
 * Loads Cursor Themes
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __CURSORTHEME_H__
#define __CURSORTHEME_H__

#include <XournalType.h>
#include <String.h>

#include <glib.h>

class CursorTheme
{
public:
	CursorTheme();
	virtual ~CursorTheme();

public:
	bool loadTheme(String name);

public:
	//	GdkCursor * getForPen(ToolSize size, int color);
	//	GdkCursor * getForEraser(ToolSize size, EraserType type);

private:
	XOJ_TYPE_ATTRIB;

	String author;
	String name;
	String description;

};

#endif /* __CURSORTHEME_H__ */
