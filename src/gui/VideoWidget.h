/****************************************************************************
* VLC-Qt - Qt and libvlc connector library
* VideoWidget.h: Video widget
*****************************************************************************
* Copyright (C) 2008-2010 Tadej Novak
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* This file may be used under the terms of the
* GNU General Public License version 3.0 as published by the
* Free Software Foundation and appearing in the file LICENSE.GPL
* included in the packaging of this file.
*****************************************************************************/

#ifndef VLCQT_VIDEOWIDGET_H_
#define VLCQT_VIDEOWIDGET_H_

#include <QtCore/QTimer>
#include <QtGui/QWidget>

/*!
	\class VlcVideoWidget VideoWidget.h vlc-qt/VideoWidget.h
	\brief Video widget

	This is one of VLC-Qt GUI classes.
	It provides video display and mouse control.
*/
class VlcVideoWidget : public QWidget
{
Q_OBJECT
public:
	/*!
		\brief VlcVideoWidget constructor
		\param parent video widget's parent GUI widget (QWidget)
	*/
	VlcVideoWidget(QWidget *parent = 0);

	/*!
		VlcVideoWidget destructor
	*/
	~VlcVideoWidget();


	/*!
		Get unique video widget ID to set it in the instance
		\return widget ID (WId)
		\sa VlcMediaPlayer::VlcMediaPlayer()
	*/
	WId widgetId() { return _widget->winId(); }

protected:
	void mouseDoubleClickEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);

signals:
	/*!
		\brief Signal sending fullscreen request
	*/
	void fullscreen();

	/*!
		\brief Signal sending right click and it's location
		\param QPoint right click location
	*/
	void rightClick(const QPoint);

	/*!
		\brief Signal sending mouse wheel direction
		\param bool true if up
	*/
	void wheel(const bool);

	/*!
		\brief Signal sending if mouse moved and cursor is showed
		\param QPoint global position
	*/
	void mouseShow(const QPoint);

	/*!
		\brief Signal sending if mouse cursor is hidden
	*/
	void mouseHide();


public slots:
	/*!
		\brief Enable mouse hide
	*/
	void enableMouseHide() { _hide = true; }
	/*!
		\brief Disable mouse hide
	*/
	void disableMouseHide() { _hide = false; }

	/*!
		\brief Toggle fullscreen
	*/
	void toggleFullscreen();

	/*!
		\brief Set previous video settings

		crop, ratio, deinterlacing filter
	*/
	void setPreviousSettings();

	/*!
		\brief Set ratio: Original
	*/
	void setRatioOriginal();
	/*!
		\brief Set ratio: 1:1
	*/
	void setRatio1_1();
	/*!
		\brief Set ratio: 4:3
	*/
	void setRatio4_3();
	/*!
		\brief Set ratio: 16:9
	*/
	void setRatio16_9();
	/*!
		\brief Set ratio: 16:10
	*/
	void setRatio16_10();
	/*!
		\brief Set ratio: 2.21:1
	*/
	void setRatio2_21_1();
	/*!
		\brief Set ratio: 5:4
	*/
	void setRatio5_4();

	/*!
		\brief Set crop: Original
	*/
	void setCropOriginal();
	/*!
		\brief Set crop: 16:9
	*/
	void setCrop16_9();
	/*!
		\brief Set crop: 16:10
	*/
	void setCrop16_10();
	/*!
		\brief Set crop: 1.85:1
	*/
	void setCrop1_85_1();
	/*!
		\brief Set crop: 2.21:1
	*/
	void setCrop2_21_1();
	/*!
		\brief Set crop: 2.35:1
	*/
	void setCrop2_35_1();
	/*!
		\brief Set crop: 2.39:1
	*/
	void setCrop2_39_1();
	/*!
		\brief Set crop: 5:4
	*/
	void setCrop5_4();
	/*!
		\brief Set crop: 5:3
	*/
	void setCrop5_3();
	/*!
		\brief Set crop: 4:3
	*/
	void setCrop4_3();
	/*!
		\brief Set crop: 1:1
	*/
	void setCrop1_1();

	/*!
		\brief Set deinterlace filter: Disabled
	*/
	void setFilterDisabled();
	/*!
		\brief Set deinterlace filter: Discard
	*/
	void setFilterDiscard();
	/*!
		\brief Set deinterlace filter: Blend
	*/
	void setFilterBlend();
	/*!
		\brief Set deinterlace filter: Mean
	*/
	void setFilterMean();
	/*!
		\brief Set deinterlace filter: Bob
	*/
	void setFilterBob();
	/*!
		\brief Set deinterlace filter: Linear
	*/
	void setFilterLinear();
	/*!
		\brief Set deinterlace filter: X
	*/
	void setFilterX();


private slots:
	void hideMouse();
	void applyPreviousSettings();

private:
	QWidget *_widget;
	QTimer *_timerMouse;
	QTimer *_timerSettings;

	bool _hide;

	QString _currentRatio;
	QString _currentCrop;
	QString _currentFilter;
};

#endif // VLCQ_VIDEOWIDGET_H_
