#ifndef CVolumePropertySetDlg_H
#define CVolumePropertySetDlg_H

#include <QDialog>
#include "CommonDef.h"

class CVolumePropertySetDlg : public QDialog
{
	Q_OBJECT

public:
	CVolumePropertySetDlg( QWidget *parent = 0 );
	~CVolumePropertySetDlg();

signals:
	void sigPropertyChanged( const VolumePropertyInfo& stProperty );
	
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

#endif // CVolumePropertySetDlg_H
