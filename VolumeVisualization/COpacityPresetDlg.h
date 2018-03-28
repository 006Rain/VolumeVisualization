#ifndef COpacityPresetDlg_H
#define COpacityPresetDlg_H

#include <QDialog>
#include "CommonDef.h"

class COpacityPresetDlg : public QDialog
{
	Q_OBJECT

public:
	COpacityPresetDlg( QWidget *parent = 0 );
	~COpacityPresetDlg();

signals:
	void sigOpacityChanged( const VolumePropertyInfo& stProperty );
	
protected slots:
	void slotPropertyChanged( const QString& );

private:
	void InitWidget();
	void InitPropertyInfo();

private:
	VolumePropertyInfo m_stProperty_CT_Default;
	VolumePropertyInfo m_stProperty_CT_Body;
	VolumePropertyInfo m_stProperty_CT_Bone1;
	VolumePropertyInfo m_stProperty_CT_Bone2;
};

#endif // COpacityPresetDlg_H
