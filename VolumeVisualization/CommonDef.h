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
	int	m_nR;
	int	m_nG;
	int	m_nB;
	int	m_nA;
	RGBA()
	{
		m_nR = 0;
		m_nG = 0;
		m_nB = 0;
		m_nA = 255;
	}
};

struct VolumePropertyInfo
{
	bool					bClamping;			//Clamping模式

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

		//Color
		mapColor.clear();
		RGBA rgba;
		rgba.m_nR = 0;
		rgba.m_nG = 0;
		rgba.m_nB = 0;
		rgba.m_nA = 255;
		mapColor[ 0.0 ] = rgba;

		rgba.m_nR = 255;
		rgba.m_nG = 255;
		rgba.m_nB = 0;
		mapColor[ 0.25 ] = rgba;
		rgba.m_nR = 0;
		rgba.m_nG = 255;
		rgba.m_nB = 0;
		mapColor[ 0.5 ] = rgba;

		rgba.m_nR = 0;
		rgba.m_nG = 255;
		rgba.m_nB = 255;
		mapColor[ 0.75 ] = rgba;
		rgba.m_nR = 0;
		rgba.m_nG = 0;
		rgba.m_nB = 255;
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