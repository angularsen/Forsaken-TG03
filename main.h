#define STRICT
//#define INITGUID
#define WIN32_LEAN_AND_MEAN
//#define _WIN32_WINDOWS 0x0410	// Compile for Windows98 and newer

#define DEF_APPNAME		_T("Forsaken - TG03")


// Macros
#define SAFE_DELETE(p)  { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }
#define MessageBoxOK( MBTEXT )	 MessageBox( NULL, MBTEXT, NULL, MB_OK ) 
#define ScreenMidX( WIDTH )		(FLOAT)(d3dApp->m_d3dsdBackBuffer.Width / 2)  - (WIDTH / 2)
#define ScreenMidY( HEIGHT )	(FLOAT)(d3dApp->m_d3dsdBackBuffer.Height / 2) - (HEIGHT / 2)


#define DBR_OK				-2
#define DBR_CANCEL			-3
#define DBR_NOENTRY			-4

// DirectGraphics related
#define D3DFVF                  WORD
#define D3DFVF_ALLVERTEX		( D3DFVF_XYZ	| D3DFVF_NORMAL	| D3DFVF_PSIZE	| D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1 )
#define D3DFVF_VERTEX			( D3DFVF_XYZ )
#define D3DFVF_TLVERTEX			( D3DFVF_XYZRHW | D3DFVF_DIFFUSE	)				
#define D3DFVF_TTVERTEX		( D3DFVF_XYZRHW | D3DFVF_DIFFUSE| D3DFVF_TEX1 )
#define D3DFVF_LTVERTEX			( D3DFVF_XYZ	| D3DFVF_DIFFUSE| D3DFVF_TEX1 )
#define D3DFVF_NVERTEX			( D3DFVF_XYZ	| D3DFVF_NORMAL )
#define D3DFVF_NLVERTEX			( D3DFVF_XYZ	| D3DFVF_NORMAL	|	D3DFVF_DIFFUSE )
#define D3DFVF_NTVERTEX			( D3DFVF_XYZ	| D3DFVF_NORMAL	|	D3DFVF_TEX1 )
#define D3DFVF_NLTVERTEX		( D3DFVF_XYZ	| D3DFVF_NORMAL	|	D3DFVF_DIFFUSE  | D3DFVF_TEX1 )
#define D3DFVF_NL2TVERTEX		( D3DFVF_XYZ	| D3DFVF_NORMAL	|	D3DFVF_DIFFUSE  | D3DFVF_TEX2 | D3DFVF_TEXCOORDSIZE2(0) | D3DFVF_TEXCOORDSIZE2(1) )
#define D3DFVF_LVERTEX			( D3DFVF_XYZ	| D3DFVF_DIFFUSE )
#define D3DFVF_TTVERTEX			( D3DFVF_XYZRHW | D3DFVF_TEX1		)
#define D3DFVF_TNVERTEX			( D3DFVF_XYZ	| D3DFVF_NORMAL | D3DFVF_TEX1 )

// Light definitions
#define LIGHT_DIRECTIONAL 7		// The general purpose directional light
#define LIGHT_POINT		  6		// The general purpose point light


#include <windows.h>
#include <mmsystem.h>
#include <basetsd.h>
#include <stdio.h>
#include <stdlib.h>
#include <commctrl.h>
#include <time.h>

#include "common\\D3DX8.h"
#include "common\\D3DApp.h"
#include "common\\D3DFont.h"
#include "common\\D3DFile.h"
#include "common\\D3DX8math.h"
#include "common\\D3DUtil.h"
#include "common\\DXUtil.h"
#include "common\\dxerr8.h"

#include "resource.h"
#include "fmod.h"


struct ARGB
{
	BYTE a;
	BYTE r;
	BYTE g;
	BYTE b;
};


struct BPARTICLE
{
	D3DXVECTOR3 v;			// World position. 
	D3DXVECTOR3 vPrevOffset;
	D3DXVECTOR3 vNextOffset;
	FLOAT fSize;
	FLOAT fSegProg;
	FLOAT fAdvance;
	FLOAT fStartOffset;
	FLOAT fLastTime;
	INT iCurWaypoint;	
};

struct FRECT
{
	FLOAT left;
	FLOAT top;
	FLOAT right;
	FLOAT bottom;
};

typedef struct
{
   D3DXVECTOR3 p[3];
} TRIANGLE;

typedef struct
{
   D3DXVECTOR3 p[8];
   FLOAT val[8];
} GRIDCELL;

struct WAVEDATA
{
	BOOL bDataIsSet;
	FLOAT fPosX;
	FLOAT fPosY;
	FLOAT fRadius;
    FLOAT fWaveWidth;
	FLOAT fStrength;
	FLOAT fTimeStart;
	FLOAT fTimeEnd;
	FLOAT fSinTable[WATER_VERTS];
	FLOAT fVertDist[WATER_VERTS];
	FLOAT fVertAffection[WATER_VERTS];
	
};

struct ALLVERTEX
{
	FLOAT x, y, z;		// Untransformed
	FLOAT nx, ny, nz;	// Normalized
	DWORD diffuse;		// Lit by diffuse color
	FLOAT tu, tv;		// Textured
};


struct VERTEX	// Untransformed, unlit
{
	FLOAT x, y, z;
};

struct TLVERTEX	// Transformed and lit
{
	FLOAT x, y, z;
	FLOAT rhw;
	DWORD diffuse;
};

struct TTVERTEX	// Transformed, lit and textured
{
	FLOAT x, y, z;
	FLOAT rhw;
	DWORD diffuse;
	FLOAT tu, tv;
};

struct LTVERTEX	// Lit and textured
{
	FLOAT x, y, z;
	DWORD diffuse;
	FLOAT tu, tv;
};


struct NVERTEX		// Normaled and textured
{
	FLOAT x, y, z;
	FLOAT nx, ny, nz;
};

struct NLVERTEX		// Normaled and lit
{
	FLOAT x, y, z;
	FLOAT nx, ny, nz;
	DWORD diffuse;
};

struct NTVERTEX		// Normaled and textured
{
	FLOAT x, y, z;
	FLOAT nx, ny, nz;
	FLOAT tu, tv;
};


struct NLTVERTEX	// Normaled, lit and textured
{
	FLOAT x, y, z;
	FLOAT nx, ny, nz;
	DWORD diffuse;
	FLOAT tu, tv;
};

struct NL2TVERTEX	// Normaled, lit and two sets of texturecoords
{
	FLOAT x, y, z;
	FLOAT nx, ny, nz;
	DWORD diffuse;
	FLOAT tu1, tv1;
	FLOAT tu2, tv2;
};

struct LVERTEX	// Lit vertex (for use with lines and such)
{
	FLOAT x, y, z;
	DWORD diffuse;
};

struct METABALL
{
	D3DXVECTOR3 v;
	FLOAT fRadius;
	// Waypoints?
};


struct TLTQUAD	// Used in ShowTextureVB. Describes a quad of TTVERTEXes
{
	TTVERTEX vertex[4];
};


struct FIREFLY
{
	D3DXVECTOR3 v[FIREFLY_GLOWLAYERS];	// World position. 0 is actual position, and 1-3 are history positions (to create a glow effect)
	BOOL  bExists;
	FLOAT fSize;
	FLOAT fVisibility;
	FLOAT fSegProg;
	FLOAT fSegTStart;
	FLOAT fSegTCurrent;
	FLOAT fSegTLength;
	FLOAT fTimeDiff;
	D3DXVECTOR3 vSwirlV0;
	D3DXVECTOR3 vSwirlV1;
	D3DXVECTOR3 vSwirlV2;
	D3DXVECTOR3 vSwirlV3;
};

struct WAYPOINT3D
{
	FLOAT fTime;
	D3DXVECTOR3 v;
};



//-----------------------------------------------------------------------------
// Name: class CFireFlies
// Desc: Particle system for a group of fireflies
//-----------------------------------------------------------------------------

class CFireFlies
{
public:
    CFireFlies						( INT iStartFlies );
    HRESULT AddFlies				( INT cNewFlies, D3DXVECTOR3 vPos, FLOAT fTimeStart, FLOAT fCurrent, FLOAT fTimeDiff, LONG lRandSeed );
    HRESULT Animate					( FLOAT fLocalTime );
    INT		GetNum					() { return m_iNumFlies; }
	HRESULT InvalidateDeviceObjects	();
    HRESULT Render					();
	HRESULT InitDeviceObjects		();
	
protected:
	D3DLIGHT8				m_light;
	LPDIRECT3DTEXTURE9      m_ptexFirefly;
	LPDIRECT3DVERTEXBUFFER9 m_pVB;	// Vertex buffer for textured quad
	
	WAYPOINT3D	m_wpWaypoint[MAX_FIREFLY_WAYPOINTS];
	FIREFLY		m_fly[MAX_FIREFLIES];
	D3DXVECTOR3 m_vGroupPos;
	D3DXVECTOR3	m_vAveragePos;

	INT		m_iCurrentWaypoint;
	INT		m_iNumWaypoints;
	FLOAT	m_fFlyRadius;
	FLOAT	m_fGroupRadius;
	FLOAT	m_fSpeed;
    FLOAT	m_fTimeStart;
    FLOAT	m_fTimeEnd;
  	INT		m_iNumFlies;
};





//-----------------------------------------------------------------------------
// Name: class CBloodParticles
// Desc: Particle system for a group of fireflies
//-----------------------------------------------------------------------------

class CBloodParticles
{
	friend class CTunnel2;
public:
    CBloodParticles					();
    HRESULT Animate					( FLOAT fLocalTime, FLOAT fCameraProgress );
	HRESULT InitDeviceObjects		();
	HRESULT InvalidateDeviceObjects	();
    HRESULT Render					();
	
protected:
	LPDIRECT3DTEXTURE9      m_ptexParticle;
	LPDIRECT3DVERTEXBUFFER9 m_pVB;	// Vertex buffer for textured quad
	
	WAYPOINT3D	m_wpWaypoint[TUNNEL2_WAYPOINTS+2];
	BPARTICLE	m_particle[BLOOD_PARTICLES];

	INT		m_iCurrentWaypoint;
	INT		m_iNumWaypoints;
	FLOAT	m_fParticleRadius;
  	INT		m_iNumParticles;
};




//-----------------------------------------------------------------------------
// Name: class CMetaBall
// Desc: Handles the modelling, animation and rendering of metaballs
//-----------------------------------------------------------------------------

class CMetaBall
{
public:
    CMetaBall						();
    HRESULT Animate					( FLOAT fLocalTime );
	HRESULT GenerateIsoValues		( GRIDCELL* pGridCell );
	HRESULT GenerateMetaMesh		( FLOAT fLocalTime );
	HRESULT InitDeviceObjects		();
	HRESULT InvalidateDeviceObjects	();
	HRESULT Overlay					( FLOAT fLocalTime );
    HRESULT Render					();


	LPD3DXMESH				m_pmeshMetaBall;
	LPDIRECT3DTEXTURE9		m_ptexMetaBall;
	LPDIRECT3DTEXTURE9		m_ptexBackground;
	LPDIRECT3DVERTEXBUFFER9 m_pVB;	// Vertex buffer for metaball
	LPDIRECT3DINDEXBUFFER9	m_pIB;

	METABALL	m_ball[METAB_BALLS];
	INT			m_iNumBalls;
	INT			m_iNumTriangles;
	D3DSURFACE_DESC	m_sdBackground;

};



//-----------------------------------------------------------------------------
// Name: class CTextGrid
// Desc: Handles the animation and rendering of text in the textscene
//-----------------------------------------------------------------------------

class CTextGrid
{
public:
    CTextGrid						();
    HRESULT Animate					( FLOAT fLocalTime );
	HRESULT GenerateGrid			( INT iCubeX, INT iCubeY, INT iCubeZ );
	HRESULT InitDeviceObjects		();
	HRESULT InvalidateDeviceObjects	();
	HRESULT Overlay					( FLOAT fLocalTime );
    HRESULT Render					();
	HRESULT SetGridQuad				( GRID_VERTEX vBuffer[4], D3DXVECTOR3 v1, D3DXVECTOR3 v2, FLOAT fAlpha=255.0f, FLOAT fTile=1.0f, FLOAT fTileOffset=0.0f );
	HRESULT ScrollText				( FLOAT fSpeed );
	HRESULT SortGrid				();
	
	
protected:
	D3DLIGHT8				m_light;
	LPDIRECT3DTEXTURE9      m_ptexText1;
	LPDIRECT3DTEXTURE9		m_ptexOverlay;
	LPDIRECT3DTEXTURE9		m_ptexOverlayText;

	LPDIRECT3DVERTEXBUFFER9 m_pVB;	// Vertex buffer for textured quads
	LPDIRECT3DINDEXBUFFER9	m_pIB;

	INT	m_iCubeX;	// Which cube in the grid the camera 
	INT m_iCubeY;	// is currently positioned in.
	INT m_iCubeZ;	// Used to automatically generate grid as camera moves to new cubes.
	FLOAT m_fScrollOffsetX;
	FLOAT m_fScrollOffsetY;
	FLOAT m_fScrollOffsetZ;
};


//-----------------------------------------------------------------------------
// Name: class CTunnel
// Desc: Handles the animation and rendering of tunnel1
//-----------------------------------------------------------------------------

class CTunnel
{
public:
    CTunnel	();
    HRESULT Animate					( FLOAT fLocalTime );
	HRESULT FlyCamera				( FLOAT fProgress, BOOL bWaypointChanged );
	HRESULT GenerateTunnel			( LPDIRECT3DVERTEXBUFFER9 pVB, LPDIRECT3DINDEXBUFFER9 pIB, FLOAT fTunnelRadius, BOOL bGenerateWaypoint );
	HRESULT InitDeviceObjects		();
	HRESULT InvalidateDeviceObjects	();
	HRESULT Overlay					( FLOAT fLocalTime );
    HRESULT Render					();
	HRESULT	RotateTexCoords			( LPDIRECT3DVERTEXBUFFER9 pVB, LPDIRECT3DINDEXBUFFER9 pIB, FLOAT fRot, FLOAT fAlpha=255.0f );
	
protected:
	LPDIRECT3DTEXTURE9		m_ptexTunnel;
	LPDIRECT3DTEXTURE9		m_ptexPlasma;
	LPDIRECT3DTEXTURE9		m_ptexPlasma2;
	LPDIRECT3DVERTEXBUFFER9	m_pvbTunnel1;
	LPDIRECT3DINDEXBUFFER9	m_pibTunnel1;
	LPDIRECT3DVERTEXBUFFER9	m_pvbTunnel2;
	LPDIRECT3DINDEXBUFFER9	m_pibTunnel2;
	LPDIRECT3DVERTEXBUFFER9	m_pvbTunnel3;
	LPDIRECT3DINDEXBUFFER9	m_pibTunnel3;

	INT						m_iNumTexts;
	LPDIRECT3DTEXTURE9		m_ptexText[8];
	LPDIRECT3DTEXTURE9		m_ptexWhatIf;
	LPDIRECT3DTEXTURE9		m_ptexWereBlaim;
	LPDIRECT3DTEXTURE9		m_ptexHumansAre;
	LPDIRECT3DTEXTURE9		m_ptexPsychologically;
	LPDIRECT3DTEXTURE9		m_ptexTheSun;
	LPDIRECT3DTEXTURE9		m_ptexTheEarth;
	LPDIRECT3DTEXTURE9		m_ptexWillBlaim;
	LPDIRECT3DTEXTURE9		m_ptexUsAlone;

	D3DMATERIAL8	m_mtrl;
	WAYPOINT3D		m_wpWaypoint[TUNNEL_WAYPOINTS+2];	// Add two endpoints to the waypoints (for cat-mull rom calculations)

	D3DXVECTOR3 m_vCamPos;				// Camera's position in tunnel
	D3DXVECTOR3 m_vOldCamPos;			// Previous camera position (used to calculate view direction)
	D3DXVECTOR3 m_vCamLookAt;			// The camera's look-at position in tunnel
	FLOAT		m_fLocalTime;			// This objects localtime (the same as the scene it is called from (scene02))
	FLOAT		m_fCamProgress;			// Camera's progress factor in current waypoint-segment
	INT			m_iCurrentWaypoint;		// Last waypoint passed
	INT			m_iNumWaypoints;		// Total number of waypoints (increases as camera moves through tunnel and it is generated)
};




//-----------------------------------------------------------------------------
// Name: class CTunnel2
// Desc: Handles the animation and rendering of tunnel2 
//-----------------------------------------------------------------------------

class CTunnel2
{
	friend class CBloodParticles;

public:
	HRESULT Animate					( FLOAT fLocalTime );
    CTunnel2						();
	HRESULT FlyCamera				( FLOAT fProgress, BOOL bWaypointChanged );
	HRESULT GenerateTunnel			( LPDIRECT3DVERTEXBUFFER9 pVB, LPDIRECT3DINDEXBUFFER9 pIB, FLOAT fTunnelRadius, BOOL bGenerateWaypoint );
	HRESULT InitDeviceObjects		();
	HRESULT InvalidateDeviceObjects	();
	HRESULT Overlay					( FLOAT fLocalTime );
    HRESULT Render					();

	LPD3DXMESH				m_pmeshTunnel;
	
protected:
	LPDIRECT3DTEXTURE9		m_ptexTunnel;
	LPDIRECT3DVERTEXBUFFER9	m_pvbTunnel;
	LPDIRECT3DINDEXBUFFER9	m_pibTunnel;

	D3DMATERIAL8	m_mtrl;
	WAYPOINT3D		m_wpWaypoint[TUNNEL2_WAYPOINTS+2];	// Add two endpoints to the waypoints (for cat-mull rom calculations)

	D3DXVECTOR3 m_vCamPos;				// Camera's position in tunnel
	D3DXVECTOR3 m_vOldCamPos;			// Previous camera position (used to calculate view direction)
	D3DXVECTOR3 m_vCamLookAt;			// The camera's look-at position in tunnel
	FLOAT		m_fLocalTime;			// This objects localtime (the same as the scene it is called from (scene02))
	FLOAT		m_fCamProgress;			// Camera's progress factor in current waypoint-segment
	INT			m_iCurrentWaypoint;		// Last waypoint passed
	INT			m_iNumWaypoints;		// Total number of waypoints (increases as camera moves through tunnel and it is generated)
};



//-----------------------------------------------------------------------------
// Name: class CScene08
// Desc: Handles the animation and rendering of scene08
//-----------------------------------------------------------------------------

class CScene08
{
public:
    CScene08	();
    HRESULT Animate					( FLOAT fLocalTime );
	HRESULT FlyCamera				( FLOAT fProgress, BOOL bWaypointChanged );
	HRESULT InitDeviceObjects		();
	HRESULT InvalidateDeviceObjects	();
    HRESULT Render					();
	
protected:
	CD3DMesh*				m_pmeshStar;
	LPD3DXMESH				m_pmeshSphere;
	LPDIRECT3DVERTEXBUFFER9	m_pvbStar;
	LPDIRECT3DINDEXBUFFER9	m_pibStar;
	LPDIRECT3DTEXTURE9		m_ptexStar;

	D3DXVECTOR3 m_vCamPos;				// Camera's position in tunnel
	D3DXVECTOR3 m_vCamLookAt;			// The camera's look-at position in tunnel
};



//-----------------------------------------------------------------------------
// Name: class CScene10
// Desc: Handles the animation and rendering of scene08
//-----------------------------------------------------------------------------

class CScene10
{
public:
    CScene10						();
    HRESULT Animate					( FLOAT fLocalTime );
	HRESULT FlyCamera				( FLOAT fProgress, BOOL bWaypointChanged );
	HRESULT InitDeviceObjects		();
	HRESULT InvalidateDeviceObjects	();
    HRESULT Render					();
	
protected:
	LPDIRECT3DTEXTURE9		m_ptexFinalSplash;
	PDIRECT3DTEXTURE8		m_ptexEndScreen;
};


	// Generic purpose resources
	CD3DFont*				g_pFont;
	DWORD					g_dwTextColor;
    LPDIRECT3DTEXTURE9		g_ptexBlender;		// Pointer to destination texture for blending textures to
	LPDIRECT3DCUBETEXTURE8	g_ptexEnvmap;		// General purpose cubic environment map
	LPDIRECT3DSURFACE8		g_psEnvmapStencil;	// A stencil buffer to use with cubic environment mapping
	LPDIRECT3DTEXTURE9		g_ptexScreenMask;	// Uses a texture with transparency, as to mask out part of the screen with the image
	LPDIRECT3DTEXTURE9		g_ptexScaleScreen;	// Low-res texture used to draw scene to before displaying on screen (to give a low-res effect)
	LPDIRECT3DTEXTURE9		g_ptexScreenBuffer;	// A screen buffer, to draw scenes to and add to backbuffer by a ShowTexture(). Transparent layers-effect.
	LPDIRECT3DSURFACE8		g_psOrigRenderTarget;	// The original render and stencil targets (used to restore after changing them)
	LPDIRECT3DSURFACE8		g_psOrigStencilTarget;
	LPDIRECT3DVERTEXBUFFER9 g_pvbFadeRect;      // Vertexbuffer for fade rect
	LPDIRECT3DVERTEXBUFFER9 g_pvbTexture;		// Pointer to vertexbuffer for ShowTexture()
	LPDIRECT3DTEXTURE9		g_ptexWhite;		// White texture
	LPDIRECT3DTEXTURE9		g_ptexBlack;		// Black texture
	
	D3DMATERIAL8			g_stdMtrl;			// Standard material, with white diffuse and ambient, and no specular
	D3DLIGHT8				g_dirLight;			// Directional light for general use
	D3DLIGHT8				g_pointLight;
	DWORD					g_dwBackgroundColor = D3DCOLOR_ARGB(0xff,0x00,0x00,0x00);

	// Music
	FSOUND_SAMPLE*			g_psampleMusic;


	// Camera
	D3DXMATRIX				g_matTrackBall;
	D3DXMATRIX				g_matIdentity;


	// Loadscreen
	LPDIRECT3DTEXTURE9		g_ptexLoadScreen;

	// Scene 01
	CFireFlies				g_flyGroup1(0);

	LPDIRECT3DTEXTURE9		g_ptexIAmFeeling;
	LPDIRECT3DTEXTURE9		g_ptexInAViolated;
	LPDIRECT3DTEXTURE9		g_ptexICanNoLonger;
	LPDIRECT3DTEXTURE9		g_ptexTheThings;
	LPDIRECT3DTEXTURE9		g_ptexIHaveForsaken;
	LPDIRECT3DTEXTURE9		g_ptexHeed;
	LPDIRECT3DTEXTURE9		g_ptexPresents;
	LPDIRECT3DTEXTURE9		g_ptexOurFirst;
	LPDIRECT3DTEXTURE9		g_ptexDemoEver;

	LPDIRECT3DTEXTURE9		g_ptexLogo;
	LPDIRECT3DTEXTURE9		g_ptexSplash1;		
	LPDIRECT3DTEXTURE9		g_ptexShadow;		// Shadow used on splashscreen
	LPDIRECT3DTEXTURE9		g_ptexWater;		// Pointer to water texture
	LPDIRECT3DCUBETEXTURE8	g_ptexWaterEnvmap;	// Environmapped water texture
	CD3DMesh*				g_pmeshWater;
	LPDIRECT3DVERTEXBUFFER9 g_pvbWater;			// Vertexbuffer for water surface
	LPDIRECT3DINDEXBUFFER9	g_pibWater;			// Indexbuffer for water surface



	// Scene 02
	CTunnel					g_tunnel;

	// Scene 03
	CTextGrid				g_textScene;

	// Scene 04
	CMetaBall				g_metaBall;

	// Scene 05
	CTunnel2				g_tunnel2;
	CBloodParticles			g_bParticles;
	LPDIRECT3DTEXTURE9		g_ptexSymbol1;
	LPDIRECT3DTEXTURE9		g_ptexSymbol2;
	LPDIRECT3DTEXTURE9		g_ptexSymbol3;
	LPDIRECT3DTEXTURE9		g_ptexSymbol4;


	// Scene 06
	LPDIRECT3DTEXTURE9		g_ptexSplash2;

	// Scene 07
	LPDIRECT3DTEXTURE9		g_ptexCredit1;
	LPDIRECT3DTEXTURE9		g_ptexCredit2;
	LPDIRECT3DTEXTURE9		g_ptexCredit3;
	LPDIRECT3DTEXTURE9		g_ptexHello;

	// Scene 08
	CScene08				g_scene08;

	// Scene 09
	INT						g_iNumGreets;
	LPDIRECT3DTEXTURE9		g_ptexGreets[14];
	LPDIRECT3DTEXTURE9		g_ptexDarkCodex;
	LPDIRECT3DTEXTURE9		g_ptexExceed;
	LPDIRECT3DTEXTURE9		g_ptexExcess;
	LPDIRECT3DTEXTURE9		g_ptexFairlight;
	LPDIRECT3DTEXTURE9		g_ptexFarbrausch;
	LPDIRECT3DTEXTURE9		g_ptexFutureCrew;
	LPDIRECT3DTEXTURE9		g_ptexHaujobb;
	LPDIRECT3DTEXTURE9		g_ptexInf;
	LPDIRECT3DTEXTURE9		g_ptexKvasigen;
	LPDIRECT3DTEXTURE9		g_ptexOrange;
	LPDIRECT3DTEXTURE9		g_ptexPopsyTeam;
	LPDIRECT3DTEXTURE9		g_ptexProgress;
	LPDIRECT3DTEXTURE9		g_ptexSunflower;
	LPDIRECT3DTEXTURE9		g_ptexYaphan;

	// Scene 10
	CScene10				g_scene10;

	// Non-resource members (these don't have to be allocated/deallocated)
	LPDIRECT3D8	g_pD3D;
	D3DSURFACE_DESC g_d3dsdBackBuffer;
	HINSTANCE	g_hInst;
	HWND		g_hWnd;
	HWND		g_hwndManipl;
	FLOAT		g_fAspect;
	CD3DCamera	g_cam;

	RECT		g_rcScreen;			// The rectdimension of the screen (backbuffer)
	INT			g_cWindowX;			// Width and height of screen (backbuffer)
	INT			g_cWindowY;
	INT			g_midWindowX;		// Half the width and height of screen (backbuffer)
	INT			g_midWindowY;
	FLOAT		g_fScaleX;	// A scalefactor when calculating values based on a 1024x768 resolution 
	FLOAT		g_fScaleY;	// (so that it shows up the same no matter what resolution we're using)
	FLOAT		g_fWindowX;
	FLOAT		g_fWindowY;
	FLOAT		g_fMidWindowX;		// Half the width and height of screen (backbuffer)
	FLOAT		g_fMidWindowY;
    
	FLOAT       g_fFadeStart;       // Global start/end values for fading, to determine if a fade is in progress or not.
    FLOAT       g_fFadeEnd;
	FLOAT		g_bFading;			            // BOOL for wheter fade is in use or not
	D3DCOLOR	g_dwFadeColor;		            // The D3DCOLOR value that the fadehandler fills the backbuffer with
	D3DCOLOR	g_dwColWhite;	// White d3dcolor, with full alpha

	INT			g_sliderVal[4];
	BOOL		g_bTexmodePlain;

	INT			g_waterPlaneWidth;
	INT			g_waterPlaneHeight;

	FLOAT		g_fTBoost;	// time booster (for jumping to a time)
	FLOAT		g_fDTime;
	FLOAT		g_fDemoStartTime;
	FLOAT		g_fPointSize = VERTEX_POINTSIZE;

	INT_PTR CALLBACK ManipulatorProc( HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam );

// Scene effectfunctions
	HRESULT FireFlies           ( FLOAT fLocalTime );
	HRESULT SplashScreen1		( FLOAT fLocalTime );
	HRESULT SplashScreen2		( FLOAT fLocalTime );

// Tool-functions
	HRESULT BlendTexture		( LPDIRECT3DTEXTURE9 pSource1, LPDIRECT3DTEXTURE9 pSource2, LPDIRECT3DTEXTURE9 pDest, FRECT frcSource1, FRECT frcSource2, FLOAT fAlpha=255.0f, BOOL bReplace=FALSE );
	HRESULT CenterMesh			( CD3DMesh* pMesh, LPDIRECT3DVERTEXBUFFER9 pVB );
	HRESULT CenterMeshFVF		( LPD3DXMESH pMesh, DWORD dwFVF );
	HRESULT ClearTexture		( LPDIRECT3DTEXTURE9 pTexture, D3DCOLOR dwColor );
	HRESULT CloneVB				( LPDIRECT3DVERTEXBUFFER9 pSource, LPDIRECT3DVERTEXBUFFER9 pDest );
	HRESULT DisplayErrorMsg2	( HRESULT hr, DWORD dwType );
	HRESULT DisturbWater		( LPDIRECT3DVERTEXBUFFER9 pVB, LPDIRECT3DINDEXBUFFER9 pIB, DWORD dwFVF, WAVEDATA* wData, FLOAT fCurrentTime );
	HRESULT DrawLine			( FLOAT fX1, FLOAT fY1, FLOAT fX2, FLOAT fY2, D3DCOLOR dwCol=0xffffffff, FLOAT fAlpha=255.0f );
	HRESULT DrawRect			( FLOAT fX1, FLOAT fY1, FLOAT fX2, FLOAT fY2, D3DCOLOR dwCol=0xffffffff, FLOAT fAlpha=255.0f );
	HRESULT Fade				( D3DCOLOR dwColorStart, D3DCOLOR dwColorEnd, FLOAT fTStart, FLOAT fTCurrent, FLOAT fTEnd, FLOAT fTHold=0.0f );
	HRESULT FadeRect			( D3DCOLOR dwColor, RECT rcArea, BOOL bUpdateRect=FALSE, BOOL bOverrideFade=FALSE );
	HRESULT FillTexture			( LPDIRECT3DTEXTURE9 pTex1, LPDIRECT3DTEXTURE9 pTex2 );
	FLOAT	LinearChange		( FLOAT fStart, FLOAT fEnd, FLOAT fTimeStart, FLOAT fCurrent, FLOAT fTimeEnd );
	D3DXVECTOR3 LinearChangeVector( D3DXVECTOR3 vStart, D3DXVECTOR3 vEnd, FLOAT fTimeStart, FLOAT fLocalTime, FLOAT fTimeEnd );
	VOID	nop					() { return; }
	HRESULT PlayMusic			();
inline 	FLOAT RandRange			( FLOAT low, FLOAT high);
	HRESULT RestoreRenderTarget	();
	HRESULT	SetDetailedVBRect	( LPDIRECT3DVERTEXBUFFER9 pVB, FLOAT fOffsetX, FLOAT fOffsetY, FLOAT fOffsetX2, FLOAT fOffsetY2, INT numQuadsX, INT numQuadsY, FLOAT fAlpha, FLOAT fTiled );
	HRESULT SetRenderTargetToTexture ( LPDIRECT3DTEXTURE9 pTex );
	HRESULT SetRenderTargetToCubemap ( INT iLevel, LPDIRECT3DCUBETEXTURE8 ptexCube, LPDIRECT3DSURFACE8 psStencil );
	HRESULT SetVB3DPlaneRect	( LPDIRECT3DVERTEXBUFFER9 pVB, LPDIRECT3DINDEXBUFFER9 pIB, DWORD dwFVF, D3DXVECTOR3 vTopLeft, D3DXVECTOR3 vBottomRight, INT numVertsX, INT numVertsY, FLOAT fAlpha );
	HRESULT SetVBRect			( LPDIRECT3DVERTEXBUFFER9 pVB, RECT rcRect, D3DCOLOR dwColor=NULL );
	HRESULT ShowOrigin			();
	HRESULT ShowBlurTexture		( LPDIRECT3DTEXTURE9 pTexture, FLOAT fOffsetX, FLOAT fOffsetY, FLOAT fWidth, FLOAT fHeight, FLOAT fBlurIntensity, FLOAT fBlurSize, FLOAT fAlpha=255.0f, FLOAT fTileFactor=1.0f, BOOL bForeground=TRUE );
	HRESULT ShowTexture			( LPDIRECT3DTEXTURE9 pTexture, FLOAT fOffsetX, FLOAT fOffsetY, FLOAT fWidth, FLOAT fHeight, FLOAT fAlpha=255.0f, FLOAT fTileFactor=1.0f, BOOL bForeground=TRUE );
	HRESULT ShowTextureTile		( LPDIRECT3DTEXTURE9 pTexture, FLOAT fOffsetX, FLOAT fOffsetY, FLOAT fWidth, FLOAT fHeight, FLOAT fAlpha=255.0f, FLOAT fTileFactorX=1.0f, FLOAT fTileFactorY=1.0f, BOOL bForeground=TRUE );
	HRESULT ShowTextureEx		( LPDIRECT3DTEXTURE9 pTexture, FRECT frcSrc, D3DCOLOR vertCol[4], FLOAT fOffsetX, FLOAT fOffsetY, FLOAT fWidth, FLOAT fHeight, FLOAT fAlpha=255.0f );
	HRESULT ShowTextureExTile	( LPDIRECT3DTEXTURE9 pTexture, D3DCOLOR vertCol[4], FLOAT fOffsetX, FLOAT fOffsetY, FLOAT fWidth, FLOAT fHeight, FLOAT fTileTU, FLOAT fTileTV, FLOAT fOffsetTU=0.0f, FLOAT fOffsetTV=0.0f, FLOAT fAlpha=255.0f );
	HRESULT ShowTextureVB		( LPDIRECT3DTEXTURE9 pTexture, LPDIRECT3DVERTEXBUFFER9 pVB, INT numQuadsX, INT numQuadsY, FLOAT fAlpha, FLOAT fTileFactor );
	HRESULT ShowTextureVBProj	( LPDIRECT3DTEXTURE9 pTexture, LPDIRECT3DVERTEXBUFFER9 pVB, LPDIRECT3DINDEXBUFFER9 pIB, D3DXVECTOR3 vTopLeft, D3DXVECTOR3 vBottomRight, INT numVertsX, INT numVertsY, FLOAT fAlpha );
	HRESULT ShowWaypoints		( WAYPOINT3D* pWaypoint, INT iNumWaypoints, FLOAT fAlpha=255.0f );
	HRESULT SizeMesh			( CD3DMesh* pMesh, LPDIRECT3DVERTEXBUFFER9 pVB, FLOAT fNewRadius );
	HRESULT SizeMeshFVF			( LPD3DXMESH pMesh, DWORD dwFVF, FLOAT fNewRadius );


	// External functions (due to compiletime)
	extern INT			Polygonise	 ( GRIDCELL grid, FLOAT fIsoLevel, TRIANGLE* pTriangles );
	extern D3DXVECTOR3	VertexInterp ( FLOAT fIsoLevel, D3DXVECTOR3 vP1, D3DXVECTOR3 vP2, FLOAT fValP1, FLOAT fValP2 );


	// Application skeleton
	HRESULT InitD3D( HWND hWnd );
    HRESULT InitDeviceObjects();
    HRESULT Render();
    HRESULT InvalidateDeviceObjects();
    HRESULT FinalCleanup();

	LRESULT WINAPI MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );


	// Progive scene functions, listed in order of execution
	HRESULT	LoadScreen( FLOAT fTime );
	HRESULT	AScene01( FLOAT fTime );
	HRESULT AScene02( FLOAT fTime );
	HRESULT AScene03( FLOAT fTime );
	HRESULT AScene04( FLOAT fTime );
	HRESULT AScene05( FLOAT fTime );
	HRESULT AScene06( FLOAT fTime );
	HRESULT AScene07( FLOAT fTime );
	HRESULT AScene08( FLOAT fTime );
	HRESULT AScene09( FLOAT fTime );
	HRESULT AScene10( FLOAT fTime );

	HRESULT InitScene01();
	
	HRESULT InitScene09();
	HRESULT InvalidateScene09();
	HRESULT Scene09Overlay( FLOAT fLocalTime );
	HRESULT PlayMusic();

VOID ComputeScreenQuad( const D3DXMATRIX& inverseview, const D3DXMATRIX& view, const D3DXMATRIX& proj,
						BYTE* verts, BYTE* uvs, DWORD stride, const D3DXVECTOR3& p0, const D3DXVECTOR3& p1, FLOAT size, BOOL constantsize );
FLOAT ComputeConstantScale(const D3DXVECTOR3& pos, const D3DXMATRIX& view, const D3DXMATRIX& proj);
inline VOID ComputePoint( D3DXVECTOR3& dest, FLOAT x, FLOAT y, const D3DXMATRIX& rot, const D3DXVECTOR3& trans );
inline VOID TransformPoint3x3(D3DXVECTOR3& dest, const D3DXVECTOR3& source, const D3DXMATRIX& rot);
