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
	bool					bClamping;			//Clamping模式

	bool					bUseAbsolute;		//是否在mapOpacity和mapColor中使用绝对值，默认false

	QMap<float, float>		mapOpacity;			//Opacity映射表
	QMap<float, RGBA>		mapColor;			//颜色映射表

	//mapOpacity,以及mapColor的Key必须在fMin和fMax此范围
	float					fMin;
	float					fMax;

	bool					bShade;				//是否使用阴影
	double					dAmbient;			//环境光因子
	double					dDiffuse;			//散射光因子
	double					dSpecular;			//反射光因子

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