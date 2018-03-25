#ifndef CVOLUMEOPACITYSETDLG_H
#define CVOLUMEOPACITYSETDLG_H

#include <QDialog>

class CVolumeOpacitySetDlg : public QDialog
{
	Q_OBJECT

public:
	CVolumeOpacitySetDlg( QWidget *parent = 0 );
	~CVolumeOpacitySetDlg();

private:
	void InitWidget();

private:
	
};

#endif // CVOLUMEOPACITYSETDLG_H
