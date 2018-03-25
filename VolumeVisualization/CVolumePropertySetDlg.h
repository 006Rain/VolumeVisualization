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
	VolumePropertyInfo m_stProperty_CT_AAA;
	VolumePropertyInfo m_stProperty_CT_Bone;
	VolumePropertyInfo m_stProperty_CT_Muscle;
	VolumePropertyInfo m_stProperty_MR_MIP;
	VolumePropertyInfo m_stProperty_MR_T2_Brain;
};

#endif // CVolumePropertySetDlg_H
