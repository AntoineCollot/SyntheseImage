#ifndef __COLOR_H
#define __COLOR_H

#include <math.h>
#include <string>
#include <sstream>

using namespace std;

class CRTColor
{
	public :

		CRTColor ()
			:	m_fR	(0.0f),
				m_fG	(0.0f),
				m_fB	(0.0f)
		{
		}

		CRTColor (float fR,float fG,float fB)
			:	m_fR	(fR),
				m_fG	(fG),
				m_fB	(fB)
		{
		}
		
		CRTColor (float fValue)
			:	m_fR	(fValue),
				m_fG	(fValue),
				m_fB	(fValue)
		{
		}

		bool IsBlack () const { return ( (m_fR==0.0f) && (m_fG==0.0f) && (m_fB==0.0f) ) ; }

		bool IsWhite () const { return ( (m_fR==1.0f) && (m_fG==1.0f) && (m_fB==1.0f) ) ; }

		string ToString()
		{
			ostringstream os;
			os << "Red : "<< m_fR<<", Green : "<<m_fG<<", Blue : "<<m_fB;
			return os.str();
		}

		char RedToChar()
		{
			return (unsigned char)(m_fR * 255);
		}

		char GreenToChar()
		{
			return (unsigned char)(m_fG * 255);
		}

		char BlueToChar()
		{
			return (unsigned char)(m_fB * 255);
		}

		static CRTColor Red()
		{
			return CRTColor(0, 0, 1);
		}

		static CRTColor Green()
		{
			return CRTColor(0, 1, 0);
		}

		static CRTColor Blue()
		{
			return CRTColor(1, 0, 0);
		}

		static CRTColor White()
		{
			return CRTColor(1, 1, 1);
		}

		static CRTColor Black()
		{
			return CRTColor(0, 0, 0);
		}

		CRTColor operator + (const CRTColor & c) const
		{
			return CRTColor (m_fR+c.m_fR,m_fG+c.m_fG,m_fB+c.m_fB) ;
		}

		CRTColor operator - (const CRTColor & c) const
		{
			return CRTColor (m_fR-c.m_fR,m_fG-c.m_fG,m_fB-c.m_fB) ;
		}

		CRTColor operator * (float fFactor) const
		{
			return CRTColor (m_fR*fFactor,m_fG*fFactor,m_fB*fFactor) ;
		}

		CRTColor operator * (const CRTColor & cColor) const
		{
			return CRTColor (m_fR*cColor.m_fR,m_fG*cColor.m_fG,m_fB*cColor.m_fB) ;
		}

		CRTColor operator / (float fFactor) const
		{
			return CRTColor (m_fR/fFactor,m_fG/fFactor,m_fB/fFactor) ;
		}

		CRTColor operator ^ (float k)           const
		{
			return CRTColor ((float)pow(m_fR,k),(float)pow(m_fG,k),(float)pow(m_fB,k)) ;
		}
		
		CRTColor & operator += (const CRTColor & cColor)
		{
			m_fR+=cColor.m_fR;
			m_fG+=cColor.m_fG;
			m_fB+=cColor.m_fB;
			return *this;
		}

		CRTColor & operator -= (const CRTColor & cColor)
		{
			m_fR-=cColor.m_fR;
			m_fG-=cColor.m_fG;
			m_fB-=cColor.m_fB;
			return *this;
		}

		CRTColor & operator *= (float fFactor)
		{
			m_fR*=fFactor;
			m_fG*=fFactor;
			m_fB*=fFactor;
			return *this;
		}

		CRTColor & operator *= (const CRTColor & cColor)
		{
			m_fR*=cColor.m_fR;
			m_fG*=cColor.m_fG;
			m_fB*=cColor.m_fB;
			return *this;
		}

		CRTColor & operator /= (float fFactor)
		{
			m_fR/=fFactor;
			m_fG/=fFactor;
			m_fB/=fFactor;
			return *this;
		}

		bool operator == ( const CRTColor &cColor ) const
		{
			return ( (m_fR==cColor.m_fR) && (m_fG==cColor.m_fG) && (m_fB==cColor.m_fB) ) ;
		}

		bool operator != ( const CRTColor &cColor ) const
		{
			return ( (m_fR!=cColor.m_fR) || (m_fG!=cColor.m_fG) || (m_fB!=cColor.m_fB) ) ;
		}

		float m_fR , m_fG , m_fB ;
} ;

#endif
