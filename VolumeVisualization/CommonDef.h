#pragma once

#include <QMap>
#include <QString>

enum DataType
{
	Char, Short, Float
};

struct ImageParams
{
	int nDimX;
	int nDimY;
	int nDimZ;

	double dPixelX;
	double dPixelY;
	double dPixelZ;

	int nOffset;
	DataType eDataType;

	QString strFilePath;

	ImageParams()
	{
		nDimX = 64;
		nDimY = 64;
		nDimZ = 64;

		dPixelX = 0.1;
		dPixelY = 0.1;
		dPixelZ = 0.1;

		nOffset = 0;
		eDataType = Char;
	}
};

struct RGBA
{
	double	m_r;
	double	m_g;
	double	m_b;
	double	m_a;
	RGBA()
	{
		m_r = 0;
		m_g = 0;
		m_b = 0;
		m_a = 255;
	}
};

struct VolumePropertyInfo
{
	bool					bClamping;			//Clampingģʽ

	bool					bUseAbsolute;		//�Ƿ���mapOpacity��mapColor��ʹ�þ���ֵ��Ĭ��false

	QMap<float, float>		mapOpacity;			//Opacityӳ���
	QMap<float, RGBA>		mapColor;			//��ɫӳ���

	//mapOpacity,�Լ�mapColor��Key������fMin��fMax�˷�Χ
	float					fMin;
	float					fMax;

	bool					bShade;				//�Ƿ�ʹ����Ӱ
	double					dAmbient;			//����������
	double					dDiffuse;			//ɢ�������
	double					dSpecular;			//���������

	VolumePropertyInfo()
	{
		bClamping = true;
		bUseAbsolute = false;

		//Color
		mapColor.clear();
		RGBA rgba;
		rgba.m_r = 0;
		rgba.m_g = 0;
		rgba.m_b = 0;
		rgba.m_a = 255;
		mapColor[ 0.0 ] = rgba;

		rgba.m_r = 255;
		rgba.m_g = 255;
		rgba.m_b = 0;
		mapColor[ 0.25 ] = rgba;
		rgba.m_r = 0;
		rgba.m_g = 255;
		rgba.m_b = 0;
		mapColor[ 0.5 ] = rgba;

		rgba.m_r = 0;
		rgba.m_g = 255;
		rgba.m_b = 255;
		mapColor[ 0.75 ] = rgba;
		rgba.m_r = 0;
		rgba.m_g = 0;
		rgba.m_b = 255;
		mapColor[ 1.0 ] = rgba;

		//Opacity
		mapOpacity.clear();
		mapOpacity[ 0 ] = 0.0;
		mapOpacity[ 0.25 ] = 0.2;
		mapOpacity[ 0.5 ] = 0.4;
		mapOpacity[ 0.75 ] = 0.6;
		mapOpacity[ 1.0 ] = 0.4;

		fMin = -1100;
		fMax = 1100;

		//Shader
		bShade = true;
		dAmbient = 0.4;
		dDiffuse = 0.6;
		dSpecular = 0.2;
	}
};