#define DEF_TIMEJUMP TIME_SCENE08	// Timejump should be TIME_SCENExx when ONLY_PLAY_SCENE has xx value
#define ONLY_PLAY_SCENE 8

#define PLAY_LOADSCREEN
#define PLAY_SCENE01	// Intro with waterscene and brainroom splashscroller
#define PLAY_SCENE02	// Energy tunnel
#define PLAY_SCENE03	// Textworld
#define PLAY_SCENE04	// Metaball
#define PLAY_SCENE05	// Mean tunnel
#define PLAY_SCENE06	// Nature splashscroller
#define PLAY_SCENE07	// Credit screen
#define PLAY_SCENE08	// 3D scene
#define PLAY_SCENE09	// 3D scene with greets, same style
#define PLAY_SCENE10	// Final splashscreen, with fadeout to end-text

//#define PLAYMUSIC
#define FULLSCREEN
//#define INFOTEXT
#define SLOWMO_FACTOR	1.0f

#define WINDOW_WIDTH	1024
#define WINDOW_HEIGHT	768
#define MOUSECONTROL	FALSE	// Flag that specifies whether mouse controls camera or not
#define GLOBAL_FILLMODE	D3DFILL_SOLID
#define TEXT_COLOR		D3DCOLOR_ARGB(255,127,127,127)

#define GAMMA_RED			255.0f
#define GAMMA_BLUE			255.0f
#define GAMMA_GREEN			255.0f


//-----------------------------------------------------------------------------
// Title: Forsaken v0.926 Hi-Quality PC-Demo
// Author: Zigrath / Heed
// Mail: zigrath@online.no
//
// Desc: My first demo ever, to be contributed at The Gathering 2003.
//		 Kaktusen provides music, gfx and ideas.
//
// Linked libraries: 
//	* d3dx8.lib d3dxof.lib d3d8.lib dxguid.lib winmm.lib fmodvc.lib comctl32.lib 
//
// Bugs: 
//	* Heap block modified past requested size of 46020. Scene04/05? Might still exist.
//	* Set3DPlaneVBRect() is NOT foolproof with the different vertex formats. Only one flag after XYZ and NORMAL can work 100%.
//       
//
// Compatibility checklist:
//	* timebased random generating (i.e. feed the chicken vibration)
//	* memory allocations (textures above 1024x1024?)
//	* test product on a slow computer and a really fast one
//
// Todos:
//	* ShowBlurTexture() or alternative blurring
//	* sort bloodparticles in scene05
//  * metaballs:  bruk en sum av vektorenE fra ballenes sentrum ganger verdien fra metafunksjonene dems
//	* Fog on water in scene01?
//	* Scene04. Metaball and marching cubes. Improve melting.
//	* DX SDK has some nice textures. Might find a replacement for flies.
//	* Point sprites?
//	* World-transformation correction for fireflies, we want sprites to look 2D
//
// Effect ideas:
//	* Scroll-in transparency and blur effect on introtext
//	* Animated inverse-color rectangle from 4 cross-screen lines
//	* Rotate the three manga-heads transparently on top of eachother
//
//
//
// Memos to self:
// 28.11.02: Spank me. The intro is finally getting somewhere..
// 06.12.02: Bugs aren't all that bad, it is fixing them that really sucks.
// 20.02.03: Intro is nearly done, and I'm sort of pleased with it - but not overjoyous, mark you.
// 20.02.03: So much to do, so little time. So hungry.
// 09.03.03: Intro has been improved a lot, the flies in particular. I'm currently working on the
//				tunnel effect, and I'm quite pleased with it. I even got most of the plasma effect
//				in place already.
// 10.03.03: Skipping sleep is good for demos, but that's just about it. 
//			 I and kaktus have produced a number of concrete ideas that's going to be part of the demo.

// 11.03.03: The soundtrack is finished, thanks to a great job by Kaktus, and it is awesome!
//			 He has also set up a pretty concrete plan for where and how to apply the different
//			 scenes and effects we have discussed. This plan is based on the music, and should
//			 give a very thorough experience if we succeed to follow it.
//			 Splashscreen 1 is nearly done, and I found a better looking way of creating the
//			 plasma effect for the tunnel. This demo is gonna be great! :D

// 28.03.03: Lots have been done. The water effect in the intro has been improved a heck of a lot,
//			 and it's now looking sweet!
//			 I have also finished most of the textscene in musicpause1, and next up will be the
//			 metaball. I'm really excited about that one.
//			 The rest of the scenes are more or less finished on plan level, and they should
//			 be far faster to create than the scenes so far.
//			 The deadline is two and a half week from now, and we have finished about 2 minutes out of 5.
//			 But I think we'll have enough time to come up with a pretty decent demo.

// 30.03.03: I finished off the blue tunnel scene. It's not perfect, but it'll do. We're short on time already,
//			 and I have that pesky metaball to figure out shortly. The big scenes that remain are.. still many.

// 12.03.03: Time is running out and I'm so busy I can't even take a piss. And when I occasionally do,
//			 it smells like honney corn.
//			 A lot has happened since last post however. I have come far with the metaballs (they are still too slow and
//			 don't look too good because of resolution on grid). The mean tunnel at scene5 is nearly done. The particles
//			 are basically finished, it's just some camera stuff to set up and flash-effects. Shouldn't take long.
//			 The nature splashscroller and credits are also basically in place, just missing some textures and finish.
//
//			 Finally, I have made a temporary 3d-object for use in scene8 and threw in some rotation. I'm thinking of
//			 adding more objects and some particles, and that should pretty much do it.
//			 I do have accomplished a lot the past 12 days, and I'm finally seeing an end to this demo. About 30 seconds
//			 remain that I haven't put any work to yet, and they should only take a day or two to implement.
//			 Who knows, we might actually finish this demo in time!

// 14.03.03: Two days to dust off. These holidays have been very useful, and I have been able
//			 to put down quite a share of work. The major accomplishment is a pretty much done
//			 scene8 and I am thinking of using much of it in scene9 as well. And that narrows
//			 it down to a 15 second lastscene that I intend to put a lot of work into, as to
//			 give a good last impression of the demo.
//			 The camera movement in scene2 and 5 has been improved a lot, scene5 in particular.
//			 The particles in scene5 are also moving a bit random now to look more alive,
//			 and it works pretty decent. I'm still thinking of experimenting with the textures a
//			 bit though, but there's plenty of time for such at the party.
//			 I also added introtext for the poem in the soundtrack. The textures are rather
//			 temporary but most of the work there is done. And I'm thinking of adding some blur and
//			 "scroll-in transparency" effects on the textlines.

// 19.03.03: It is Saturday morning, and less than 4 hours to deadline. I think we have managed to scrap together
//			 a rather decent demo, at least for a first attempt. We had to cut the soundtrack about 20 seconds at 
//			 the end, since we couldn't get enough time to fill it all. Kaktus did a good job, and the soundtrack
//			 now fits the demo pretty well (and vice versa).
//			 We have put a lot of work in refining the textures and adding quite a deal of fill-effects.
//			 Of course I wish I'd have more time, but then again I'll be happy to wrap up this product.
//			 I've spent an enormous time and effort making it.. and as long as it shows up ok on the bigscreen
//			 I will be quite satisfied with this demo.
//			 My fingers are crossed.
//			 There is a major bug in the demo however. It seems ATI cards mess up the fade-sequences, so it is
//			 currently not playable on those. I'll try and fix it before deadline.
//			 Except for that, all scenes are in place more or less. The metaballs look like crap, but I just don't
//			 have time to fix it.
//			 I'm quite excited how this compo will turn out.
//			 
// 
// Disclaimer: Be aware of the bugs, they bite.
//-----------------------------------------------------------------------------



// Global timekeys
#define TIME_SCENE00	0.0f						// Start of demo, to make a pause between start and scene01
#define TIME_SCENE01	5.0f						// Water and flies
#define TIME_SPLASH01	65.0f						// Logo and brain-room splashscroller. Part of scene01, so it uses that localtime
#define TIME_SCENE02	(TIME_SCENE01 + 85.3f)		// Energy tunnel
#define TIME_SCENE03	(TIME_SCENE01 + 106.6f)		// Textworld
#define TIME_SCENE04	(TIME_SCENE01 + 127.95f)	// Metaball
#define TIME_SCENE05	(TIME_SCENE01 + 149.2f)		// Mean tunnel
#define TIME_SCENE06	(TIME_SCENE01 + 192.0f)		// Nature splashscroller
#define TIME_SCENE07	(TIME_SCENE01 + 213.5f)		// Credit screen
#define TIME_SCENE08	(TIME_SCENE01 + 234.7f)		// 3D scene
#define TIME_SCENE09	(TIME_SCENE01 + 255.8f)		// 3D scene with greets, same style
#define TIME_SCENE10	(TIME_SCENE01 + 277.4f)		// Final splashscreen, with fadeout to end-text
#define TIME_SCENE11	(TIME_SCENE01 + 292.0f)

// Scene01
#define WATER_FVF					D3DFVF_NLVERTEX
#define WATER_VERTEX				NLVERTEX
#define WATER_VX					50	// Number of vertices
#define WATER_VY					50
#define WATER_DELAY					10.0f
#define WATER_VERTS					(WATER_VX*WATER_VY)
#define WATER_INDICES				((WATER_VX-1)*(WATER_VY-1)*6)	// Number of quads times 6
#define WATER_FACES					((WATER_VX-1)*(WATER_VY-1)*2)	// Twice the number of quads
#define MAX_FIREFLIES				100
#define MAX_FIREFLY_WAYPOINTS		100
#define FIREFLY_GLOWLAYERS			4
#define FIREFLY_MAX_GLOWDIST		0.5f
#define FIREFLY_DEPTH_VISIBLE		70.0f	// At which depth fireflies go visible (distance from camera)	
#define FIREFLY_DEPTH_INVISIBLE		40.0f	// At which depth fireflies go invisible (distance from camera)

// Scene02
#define TUNNEL_LENGTH				150.0f
#define TUNNEL_RADIUS				1.0f
#define TUNNEL_WILD_RADIUS			10.0f
#define TUNNEL_SPEED				1.0f
#define TUNNEL_VERTEX				NLTVERTEX
#define TUNNEL_FVF					D3DFVF_NLTVERTEX
#define TUNNEL_WAYPOINTS			4		// 4 waypoints for the visible part of the tunnel, and 2 endpoints for cat-mull rom calculations
#define TUNNEL_SEGS_PER_WAYPOINT	10
#define TUNNEL_SEGMENT_VERTS		36
#define TUNNEL_SEGMENTS				(TUNNEL_SEGS_PER_WAYPOINT * TUNNEL_WAYPOINTS)
#define TUNNEL_SEGMENT_QUADS		(TUNNEL_SEGMENT_VERTS)
#define TUNNEL_SEGMENT_INDICES		(TUNNEL_SEGMENT_QUADS * 6)
#define TUNNEL_TILE_PER_SEG			1.0f	
#define TUNNEL_TILE_PER_QUAD		1.0f
#define TUNNEL_VERTS				(2+(TUNNEL_SEGMENTS * TUNNEL_SEGMENT_VERTS * 2)) // Every vertex in a segment has a clone (even counting the first and last segment), for better texturecoord control (each segment is the last and first in two connected quads)
#define TUNNEL_QUADS				((TUNNEL_SEGMENTS-1) * TUNNEL_SEGMENT_QUADS)
#define TUNNEL_INDICES				(TUNNEL_QUADS * 6)
#define TUNNEL_FACES				(TUNNEL_QUADS * 2)

// Scene03
#define GRID_VERTEX		NLTVERTEX
#define GRID_FVF		D3DFVF_NLTVERTEX
#define GRID_LINES_X	20
#define GRID_LINES_Y	20
#define GRID_LINES_Z	20
#define GRID_SEG_SIZE	0.5f
#define GRID_TILES		20
#define GRID_SEG_LENGTH	(GRID_WIDTH / GRID_TILES)
#define GRID_WIDTH		100.0f
#define GRID_HEIGHT		100.0f
#define GRID_DEPTH		100.0f
#define GRID_SPACE_X	(GRID_WIDTH  / (FLOAT)(GRID_LINES_X-1))
#define GRID_SPACE_Y	(GRID_HEIGHT / (FLOAT)(GRID_LINES_Y-1))
#define GRID_SPACE_Z	(GRID_DEPTH  / (FLOAT)(GRID_LINES_Z-1))
#define GRID_LINES		((GRID_LINES_X*GRID_LINES_Y) + (GRID_LINES_Y*GRID_LINES_Z) + (GRID_LINES_X*GRID_LINES_Z))
#define GRID_POINTS		(GRID_LINES_X * GRID_LINES_Y * GRID_LINES_Z)
#define GRID_VERTS		(GRID_LINES * 4)	// We'll create a quad for each line
#define GRID_QUADS		(GRID_LINES)	// 1 quad per line

#define GRID_MOVETIME	20.0f
#define GRID_INDICES		(GRID_POINTS * 3 * 6)	// 3 quads per point (x,y,z directions), 6 indices per quad


// Scene04
#define METAB_FVF			D3DFVF_NVERTEX
#define METAB_VERTEX		NVERTEX
#define METAB_VERTS			20000//(METAB_GRID_RES*METAB_GRID_RES*METAB_GRID_RES * (5*3))	// Max 5 triangles (3 vertices each)
#define METAB_FACES			(METAB_VERTS / 3)

#define METAB_GRID_SIZE		70.0f
#define METAB_GRID_RES		10	// Number of cells in width, height and depth of grid
#define METAB_CELL_SIZE		(METAB_GRID_SIZE / (METAB_GRID_RES-1))	// This is the width, height and depth of all cells (dimensions are "homogeneous")

#define METAB_BALLS			4
#define METAB_RADIUS		13.0f
#define METAB_MOVE_RADIUS	15.0f
#define METAB_SPEED			3.0f


// Scene05
#define TUNNEL2_LENGTH				150.0f
#define TUNNEL2_RADIUS				1.0f
#define TUNNEL2_SHAKERADIUS			0.002f
#define TUNNEL2_WILD_RADIUS			30.0f
#define TUNNEL2_WILDCAM_RADIUS		2.0f
#define TUNNEL2_WILDCAM_TIME		0.5f		
#define TUNNEL2_BUMPSTRENGTH		1.3f
#define TUNNEL2_WPBUMPS				2
#define TUNNEL2_SEGBUMPS			8
#define TUNNEL2_SPEED				2.0f

#define TUNNEL2_VERTEX				NLVERTEX
#define TUNNEL2_FVF					D3DFVF_NLVERTEX

#define TUNNEL2_WAYPOINTS			4	// 4 waypoints for the visible part of the tunnel, and 2 endpoints (added manually) for cat-mull rom calculations
#define TUNNEL2_SEGS_PER_WAYPOINT	20
#define TUNNEL2_SEGMENT_VERTS		64

#define BLOOD_PARTICLES				70
#define BPARTICLES_WAYPOINTS		(TUNNEL2_WAYPOINTS+2)
#define BPARTICLES_SIZE				1.0f
#define BPARTICLES_SPEED			(TUNNEL2_SPEED * 0.3f)
#define BPARTICLES_RADIUS			7.0f

#define TUNNEL2_SEGMENTS			(TUNNEL2_SEGS_PER_WAYPOINT * TUNNEL2_WAYPOINTS)
#define TUNNEL2_SEGMENT_QUADS		(TUNNEL2_SEGMENT_VERTS)
#define TUNNEL2_SEGMENT_INDICES		(TUNNEL2_SEGMENT_QUADS * 6)
#define TUNNEL2_TILE_PER_SEG		1.0f	
#define TUNNEL2_TILE_PER_QUAD		1.0f
#define TUNNEL2_VERTS				(2+(TUNNEL2_SEGMENTS * TUNNEL2_SEGMENT_VERTS * 2)) // Every vertex in a segment has a clone (even counting the first and last segment), for better texturecoord control (each segment is the last and first in two connected quads)
#define TUNNEL2_QUADS				(TUNNEL2_SEGMENTS-1) * TUNNEL2_SEGMENT_QUADS
#define TUNNEL2_INDICES				(TUNNEL2_QUADS * 6)
#define TUNNEL2_FACES				(TUNNEL2_QUADS * 2)

// Scene 08
#define STAR_BALLS					750
#define STAR_BALLSPEED				1.5f			
#define STAR_BALLSPEED2				0.5f			

// Scene 10
#define SCENE10_FVF					D3DFVF_LVERTEX
#define SCENE10_VERTEX				LVERTEX

// Generic purpose
#define CUBEMAP_RES			512	// Resolution of cubemap

#define	QUADS_X				4	// SetDetailedVBRect()
#define QUADS_Y				4
#define ALPHA_FULL			255.0f
#define ALPHA_NONE			0.0f

#define VERTEX_POINTSIZE 10.0f

#include "main.h"


TCHAR g_szInfoLine1[256] = "";
TCHAR g_szInfoLine2[256] = "";

TCHAR szDemoTime[120];
INT	iOnlyPlayScene = ONLY_PLAY_SCENE;	// Which scene to run unlimited. 0 == disabled

LPDIRECT3DDEVICE8	g_pd3dDevice;

INT	GridCompare( const VOID* arg1, const VOID* arg2 );


//-----------------------------------------------------------------------------
// Name: BlendTexture()
// Desc: Blends a texture (source1) with another (source2), storing it in a third texture (dest).
// Note: The RECTs are different treated. Right and Bottom are respectively Width and Height, and
//		 Left and Top are the offsets.
//-----------------------------------------------------------------------------

HRESULT BlendTexture( LPDIRECT3DTEXTURE8 pSource1, LPDIRECT3DTEXTURE8 pSource2, LPDIRECT3DTEXTURE8 pDest, FRECT frcSource1, FRECT frcSource2, FLOAT fAlpha, BOOL bReplace )
{
	HRESULT hr = S_OK;

	SetRenderTargetToTexture( pDest );
	
	if ( bReplace )
	{
		g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
		g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_SRCALPHA );
	}
	else
	{
		g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
		g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	}

	if ( pSource2 )
	{
		ShowTexture( pSource2, frcSource2.left, frcSource2.top, frcSource2.right, frcSource2.bottom, ALPHA_FULL, 1.0f );
	}
	
	ShowTexture( pSource1, frcSource1.left, frcSource1.top, frcSource1.right, frcSource1.bottom, fAlpha, 1.0f );

	RestoreRenderTarget();

	return hr;
}




//-----------------------------------------------------------------------------
// Name: Animate()
// Desc: Animates the particles
//-----------------------------------------------------------------------------

HRESULT CBloodParticles::Animate( FLOAT fLocalTime, FLOAT fCameraProgress )
{
	HRESULT	hr = S_OK;
	INT	i;

	if ( m_iNumParticles <= 0 )
		return S_OK;


	
	NLTVERTEX vTable[] = 
	{
		{ -BPARTICLES_SIZE, BPARTICLES_SIZE, 0.0f, 0.0f, 0.0f, 0.0f, 0xffffffff, 0.0f, 0.0f },	// x,y,z,nx,ny,nz,col,tu,tv
		{  BPARTICLES_SIZE, BPARTICLES_SIZE, 0.0f, 0.0f, 0.0f, 0.0f, 0xffffffff, 1.0f, 0.0f },
		{  BPARTICLES_SIZE,-BPARTICLES_SIZE, 0.0f, 0.0f, 0.0f, 0.0f, 0xffffffff, 1.0f, 1.0f },
		{ -BPARTICLES_SIZE,-BPARTICLES_SIZE, 0.0f, 0.0f, 0.0f, 0.0f, 0xffffffff, 0.0f, 1.0f },
	};



	//--------------------------------------------------------------------
	// PER-PARTICLE CALCULATION
	//--------------------------------------------------------------------


	NLTVERTEX* pVertices;
	if ( FAILED(hr = m_pVB->Lock(0, NULL, (BYTE**)&pVertices, NULL)) )
		return hr;		

	for ( i=0; i<m_iNumParticles; i++ )
	{
		FLOAT fTimeDiff = fLocalTime - m_particle[i].fLastTime;

		m_particle[i].fAdvance = m_particle[i].fStartOffset - (fTimeDiff * BPARTICLES_SPEED);


/*		if ( m_particle[i].fAdvance >= 1.0f )
		{
			m_particle[i].fAdvance -= 1.0f;
			m_particle[i].fStartOffset = 0.0f;

			m_particle[i].vPrevOffset = m_particle[i].vNextOffset;
			m_particle[i].vNextOffset = D3DXVECTOR3( RandRange(-BPARTICLES_RADIUS, BPARTICLES_RADIUS), 
													 RandRange(-BPARTICLES_RADIUS, BPARTICLES_RADIUS), 
													 0.0f );

			fTimeDiff -= 1.0f;
			m_particle[i].fLastTime = fLocalTime;
		}*/
		if ( m_particle[i].fAdvance <= 0.0f )
		{
			m_particle[i].fAdvance += 1.0f;
			m_particle[i].fStartOffset = 1.0f;

			m_particle[i].vPrevOffset = m_particle[i].vNextOffset;
			m_particle[i].vNextOffset = D3DXVECTOR3( RandRange(-BPARTICLES_RADIUS, BPARTICLES_RADIUS), 
													 RandRange(-BPARTICLES_RADIUS, BPARTICLES_RADIUS), 
													 0.0f );

			fTimeDiff = 0.0f;
			m_particle[i].fLastTime = fLocalTime;
		}

		m_particle[i].fSegProg = fCameraProgress + m_particle[i].fAdvance;


		// New spline segment, generate new particle data
		if ( m_particle[i].fSegProg >= 1.0f )	
		{
			m_particle[i].fSegProg -= 1.0f;		// include excess time
			m_particle[i].iCurWaypoint = 1;
		}
		else
			m_particle[i].iCurWaypoint = 0;

		memcpy( m_wpWaypoint, &g_tunnel2.m_wpWaypoint[m_particle[i].iCurWaypoint], sizeof(m_wpWaypoint) );


		D3DXVECTOR3 vCtrlD3DXVECTOR31 = m_wpWaypoint[1].v + LinearChangeVector( m_particle[i].vPrevOffset, m_particle[i].vNextOffset, m_particle[i].fLastTime, fLocalTime, m_particle[i].fLastTime+3.0f );
		D3DXVECTOR3 vCtrlD3DXVECTOR32 = m_wpWaypoint[2].v + LinearChangeVector( m_particle[i].vPrevOffset, m_particle[i].vNextOffset, m_particle[i].fLastTime, fLocalTime, m_particle[i].fLastTime+3.0f );
		D3DXVECTOR3 vCtrlD3DXVECTOR33 = m_wpWaypoint[3].v + LinearChangeVector( m_particle[i].vPrevOffset, m_particle[i].vNextOffset, m_particle[i].fLastTime, fLocalTime, m_particle[i].fLastTime+3.0f );
		D3DXVECTOR3 vCtrlD3DXVECTOR34 = m_wpWaypoint[4].v + LinearChangeVector( m_particle[i].vPrevOffset, m_particle[i].vNextOffset, m_particle[i].fLastTime, fLocalTime, m_particle[i].fLastTime+3.0f );

		D3DXVec3CatmullRom( &m_particle[i].v,	// Resulting interpolated point in curve
			&vCtrlD3DXVECTOR31,						// Controlpoint for startpoint
			&vCtrlD3DXVECTOR32,						// Startpoint in curve
			&vCtrlD3DXVECTOR33,						// Endpoint in curve
			&vCtrlD3DXVECTOR34,						// Controlpoint for endpoint
			m_particle[i].fSegProg );

		memcpy( pVertices+(i*4), vTable, sizeof(vTable) );
	}

	m_pVB->Unlock();
	
	return hr;
}




//-----------------------------------------------------------------------------
// Name: CBloodParticles()
// Desc: Constructor
//-----------------------------------------------------------------------------

CBloodParticles::CBloodParticles()
{
    m_ptexParticle	= NULL;
	m_pVB			= NULL;

	m_iNumParticles = BLOOD_PARTICLES;
	m_iNumWaypoints = BPARTICLES_WAYPOINTS;
	m_iCurrentWaypoint = 0;


	ZeroMemory( m_wpWaypoint, sizeof(m_wpWaypoint ) );
	ZeroMemory( m_particle, sizeof(m_particle) );


	for ( INT i=0; i<m_iNumParticles; i++ )
	{
		m_particle[i].v.x = 0.0f;
		m_particle[i].v.y = 0.0f;
		m_particle[i].v.z = 0.0f;

		m_particle[i].fSize			= BPARTICLES_SIZE;
		m_particle[i].fAdvance		= 0.0f;
		m_particle[i].fStartOffset	= RandRange( 0.0f, 1.0f );//(FLOAT)i / (m_iNumParticles-1) - RandRange( 0.0f, 1.0f / (m_iNumParticles-1) );
		m_particle[i].fSegProg		= 0.0f;	// Prog factor of curve, distribute particles over progressfactor
		m_particle[i].iCurWaypoint	= 0;	// Waypoint0 is not a valid waypoint, as it is only used for catmull-rom splines
	}
}



//-----------------------------------------------------------------------------
// Name: InitDeviceObjects()
// Desc: Initializes and allocates devicedepenent resources for the class.
//-----------------------------------------------------------------------------

HRESULT CBloodParticles::InitDeviceObjects()
{
	HRESULT hr = S_OK;

#ifdef PLAY_SCENE05
	
	if ( FAILED(hr = g_pd3dDevice->CreateVertexBuffer(BLOOD_PARTICLES*8*sizeof(NLTVERTEX), NULL, D3DFVF_NLTVERTEX, D3DPOOL_MANAGED, &m_pVB)) )
		return hr;

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene05\\firefly_r.png"), &m_ptexParticle)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}        		


	// Initialize wild-waypoints for particles, copy waypoints from tunnel2 as base
	memcpy( m_wpWaypoint, g_tunnel2.m_wpWaypoint, sizeof(g_tunnel2.m_wpWaypoint) );

	for ( INT i=0; i<m_iNumParticles; i++ )
	{
		m_particle[i].vPrevOffset = D3DXVECTOR3( RandRange(-BPARTICLES_RADIUS, BPARTICLES_RADIUS), 
												 RandRange(-BPARTICLES_RADIUS, BPARTICLES_RADIUS), 
												 0.0f );
		m_particle[i].vNextOffset = D3DXVECTOR3( RandRange(-BPARTICLES_RADIUS, BPARTICLES_RADIUS), 
												 RandRange(-BPARTICLES_RADIUS, BPARTICLES_RADIUS), 
												 0.0f );
	}

#endif	// PLAY_SCENE05

	return S_OK;
}



//-----------------------------------------------------------------------------
// Name: InvalidateDeviceObjects()
// Desc: Cleans up any allocated resources used by the class.
//-----------------------------------------------------------------------------

HRESULT CBloodParticles::InvalidateDeviceObjects()
{
	HRESULT hr = S_OK;

	SAFE_RELEASE( m_pVB );
	SAFE_RELEASE( m_ptexParticle );

	return S_OK;
}




//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Renders the group of fireflies
//-----------------------------------------------------------------------------

HRESULT CBloodParticles::Render()
{
	HRESULT hr = S_OK;
	D3DXMATRIX matBillboard;

	if ( m_iNumParticles <= 0 )
		return S_OK;

	matBillboard = g_cam.GetViewMatrix();
	matBillboard._14 = 0.0f;
	matBillboard._24 = 0.0f;
	matBillboard._34 = 0.0f;
	matBillboard._44 = 1.0f;
	D3DXMatrixInverse( &matBillboard, NULL, &matBillboard );
	

	g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
	g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
	g_pd3dDevice->SetRenderState( D3DRS_ZWRITEENABLE, FALSE );	

	g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
 
	g_pd3dDevice->SetTexture( 0, m_ptexParticle );
	g_pd3dDevice->SetVertexShader( D3DFVF_NLTVERTEX );
	g_pd3dDevice->SetStreamSource( 0, m_pVB, sizeof(NLTVERTEX) );

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,   D3DTOP_MODULATE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE );
	g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );

	D3DXMATRIX matTranslate;
	for ( INT i=0; i<m_iNumParticles; i++ )
	{
		matBillboard._41 = m_particle[i].v.x;
		matBillboard._42 = m_particle[i].v.y;
		matBillboard._43 = m_particle[i].v.z;

		D3DXMatrixTranslation( &matTranslate, m_particle[i].v.x, m_particle[i].v.y, m_particle[i].v.z );
		g_pd3dDevice->SetTransform( D3DTS_WORLD, &matTranslate );

		if ( FAILED(hr = g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN, (i*4), 2)) )
			return hr;	
	}

	g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW );
	g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );
	g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_ZWRITEENABLE, TRUE );	
	g_pd3dDevice->SetTexture( 0, NULL );

	return hr;
}



//-----------------------------------------------------------------------------
// Name: CenterMesh()
// Desc: Finds the center of the mesh and then moves the mesh by vertex to origin.
//-----------------------------------------------------------------------------

HRESULT CenterMesh( CD3DMesh* pMesh, LPDIRECT3DVERTEXBUFFER8 pVB )
{
	HRESULT hr = S_OK;
	BYTE* pVertex = NULL;
	BYTE* pVertices = NULL;
	DWORD dwFVF = pMesh->GetSysMemMesh()->GetFVF();
	DWORD dwStride = D3DXGetFVFVertexSize( dwFVF );
	DWORD dwNumVerts = pMesh->GetSysMemMesh()->GetNumVertices();
	D3DXVECTOR3 vCentre;
	FLOAT fRadius;

	if ( !pVB )
	{
		MessageBoxOK( _T("CenterMesh()\nA buffer pointer is NULL!") );
		return E_FAIL;
	}

	if ( FAILED(pVB->Lock(0, NULL, &pVertices, NULL)) )
		return E_FAIL;

	D3DXComputeBoundingSphere( pVertices, dwNumVerts, dwFVF, &vCentre, &fRadius );

	INT iVert=0;
	for ( DWORD v=0; v<dwNumVerts; v++ )
	{
		iVert = v*dwStride;
		pVertex = pVertices + iVert;
		((ALLVERTEX*)pVertex)->x -= vCentre.x;
		((ALLVERTEX*)pVertex)->y -= vCentre.y;
		((ALLVERTEX*)pVertex)->z -= vCentre.z;
	}

	pVB->Unlock();	
	
	return hr;
}



//-----------------------------------------------------------------------------
// Name: CenterMeshFVF()
// Desc: Finds the center of the mesh and then moves the mesh by vertex to origin.
//-----------------------------------------------------------------------------

HRESULT CenterMeshFVF( LPD3DXMESH pMesh, DWORD dwFVF )
{
	HRESULT hr = S_OK;
	LPDIRECT3DVERTEXBUFFER8 pVB = NULL; 
	DWORD dwStride = D3DXGetFVFVertexSize( dwFVF );
	DWORD dwNumVerts = pMesh->GetNumVertices();
	D3DXVECTOR3 vCentre;
	FLOAT fRadius;

	pMesh->GetVertexBuffer( &pVB );

	if ( !pVB )
	{
		MessageBoxOK( _T("CenterMesh()\nA buffer pointer is NULL!") );
		return E_FAIL;
	}


	BYTE* pVertex = NULL;
	BYTE* pVertices = NULL;

	if ( FAILED(pVB->Lock(0, NULL, &pVertices, NULL)) )
		return E_FAIL;

	D3DXComputeBoundingSphere( pVertices, dwNumVerts, dwFVF, &vCentre, &fRadius );

	INT iVert=0;
	for ( DWORD v=0; v<dwNumVerts; v++ )
	{
		iVert = v*dwStride;
		pVertex = pVertices + iVert;
		((ALLVERTEX*)pVertex)->x -= vCentre.x;
		((ALLVERTEX*)pVertex)->y -= vCentre.y;
		((ALLVERTEX*)pVertex)->z -= vCentre.z;
	}

	pVB->Unlock();	
	
	return hr;
}




//-----------------------------------------------------------------------------
// Name: AddFlies()
// Desc: Adds flies to a firefly-group.
//-----------------------------------------------------------------------------

HRESULT CFireFlies::AddFlies( INT cNewFlies, D3DXVECTOR3 vPos, FLOAT fTimeStart, FLOAT fLocalTime, FLOAT fTimeDiff, LONG lRandSeed )
{
	HRESULT hr = S_OK;

	for ( INT i=m_iNumFlies; i<m_iNumFlies+cNewFlies; i++ )
	{
		for ( INT j=1; j<FIREFLY_GLOWLAYERS; j++ )	
			m_fly[i].v[j] =		D3DXVECTOR3( 0.0f, 0.0f, 0.0f );	// Set history positions to 0.0f offset from start position

		m_fly[i].v[0]			= vPos;	// start position
		m_fly[i].fSize			= 1.0f;
		m_fly[i].fVisibility	= 1.0f;
		m_fly[i].fTimeDiff		= fTimeDiff;
		m_fly[i].fSegTStart		= fTimeStart + ((i-m_iNumFlies)*fTimeDiff);	// Start time of segment
		m_fly[i].fSegTCurrent	= 0.0f;							// Current time in segment
		m_fly[i].fSegProg		= 0.0f;							// Progress factor of curve		

		if ( fLocalTime < m_fly[i].fSegTStart )
			m_fly[i].bExists = FALSE;
		else
			m_fly[i].bExists = TRUE;

		m_fly[i].fSegTLength = RandRange( 2.0f, 3.0f );

		m_fly[i].vSwirlV0 = D3DXVECTOR3( RandRange(-m_fGroupRadius, m_fGroupRadius), 
										 RandRange(1.0f,			m_fGroupRadius), 
										 RandRange(-m_fGroupRadius, m_fGroupRadius) ) + vPos;

		m_fly[i].vSwirlV1 = D3DXVECTOR3( RandRange(-m_fGroupRadius, m_fGroupRadius), 
										 RandRange(1.0f,			m_fGroupRadius), 
										 RandRange(-m_fGroupRadius, m_fGroupRadius) ) + vPos;

		m_fly[i].vSwirlV2 = D3DXVECTOR3( RandRange(-m_fGroupRadius, m_fGroupRadius), 
										 RandRange(1.0f,			m_fGroupRadius), 
										 RandRange(-m_fGroupRadius, m_fGroupRadius) ) + m_vGroupPos;

		m_fly[i].vSwirlV3 = D3DXVECTOR3( RandRange(-m_fGroupRadius, m_fGroupRadius), 
										 RandRange(1.0f,			m_fGroupRadius), 
										 RandRange(-m_fGroupRadius, m_fGroupRadius) ) + m_vGroupPos;
	}

	m_iNumFlies += cNewFlies;

	return hr;
}



//-----------------------------------------------------------------------------
// Name: Animate()
// Desc: Animates the group of fireflies
//-----------------------------------------------------------------------------

HRESULT CFireFlies::Animate( FLOAT fLocalTime )
{
	HRESULT	hr = S_OK;
	D3DXVECTOR3 vOldGroupPos;
	FLOAT	fThisTimeKey;
	FLOAT	fNextTimeKey;
	FLOAT	fSegProg;
	INT		i = 0;

	if ( m_iNumFlies <= 0 )
		return S_OK;


	//--------------------------------------------------------------------
	// GROUP OF FLIES MOVEMENT
	//--------------------------------------------------------------------
	
	NLTVERTEX vTable[] = 
	{
		{ -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0xffffffff, 0.0f, 0.0f },	// x,y,z,nx,ny,nz,col,tu,tv
		{  1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0xffffffff, 1.0f, 0.0f },
		{  1.0f,-1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0xffffffff, 1.0f, 1.0f },
		{ -1.0f,-1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0xffffffff, 0.0f, 1.0f },
	};

	for ( i=1; i<m_iNumWaypoints-1; i++ )	// Starting and ending within end-waypoints, because flies should never calculate splines to end-lines
	{
		
		if ( fLocalTime < m_wpWaypoint[i+1].fTime )	// if less, current time is between this and the previous waypoint
		{
			m_iCurrentWaypoint = i;
			fThisTimeKey = m_wpWaypoint[i].fTime;
			fNextTimeKey = m_wpWaypoint[i+1].fTime;
			break;
		}
	}

	fSegProg = (fLocalTime - fThisTimeKey) / (fNextTimeKey-fThisTimeKey);
	

	// Group position moves along curved waypoints
	vOldGroupPos = m_vGroupPos;
	D3DXVec3CatmullRom( &m_vGroupPos,		// Resulting interpolated point in curve
		&m_wpWaypoint[m_iCurrentWaypoint-1].v,	// Controlpoint for startpoint
		&m_wpWaypoint[m_iCurrentWaypoint+0].v,	// Startpoint in curve
		&m_wpWaypoint[m_iCurrentWaypoint+1].v,	// Endpoint in curve
		&m_wpWaypoint[m_iCurrentWaypoint+2].v,	// Controlpoint for endpoint
		fSegProg );



	//--------------------------------------------------------------------
	// INDIVIDUAL FLY MOVEMENT
	//--------------------------------------------------------------------

	NLTVERTEX* pVertices;
	if ( FAILED(hr = m_pVB->Lock(0, NULL, (BYTE**)&pVertices, NULL)) )
		return hr;		

	for ( i=0; i<m_iNumFlies; i++ )
	{
		m_fly[i].fSegTCurrent = fLocalTime - m_fly[i].fSegTStart;	// Currently spent time in segment
		m_fly[i].fSegProg = m_fly[i].fSegTCurrent / m_fly[i].fSegTLength;	// Progress of curve factor

		if ( m_fly[i].bExists == FALSE )	// If fly doesn't exist, check if it should start existing
		{
			if ( fLocalTime > m_fly[i].fSegTStart )
			{
				m_fly[i].bExists = TRUE;
			}
			else
				continue;	// If not, bring on the next fly
		}

		// Individual fly movement (swirl around group position)
		D3DXVECTOR3 vDistance;
		if ( m_fly[i].fSegProg >= 1.0f )	// REMEMBER to include excess time
		{
			m_fly[i].fSegTStart = fLocalTime;
			m_fly[i].fSegTCurrent = m_fly[i].fSegProg - 1.0f;
			m_fly[i].fSegTLength = RandRange( 1.0f, 1.5f );
			m_fly[i].fSegProg -= 1.0f;
			m_fly[i].vSwirlV0 = m_fly[i].vSwirlV1;
			m_fly[i].vSwirlV1 = m_fly[i].vSwirlV2;
			m_fly[i].vSwirlV2 = m_fly[i].vSwirlV3;
			
//			do
//			{
				m_fly[i].vSwirlV3 = D3DXVECTOR3( RandRange(-m_fGroupRadius, m_fGroupRadius), 
												 RandRange(1.0f,			m_fGroupRadius*3), 
												 RandRange(-m_fGroupRadius, m_fGroupRadius) ) + m_vGroupPos;				
			
//				vDistance = m_fly[i].vSwirlV3 - m_fly[i].vSwirlV2;

//			} while( (FLOAT)fabs(vDistance.x) < 2.0f || (FLOAT)fabs(vDistance.y) < 2.0f || (FLOAT)fabs(vDistance.z) < 2.0f );	// ensure that flies move at least a certain distance
		}

		//D3DXVECTOR3 vNewFlyPos;
		D3DXVECTOR3 vGlowDist;
		FLOAT fAlpha;
		for ( INT j=0; j<FIREFLY_GLOWLAYERS; j++ )
		{
			D3DXVec3CatmullRom( &m_fly[i].v[j],	// Resulting interpolated point in curve
				&m_fly[i].vSwirlV0,				// Controlpoint for startpoint
				&m_fly[i].vSwirlV1,				// Startpoint in curve
				&m_fly[i].vSwirlV2,				// Endpoint in curve
				&m_fly[i].vSwirlV3,				// Controlpoint for endpoint
				max(0, m_fly[i].fSegProg - (0.02f*j)) );// Progress factor

			if ( j>0 )
			{
				vGlowDist = m_fly[i].v[j]-m_fly[i].v[j-1];
				FLOAT vScaleFactor = FIREFLY_MAX_GLOWDIST * j;	// Rescales glow layers to within max_glow_dist

				if ( D3DXVec3Length(&vGlowDist) > FIREFLY_MAX_GLOWDIST )	// Distance to actual point should not exceed this magic value (or else you get gaps between the textures)
				{
					D3DXVec3Normalize( &m_fly[i].v[j], &vGlowDist );
					m_fly[i].v[j] *= vScaleFactor;
					m_fly[i].v[j] += m_fly[i].v[0];
				}				
			}

			// Create glow layers by adjusting diffuse for each glow layer
			fAlpha = (((1.0f - ((FLOAT)j/(FIREFLY_GLOWLAYERS-1))) * 255.0f) * (1.0f-((FLOAT)fabs(m_fly[i].v[j].z-(g_cam.GetEyePt().z+30.0f)) / 40.0f)) );
			fAlpha = max( 0.0f, min(255.0f, fAlpha) );	// Make sure alpha value doesn't wrap around

			vTable[0].diffuse = vTable[1].diffuse = vTable[2].diffuse = vTable[3].diffuse = D3DCOLOR_ARGB( (BYTE)fAlpha, 0xff, 0xff, 0xff );
			memcpy( pVertices+(i*FIREFLY_GLOWLAYERS*4)+(j*FIREFLY_GLOWLAYERS), vTable, sizeof(vTable) );
		}
	}
	m_pVB->Unlock();

	m_vAveragePos += m_fly[i].v[0];		// Add all vectors together, to later find average vector
	m_light.Position.x = m_fly[0].v[0].x; //m_vAveragePos.x;
	m_light.Position.z = m_fly[0].v[0].z; //m_vAveragePos.z;

	if ( m_fly[0].bExists )
		m_light.Diffuse.r = m_light.Diffuse.g = m_light.Diffuse.b = LinearChange( 0.0f, 56.0f, 11.0f, fLocalTime, 13.0f );
		g_pd3dDevice->SetLight( 4, &m_light );

	return hr;
}




//-----------------------------------------------------------------------------
// Name: CFireFlies()
// Desc: Constructor
//-----------------------------------------------------------------------------

CFireFlies::CFireFlies( INT iStartFlies )
{
	m_iNumFlies = iStartFlies;

	m_fGroupRadius	= 5.0f;
	m_fSpeed		= 1.0f;

    m_ptexFirefly	= NULL;

	ZeroMemory( m_wpWaypoint, sizeof(m_wpWaypoint ) );
	ZeroMemory( m_vAveragePos, sizeof(m_vAveragePos) );	

	FLOAT initWaypoints[] = 
	{
		   0.0f,   0.0f,  3.0f,   0.0f,	// time key, x, y, z
		   1.0f,   2.0f,  3.0f,   4.0f,
		   5.0f,  10.0f,  3.0f,  15.0f,
		  10.0f,   2.0f,  3.0f,   5.0f,
		  15.0f, -10.0f,  3.0f,  15.0f,
		  20.0f,  -5.0f,  3.0f,  -5.0f,
		  25.0f,  10.0f,  3.0f, -10.0f,
		  30.0f,   2.0f,  3.0f,  10.0f,
		  35.0f,  12.0f,  3.0f,   5.0f,
		  40.0f,   0.0f,  3.0f,   0.0f,
		  42.0f, -10.0f,  3.0f,  10.0f,
		  50.0f,  10.0f,  3.0f,  -5.0f,
		  55.0f,  -5.0f,  5.0f,   5.0f,
		  57.0f,  10.0f,  7.0f,  -5.0f,
		  58.0f,   0.0f, 12.0f,   0.0f,
		  59.0f,   0.0f,100.0f,   0.0f,
		2000.0f,   0.0f,100.0f,   0.0f,	// end point, not supposed to reach end time
	};

	m_iNumWaypoints = sizeof(initWaypoints) / sizeof(WAYPOINT3D);

/*	for ( INT wayp=0; wayp<10; wayp++ )
	{
		initWaypoints[((wayp*4*4) + 3)] -= 20.0f;	// Adjust Z-value of each waypoint (temporarily solution)
	}
*/
	memcpy( m_wpWaypoint, initWaypoints, sizeof(initWaypoints) );

	m_iCurrentWaypoint = 0;
	m_vGroupPos.x = m_wpWaypoint[0].v.x;
	m_vGroupPos.y = m_wpWaypoint[0].v.y;
	m_vGroupPos.z = m_wpWaypoint[0].v.z;

	for ( INT j=0; j<1; j++ )
		RandRange( 0.0f, 100.0f );

	for ( INT i=0; i<MAX_FIREFLIES; i++ )
	{
		for ( INT j=0; j<FIREFLY_GLOWLAYERS; j++ )	// History points are same as start point
		{
			m_fly[i].v[j].x = 0.0f;
			m_fly[i].v[j].y = 0.0f;
			m_fly[i].v[j].z = 0.0f;
		}
		m_fly[i].fSize			= 1.0f;
		m_fly[i].fVisibility	= 1.0f;
		m_fly[i].fSegTStart		= 0.0f;						// Start time of segment
		m_fly[i].fSegTCurrent	= 0.0f;						// Current time in segment
		m_fly[i].fSegTLength	= 1.0f;						// Max time in seconds for duration of curve
		m_fly[i].fSegProg		= 0.0f;						// Prog factor of curve

		if ( i < m_iNumFlies )
			m_fly[i].bExists = TRUE;	// Set wheter fly exists or not
		else
			m_fly[i].bExists = FALSE;


		m_fly[i].vSwirlV0 = D3DXVECTOR3( RandRange(-m_fGroupRadius, m_fGroupRadius), 
										 RandRange(1.0f,			m_fGroupRadius*3), 
										 RandRange(-m_fGroupRadius, m_fGroupRadius) ) + m_vGroupPos;

		m_fly[i].vSwirlV1 = D3DXVECTOR3( RandRange(-m_fGroupRadius, m_fGroupRadius), 
										 RandRange(1.0f,			m_fGroupRadius*3), 
										 RandRange(-m_fGroupRadius, m_fGroupRadius) ) + m_vGroupPos;

		m_fly[i].vSwirlV2 = D3DXVECTOR3( RandRange(-m_fGroupRadius, m_fGroupRadius), 
										 RandRange(1.0f,			m_fGroupRadius*3), 
										 RandRange(-m_fGroupRadius, m_fGroupRadius) ) + m_vGroupPos;

		m_fly[i].vSwirlV3 = D3DXVECTOR3( RandRange(-m_fGroupRadius, m_fGroupRadius), 
										 RandRange(1.0f,			m_fGroupRadius*3), 
										 RandRange(-m_fGroupRadius, m_fGroupRadius) ) + m_vGroupPos;
	}


	ZeroMemory( &m_light, sizeof(D3DLIGHT8) );
	m_light.Type = D3DLIGHT_POINT;
	m_light.Position.x	= m_vGroupPos.x;
	m_light.Position.y	= m_vGroupPos.y;
	m_light.Position.z	= m_vGroupPos.z;
	m_light.Diffuse.r	= 0.0f;
	m_light.Diffuse.g	= 0.0f;
	m_light.Diffuse.b	= 0.0f;
	m_light.Range		= 20.0f;
	m_light.Attenuation1 = 0.5f;
	m_light.Attenuation2 = 1.0f;
}



//-----------------------------------------------------------------------------
// Name: InvalidateDeviceObjects()
// Desc: Cleans up any allocated resources used by the class.
//-----------------------------------------------------------------------------

HRESULT CFireFlies::InvalidateDeviceObjects()
{
	HRESULT hr = S_OK;

	SAFE_RELEASE( m_pVB );
	SAFE_RELEASE( m_ptexFirefly );

	return S_OK;
}




//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Renders the group of fireflies
//-----------------------------------------------------------------------------

HRESULT CFireFlies::Render()
{
	HRESULT hr = S_OK;
	D3DXMATRIX matBillboard;

	if ( m_iNumFlies <= 0 )
		return S_OK;

	matBillboard = g_cam.GetViewMatrix();
	matBillboard._14 = 0.0f;
	matBillboard._24 = 0.0f;
	matBillboard._34 = 0.0f;
	matBillboard._44 = 1.0f;
	D3DXMatrixInverse( &matBillboard, NULL, &matBillboard );
	

	g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0x00000000 );
	g_pd3dDevice->SetVertexShader( D3DFVF_NLTVERTEX );
	g_pd3dDevice->SetStreamSource( 0, m_pVB, sizeof(NLTVERTEX) );
	g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
	g_pd3dDevice->SetRenderState( D3DRS_ZWRITEENABLE, FALSE );	

	g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
 
	g_pd3dDevice->SetTexture( 0, m_ptexFirefly );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,   D3DTOP_MODULATE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE );

	D3DXMATRIX matTranslate;
	for ( INT i=0; i<m_iNumFlies; i++ )
	{
		if ( !m_fly[i].bExists )
			continue;
		
		matBillboard._41 = m_fly[i].v[0].x;
		matBillboard._42 = m_fly[i].v[0].y;
		matBillboard._43 = m_fly[i].v[0].z;

		for ( INT j=FIREFLY_GLOWLAYERS-1; j>=0; j-- )
		{
			D3DXMatrixTranslation( &matTranslate, m_fly[i].v[j].x, m_fly[i].v[j].y, m_fly[i].v[j].z );
			g_pd3dDevice->SetTransform( D3DTS_WORLD, &matTranslate );
	
			if ( FAILED(hr = g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN, (i*FIREFLY_GLOWLAYERS*4)+(j*FIREFLY_GLOWLAYERS), 2)) )
				return hr;	
		}
	}

	g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );
	g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_ZWRITEENABLE, TRUE );	
	g_pd3dDevice->SetTexture( 0, NULL );

	return hr;
}



//-----------------------------------------------------------------------------
// Name: InitDeviceObjects()
// Desc: Initializes and allocates devicedepenent resources for the class.
//-----------------------------------------------------------------------------

HRESULT CFireFlies::InitDeviceObjects()
{
	HRESULT hr = S_OK;

#ifdef PLAY_SCENE01

	if ( FAILED(hr = g_pd3dDevice->CreateVertexBuffer(MAX_FIREFLIES*8*sizeof(NLTVERTEX), NULL, D3DFVF_NLTVERTEX, D3DPOOL_MANAGED, &m_pVB)) )
		return hr;

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene01\\firefly.png"), &m_ptexFirefly)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}        		

	g_pd3dDevice->SetLight( 4, &m_light );
	g_pd3dDevice->LightEnable( 4, TRUE );

#endif	// PLAY_SCENE01

	return S_OK;
}




//-----------------------------------------------------------------------------
// Name: ClearTexture()
// Desc: Clears the entire level 0 surface of the texture to a given color.
//       
//-----------------------------------------------------------------------------

HRESULT ClearTexture( LPDIRECT3DTEXTURE8 pTexture, D3DCOLOR dwColor )
{
	HRESULT hr = S_OK;

	if ( !pTexture )
	{
		MessageBoxOK( _T("ClearTexture()\npTexture is NULL!") );
		return E_FAIL;
	}

	SetRenderTargetToTexture( pTexture );
	g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET, dwColor, NULL, NULL );

	RestoreRenderTarget();

	return hr;
}




//-----------------------------------------------------------------------------
// Name: CloneVB()
// Desc: Copies a vertexbuffer to another. Both must have the same vertexformat,
//		 and be of exact same size.
//-----------------------------------------------------------------------------

HRESULT CloneVB( LPDIRECT3DVERTEXBUFFER8 pSource, LPDIRECT3DVERTEXBUFFER8 pDest )
{
	HRESULT hr = S_OK;
	D3DVERTEXBUFFER_DESC sourceDesc;
	D3DVERTEXBUFFER_DESC destDesc;

	BYTE* pSourceVerts;
	if ( FAILED(hr = pSource->Lock(0, NULL, &pSourceVerts, NULL)) )
		return hr;

	BYTE* pDestVerts;
	if ( FAILED(hr = pDest->Lock(0, NULL, &pDestVerts, NULL)) )
		return hr;

	pSource->GetDesc( &sourceDesc );
	pSource->GetDesc( &destDesc );

	if ( sourceDesc.Size != destDesc.Size )
	{
		MessageBoxOK( _T("CloneVB()\nBuffers have different size!") );
		return E_FAIL;
	}

	memcpy( pDestVerts, pSourceVerts, sourceDesc.Size );

	pSource->Unlock();
	pDest->Unlock();

	return hr;
}




HRESULT CMetaBall::Animate( FLOAT fLocalTime )
{
	HRESULT hr = S_OK;

	FLOAT theta = cosf( fLocalTime * METAB_SPEED );
	FLOAT phi	= sinf( fLocalTime * METAB_SPEED );
	FLOAT alpha = sinf( fLocalTime * METAB_SPEED );

	D3DXVECTOR3 fBall[METAB_BALLS] =
	{
		D3DXVECTOR3( -1.0f*METAB_MOVE_RADIUS, 0.5f*METAB_MOVE_RADIUS, 0.8f*METAB_MOVE_RADIUS ),
		D3DXVECTOR3(  0.0f*METAB_MOVE_RADIUS,-0.7f*METAB_MOVE_RADIUS, 0.4f*METAB_MOVE_RADIUS ),
		D3DXVECTOR3(  1.0f*METAB_MOVE_RADIUS, 0.6f*METAB_MOVE_RADIUS,-0.6f*METAB_MOVE_RADIUS ),
		D3DXVECTOR3(  0.0f*METAB_MOVE_RADIUS,-1.0f*METAB_MOVE_RADIUS, 1.0f*METAB_MOVE_RADIUS ),
	};

	D3DXMATRIX matRot1;
	D3DXMatrixRotationYawPitchRoll( &matRot1, fLocalTime * METAB_SPEED, fLocalTime * METAB_SPEED, fLocalTime * METAB_SPEED );
	D3DXMATRIX matRot2;
	D3DXMatrixRotationYawPitchRoll( &matRot2, -fLocalTime * METAB_SPEED, fLocalTime * METAB_SPEED, fLocalTime * METAB_SPEED );
	D3DXMATRIX matRot3;
	D3DXMatrixRotationYawPitchRoll( &matRot3, fLocalTime * METAB_SPEED, fLocalTime * METAB_SPEED, fLocalTime * METAB_SPEED );
	D3DXMATRIX matRot4;
	D3DXMatrixRotationYawPitchRoll( &matRot4, -fLocalTime * METAB_SPEED, fLocalTime * METAB_SPEED, fLocalTime * METAB_SPEED );

//	for ( INT i=0; i<METAB_BALLS; i++ )
//	{
		D3DXVec3TransformCoord( &m_ball[0].v, &fBall[0], &matRot1 );
		D3DXVec3TransformCoord( &m_ball[1].v, &fBall[1], &matRot2 );
		D3DXVec3TransformCoord( &m_ball[2].v, &fBall[2], &matRot3 );
		D3DXVec3TransformCoord( &m_ball[3].v, &fBall[3], &matRot4 );
//	}
//	theta = cosf( fLocalTime * METAB_SPEED + D3DX_PI*i*0.25f );
//		m_ball[i].v = D3DXVECTOR3( ((FLOAT)i/(m_iNumBalls-1))*METAB_MOVE_RADIUS*4 - METAB_MOVE_RADIUS, theta*METAB_MOVE_RADIUS, 0.0f );	
//	}


	g_metaBall.GenerateMetaMesh( fLocalTime );

	return hr;
}


CMetaBall::CMetaBall()
{
	m_pmeshMetaBall	= NULL;
	m_ptexMetaBall	= NULL;
	m_ptexBackground= NULL;
	m_pVB			= NULL;
	m_pIB			= NULL;
	ZeroMemory( &m_sdBackground, sizeof(m_sdBackground) );
}


HRESULT CMetaBall::GenerateIsoValues( GRIDCELL* pGridCell )
{
	HRESULT hr = S_OK;
	FLOAT fDist;
	FLOAT fMass = 1.0f;
	FLOAT fConst = 100.0f;
	FLOAT fIsoValue;

	for ( INT i=0; i<8; i++ )
	{
		for ( INT ball=0; ball<m_iNumBalls; ball++ )
		{
			D3DXVECTOR3 vDiff = pGridCell->p[i] - m_ball[ball].v;
			fDist = D3DXVec3Length(&vDiff);
			fIsoValue = (fConst * fMass) / powf(fDist,2);

			pGridCell->val[i] += 1.0f - min((fDist / METAB_RADIUS), 1.0f);	// isovalue	is between 0.0 and 1.0, 
			pGridCell->val[i] = max(min(pGridCell->val[i], 1.0f), 0.0f);				// 0.0 is for all values outside radius, and 1.0 is at centre of metaball
		}
	}																

	return hr;
}


/*
<kusma> husk at to grid-noder som er ved siden av hverandre deler fire hjørne-verdier
<kusma> gjør det om til to looper
<kusma> én genererings-loop
<kusma> og en polygoniserings-loop
<kusma> og så har du et array av grid-noder som har pekere til de korrekte hjørne-verdiene
*/

HRESULT CMetaBall::GenerateMetaMesh( FLOAT fLocalTime )
{
	HRESULT hr = S_OK;

	GRIDCELL gridCell;
	TRIANGLE myTriangles[5];


	// Set up gridcells 
	FLOAT fHalfGrid = (METAB_GRID_SIZE/2);
	FLOAT fDist = 0.0f;
	D3DXVECTOR3 vGridCellOffset;
	D3DXVECTOR3 normal;

	METAB_VERTEX* pVertices;
	METAB_VERTEX* pVertex;
	METAB_VERTEX  myTriangle[3];

	if ( FAILED(hr = m_pVB->Lock(0, NULL, (BYTE**)&pVertices, NULL)) )
		return hr;		

	INT iGeneratedTriangles = 0;
	m_iNumTriangles = 0;

	// Optimalizing variables

	for ( INT x=0; x<METAB_GRID_RES; x++ )
	{
		for ( INT y=0; y<METAB_GRID_RES; y++ )
		{
			for ( INT z=0; z<METAB_GRID_RES; z++ )
			{
				ZeroMemory( &gridCell, sizeof(gridCell) );
				vGridCellOffset = D3DXVECTOR3(	((FLOAT)x/(METAB_GRID_RES-1))*METAB_GRID_SIZE - fHalfGrid,
												((FLOAT)y/(METAB_GRID_RES-1))*METAB_GRID_SIZE - fHalfGrid, 
												((FLOAT)z/(METAB_GRID_RES-1))*METAB_GRID_SIZE - fHalfGrid );

				// Assign vector to each of the 8 points in the gridcells
				gridCell.p[0] = D3DXVECTOR3( 0.0f*METAB_CELL_SIZE, 0.0f*METAB_CELL_SIZE, 1.0f*METAB_CELL_SIZE ) + vGridCellOffset;
				gridCell.p[1] = D3DXVECTOR3( 1.0f*METAB_CELL_SIZE, 0.0f*METAB_CELL_SIZE, 1.0f*METAB_CELL_SIZE ) + vGridCellOffset;
				gridCell.p[2] = D3DXVECTOR3( 1.0f*METAB_CELL_SIZE, 0.0f*METAB_CELL_SIZE, 0.0f*METAB_CELL_SIZE ) + vGridCellOffset;
				gridCell.p[3] = D3DXVECTOR3( 0.0f*METAB_CELL_SIZE, 0.0f*METAB_CELL_SIZE, 0.0f*METAB_CELL_SIZE ) + vGridCellOffset;

				gridCell.p[4] = D3DXVECTOR3( 0.0f*METAB_CELL_SIZE, 1.0f*METAB_CELL_SIZE, 1.0f*METAB_CELL_SIZE ) + vGridCellOffset;
				gridCell.p[5] = D3DXVECTOR3( 1.0f*METAB_CELL_SIZE, 1.0f*METAB_CELL_SIZE, 1.0f*METAB_CELL_SIZE ) + vGridCellOffset;
				gridCell.p[6] = D3DXVECTOR3( 1.0f*METAB_CELL_SIZE, 1.0f*METAB_CELL_SIZE, 0.0f*METAB_CELL_SIZE ) + vGridCellOffset;
				gridCell.p[7] = D3DXVECTOR3( 0.0f*METAB_CELL_SIZE, 1.0f*METAB_CELL_SIZE, 0.0f*METAB_CELL_SIZE ) + vGridCellOffset;

				GenerateIsoValues( &gridCell );
				iGeneratedTriangles = Polygonise( gridCell, 0.1f, myTriangles );


				// Copy triangles to vertexbuffer
				for ( INT tri=0; tri<iGeneratedTriangles; tri++ )
				{
					pVertex = pVertices + ( (tri+m_iNumTriangles) * 3 );
					
					for ( INT v=0; v<3; v++ )
					{
						memcpy( &myTriangle[v],   &myTriangles[tri].p[v], sizeof(D3DXVECTOR3) );

						normal = D3DXVECTOR3( myTriangle[v].x, myTriangle[v].y, myTriangle[v].z );
						D3DXVec3Normalize( &normal, &normal );

						myTriangle[v].nx = normal.x;
						myTriangle[v].ny = normal.y;
						myTriangle[v].nz = normal.z;
					}

					memcpy( pVertex, myTriangle, 3*sizeof(METAB_VERTEX) );
				}

				// Update number of triangles in vertexbuffer
				m_iNumTriangles += iGeneratedTriangles;
			}
		}
	}

	m_pVB->Unlock();

	return hr;
}


HRESULT CMetaBall::InitDeviceObjects()
{
	HRESULT hr = S_OK;

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene04\\envmap2.jpg", &m_ptexMetaBall )) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}			

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene04\\wood.jpg", &m_ptexBackground )) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}			

	m_ptexBackground->GetLevelDesc( 0, &m_sdBackground );

	if ( FAILED(hr = D3DXCreateMeshFVF(METAB_FACES, METAB_VERTS, D3DXMESH_MANAGED, METAB_FVF, g_pd3dDevice, &g_metaBall.m_pmeshMetaBall)) )
		return hr;


	m_pmeshMetaBall->GetVertexBuffer( &m_pVB );
	m_pmeshMetaBall->GetIndexBuffer( &m_pIB );

	CenterMeshFVF( m_pmeshMetaBall, METAB_FVF );
	SizeMeshFVF  ( m_pmeshMetaBall, METAB_FVF, 70.0f );

	//D3DXComputeNormals( m_pmeshMetaBall );

	m_iNumBalls = METAB_BALLS;

	ZeroMemory( m_ball, sizeof(m_ball) );
	for ( INT i=0; i<m_iNumBalls; i++ )
	{		
		m_ball[i].fRadius = METAB_RADIUS;		
	}

	return hr;
}


HRESULT CMetaBall::InvalidateDeviceObjects()
{
	HRESULT hr = S_OK;

	SAFE_RELEASE( m_pmeshMetaBall );
	SAFE_RELEASE( m_ptexMetaBall );
	SAFE_RELEASE( m_ptexBackground );
	SAFE_RELEASE( m_pVB );
	SAFE_RELEASE( m_pIB );

	return hr;
}



HRESULT CMetaBall::Overlay( FLOAT fLocalTime )
{
	HRESULT hr = S_OK;

	FLOAT fTimeStart = 0.0f;
	FLOAT fTimeEnd = 1.0f;

	if ( fLocalTime >= fTimeStart && fLocalTime < fTimeEnd )
	{
		DrawRect( 
			LinearChange(100.0f, 400.0f, fTimeStart, g_fDTime, fTimeEnd),
			LinearChange(100.0f, 300.0f, fTimeStart, g_fDTime, fTimeEnd),
			LinearChange(300.0f, 800.0f, fTimeStart, g_fDTime, fTimeEnd),
			LinearChange(300.0f, 550.0f, fTimeStart, g_fDTime, fTimeEnd),
			g_dwColWhite,
			LinearChange(255.0f, 0.0f, fTimeStart, g_fDTime, fTimeEnd) );
	}

	fTimeStart = 4.0f;
	fTimeEnd = 5.5f;

	if ( fLocalTime >= fTimeStart && fLocalTime < fTimeEnd )
	{
		DrawRect( 
			LinearChange(300.0f, 800.0f, fTimeStart, g_fDTime, fTimeEnd),
			LinearChange(300.0f, 550.0f, fTimeStart, g_fDTime, fTimeEnd),
			LinearChange(100.0f, 400.0f, fTimeStart, g_fDTime, fTimeEnd),
			LinearChange(100.0f, 300.0f, fTimeStart, g_fDTime, fTimeEnd),

			g_dwColWhite,
			LinearChange(255.0f, 0.0f, fTimeStart, g_fDTime, fTimeEnd) );
	}

	return hr;
}


HRESULT CMetaBall::Render()
{
	HRESULT hr = S_OK;
	
	// Background layer 
	ShowTexture( m_ptexBackground, // 1937x768
		LinearChange(0.0f, g_fWindowX-1937.0f, TIME_SCENE04, g_fDTime, TIME_SCENE05), 
		0.0f,
		1937.0f, g_fWindowY, ALPHA_FULL, 1.0f, FALSE );

	// Metaball
	g_pd3dDevice->SetTexture( 0, m_ptexBackground );
	g_pd3dDevice->SetVertexShader( METAB_FVF );
	g_pd3dDevice->SetStreamSource( 0, m_pVB, sizeof(METAB_VERTEX) );
	
	g_pd3dDevice->SetMaterial( &g_stdMtrl );
	g_pd3dDevice->SetRenderState( D3DRS_FILLMODE, GLOBAL_FILLMODE );


	D3DXMATRIX matTrans;
	D3DXMATRIX matRot;
	D3DXMatrixTranslation( &matTrans, 0.0f, 0.0f, 50.0f );
	D3DXMatrixRotationYawPitchRoll( &matRot, 0.0f*g_fDTime, 0.0f*g_fDTime, 0.0f*g_fDTime );
	D3DXMatrixMultiply( &matRot, &matRot, &g_cam.GetViewMatrix() );
	g_pd3dDevice->SetTransform( D3DTS_VIEW, &matRot );


	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSU,  D3DTADDRESS_MIRROR );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSV,  D3DTADDRESS_MIRROR );


	// Generate spheremap texture coords, and shift them over
	D3DXMATRIX mat;
	mat._11 = 0.5f; mat._12 = 0.0f; mat._13 = 0.0f; mat._14 = 0.0f; 
	mat._21 = 0.0f; mat._22 =-0.5f; mat._23 = 0.0f; mat._24 = 0.0f; 
	mat._31 = 0.0f; mat._32 = 0.0f; mat._33 = 1.0f; mat._34 = 0.0f; 
	mat._41 = 0.5f; mat._42 = 0.5f; mat._43 = 0.0f; mat._44 = 1.0f; 

	g_pd3dDevice->SetTransform( D3DTS_TEXTURE0, &mat );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT2 );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_CAMERASPACENORMAL );	

	if ( FAILED(hr = g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, m_iNumTriangles)) )
		return hr;

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_PASSTHRU );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE );

	g_pd3dDevice->SetTexture( 0, NULL );

	return hr;
}




HRESULT CScene08::Animate( FLOAT fLocalTime )
{
	HRESULT hr = S_OK;

	D3DXMATRIX matRot;
	D3DXMATRIX matCam;

	if ( g_fDTime < TIME_SCENE09 )
	{
		g_cam.SetViewParams(D3DXVECTOR3(    0.0f,  50.0f,  -100.0f),
							D3DXVECTOR3(    0.0f,   0.0f,    0.0f),
							D3DXVECTOR3(    0.0f,   1.0f,    0.0f) );


		matCam = g_cam.GetViewMatrix();

		D3DXMatrixRotationYawPitchRoll( &matRot, 0.5f*g_fDTime, 0.75f*g_fDTime, 0.0f*g_fDTime );
		D3DXMatrixMultiply( &matRot, &matRot, &matCam );
		g_pd3dDevice->SetTransform( D3DTS_VIEW, &matRot );
	}

	return hr;
}


CScene08::CScene08()
{
	m_pmeshStar		= new CD3DMesh();
	m_pmeshSphere	= NULL;
	m_pvbStar		= NULL;
	m_pibStar		= NULL;
	m_ptexStar		= NULL;
}


HRESULT CScene08::Render()
{
	HRESULT hr = S_OK;
	D3DXMATRIX matRot;
	D3DXMATRIX matTrans;

	D3DXMatrixRotationYawPitchRoll( &matRot, 0.5f*g_fDTime, 0.0f*g_fDTime, 0.0f*g_fDTime );
	g_pd3dDevice->SetTransform( D3DTS_WORLD, &matRot );
	
	// Generate spheremap texture coords, and shift them over
	D3DXMATRIX mat;
	mat._11 = 0.5f; mat._12 = 0.0f; mat._13 = 0.0f; mat._14 = 0.0f; 
	mat._21 = 0.0f; mat._22 =-0.5f; mat._23 = 0.0f; mat._24 = 0.0f; 
	mat._31 = 0.0f; mat._32 = 0.0f; mat._33 = 1.0f; mat._34 = 0.0f; 
	mat._41 = 0.5f; mat._42 = 0.5f; mat._43 = 0.0f; mat._44 = 1.0f; 

	g_pd3dDevice->SetTransform( D3DTS_TEXTURE0, &mat );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT2 );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_CAMERASPACENORMAL );	

	g_pd3dDevice->SetTexture( 0, m_ptexStar );

	if ( FAILED(hr = m_pmeshStar->Render(g_pd3dDevice)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}


	if ( g_fDTime < TIME_SCENE09 )
	{
		FLOAT fOffset = 0.0f;
		for ( INT i=0; i<STAR_BALLS; i++ )
		{
			fOffset = (FLOAT)i / (STAR_BALLS-1) * D3DX_PI*1.5f;
			D3DXMatrixRotationYawPitchRoll( &matRot, STAR_BALLSPEED*(g_fDTime+fOffset)*-1.1f, 0.0f*(g_fDTime+fOffset), STAR_BALLSPEED*(g_fDTime+fOffset)*-1.9f );
			
			D3DXMatrixTranslation( &matTrans, 30.0f, 30.0f, 30.0f );
			D3DXMatrixMultiply( &matRot, &matTrans, &matRot );
			g_pd3dDevice->SetTransform( D3DTS_WORLD, &matRot );

			m_pmeshSphere->DrawSubset( 0 );
		}
	}
	if ( g_fDTime >= TIME_SCENE09 )
	{
		FLOAT fOffset = 0.0f;
		for ( INT i=0; i<STAR_BALLS; i++ )
		{
			fOffset = (FLOAT)i / (STAR_BALLS-1) * D3DX_PI*6.0f;
			D3DXMatrixRotationYawPitchRoll( &matRot, STAR_BALLSPEED2*(g_fDTime+fOffset)*-1.1f, 0.0f*(g_fDTime+fOffset), STAR_BALLSPEED2*(g_fDTime+fOffset)*-1.9f );
			
			D3DXMatrixTranslation( &matTrans, 30.0f, 30.0f, 30.0f );
			D3DXMatrixMultiply( &matRot, &matTrans, &matRot );
			g_pd3dDevice->SetTransform( D3DTS_WORLD, &matRot );

			m_pmeshSphere->DrawSubset( 0 );
		}

		D3DXVECTOR3 vEyePt;
		D3DXVec3TransformCoord( &vEyePt, &D3DXVECTOR3(30.0f, 30.0f, 30.0f), &matRot );
		g_cam.SetViewParams( vEyePt, g_cam.GetLookatPt(), g_cam.GetUpVec() );
		g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
	}

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_PASSTHRU );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE );

	return hr;
}


HRESULT CScene08::InitDeviceObjects()
{
	HRESULT hr = S_OK;

	if ( FAILED(hr = m_pmeshStar->Create( g_pd3dDevice, "data\\meshes\\scene08\\star.x")) )
	{
		DisplayErrorMsg2( hr, D3DAPPERR_MEDIANOTFOUND );
		return hr;
	}

	m_pmeshStar->SetFVF( g_pd3dDevice, D3DFVF_NVERTEX );
	m_pmeshStar->UseMeshMaterials( FALSE );
	m_pmeshStar->GetSysMemMesh()->GetVertexBuffer( &m_pvbStar );
	m_pmeshStar->GetSysMemMesh()->GetIndexBuffer( &m_pibStar );

	CenterMesh( m_pmeshStar, m_pvbStar );
	SizeMesh( m_pmeshStar, m_pvbStar, 60.0f );

	m_pmeshStar->RestoreDeviceObjects( g_pd3dDevice );
	D3DXComputeNormals( m_pmeshStar->GetSysMemMesh() );

	if ( FAILED(hr = D3DXCreateSphere(g_pd3dDevice, 1.0f, 9, 5, &m_pmeshSphere, NULL)) )
	{
		DisplayErrorMsg2( hr, D3DAPPERR_MEDIANOTFOUND );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene08\\envmap.jpg", &m_ptexStar)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	return hr;
}


HRESULT CScene08::InvalidateDeviceObjects()
{
	HRESULT hr = S_OK;

	m_pmeshStar->Destroy();
	SAFE_DELETE( m_pmeshStar );
	SAFE_RELEASE( m_pmeshSphere );
	SAFE_RELEASE( m_pvbStar );
	SAFE_RELEASE( m_pibStar );
	SAFE_RELEASE( m_ptexStar );

	return hr;
}



HRESULT CScene10::Animate( FLOAT fLocalTime )
{
	HRESULT hr = S_OK;

	return hr;
}


CScene10::CScene10()
{
	m_ptexFinalSplash	= NULL;
	m_ptexEndScreen		= NULL;
}


HRESULT CScene10::InitDeviceObjects()
{
	HRESULT hr = S_OK;

	if ( FAILED(hr = D3DXCreateTextureFromFile( g_pd3dDevice, "data\\bitmaps\\scene10\\finalsplash.jpg", &m_ptexFinalSplash)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}	

	if ( FAILED(hr = D3DXCreateTextureFromFile( g_pd3dDevice, "data\\bitmaps\\scene10\\endscreen.png", &m_ptexEndScreen)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}	

	return hr;
}


HRESULT CScene10::InvalidateDeviceObjects()
{
	HRESULT hr = S_OK;

	SAFE_RELEASE( m_ptexFinalSplash );
	SAFE_RELEASE( m_ptexEndScreen );
	return hr;
}




HRESULT CScene10::Render()
{
	HRESULT hr = S_OK;
	FLOAT fTimeStart;
	FLOAT fTimeEnd;

	fTimeStart = TIME_SCENE10;
	fTimeEnd = TIME_SCENE10+7.0f;

	if ( g_fDTime < fTimeEnd )
	{
		ShowTexture( m_ptexFinalSplash, 0.0f, 0.0f, g_fWindowX, g_fWindowY );
	}

	fTimeStart = TIME_SCENE10+3.5f;
	fTimeEnd = TIME_SCENE10+7.0f;
	if ( g_fDTime >= fTimeStart )
	{
		ShowTexture( m_ptexEndScreen, 0.0f, 0.0f, g_fWindowX, g_fWindowY, LinearChange(0.0f, 255.0f, fTimeStart, g_fDTime, fTimeEnd) );
	}

	Fade( 0xffffffff, 0x00ffffff, TIME_SCENE10, g_fDTime, TIME_SCENE10+1.1f );
	Fade( 0x00000000, 0xff000000, TIME_SCENE11-2.0f, g_fDTime, TIME_SCENE11-0.1f, 2.0f );

	// Handle eventual fades (must be done after all drawing, and before text)
	if ( g_bFading )
		FadeRect( g_dwFadeColor, g_rcScreen, TRUE );

	return hr;
}



//-----------------------------------------------------------------------------
// Name: InitApp()
// Desc: Initializes all variables and prepares them for use
//-----------------------------------------------------------------------------
HRESULT InitApp()
{
	g_pD3D			= NULL;
	g_pd3dDevice	= NULL;

    // Application and window specific
	g_fAspect = 1.0f;
    ZeroMemory( &g_rcScreen, sizeof(g_rcScreen) );
    g_cWindowX	 = 0;
	g_cWindowY	 = 0;
	g_fWindowX	 = 0;
	g_fWindowY	 = 0;
	g_midWindowX = 0;
	g_midWindowY = 0;

    // Time specific
	g_fDemoStartTime = 0.0f;
	g_fDTime = 0.0f;    


    // Fade members
    g_bFading	    = FALSE;
    g_fFadeStart    = 0;
    g_fFadeEnd      = 0;
	g_dwFadeColor   = 0x00000000;
	g_dwColWhite	= 0xffffffff;

    ZeroMemory( g_sliderVal, sizeof(g_sliderVal) );
    
	// Generic purpose
	g_pFont					= new CD3DFont( _T("Arial"), 10, D3DFONT_BOLD );
	g_dwTextColor			= TEXT_COLOR;
	g_ptexBlender			= NULL;
	g_ptexEnvmap			= NULL;
	g_psEnvmapStencil		= NULL;
	g_ptexScreenMask		= NULL;
	g_ptexScaleScreen		= NULL;
	g_ptexScreenBuffer		= NULL;
	g_psOrigRenderTarget	= NULL;
	g_psOrigStencilTarget	= NULL;
	g_pvbFadeRect			= NULL;
	g_pvbTexture			= NULL;
	g_ptexWhite				= NULL;
	g_ptexBlack				= NULL;

	// Loadscreen
	g_ptexLoadScreen = NULL;

	// Scene 01
	g_pmeshWater			= new CD3DMesh();
	g_ptexIAmFeeling		= NULL;
	g_ptexInAViolated		= NULL;
	g_ptexICanNoLonger		= NULL;
	g_ptexTheThings			= NULL;
	g_ptexIHaveForsaken		= NULL;
	g_ptexHeed				= NULL;
	g_ptexPresents			= NULL;
	g_ptexOurFirst			= NULL;
	g_ptexDemoEver			= NULL;
	g_ptexLogo				= NULL;
	g_ptexSplash1			= NULL;
	g_ptexShadow			= NULL;
    g_ptexWater				= NULL;
	g_ptexWaterEnvmap		= NULL;
	g_pvbWater				= NULL;
	g_pibWater				= NULL;	

	// Scene 06
	g_ptexSplash2	= NULL;

	// Scene 07
	g_ptexCredit1	= NULL;
	g_ptexCredit2	= NULL;
	g_ptexCredit3	= NULL;
	g_ptexHello		= NULL;

	// Scene 09
	g_iNumGreets		= 14;
	ZeroMemory( g_ptexGreets, sizeof(g_ptexGreets) );
	
	g_ptexDarkCodex		= NULL;
	g_ptexExceed		= NULL;
	g_ptexExcess		= NULL;
	g_ptexFairlight		= NULL;
	g_ptexFarbrausch	= NULL;
	g_ptexFutureCrew	= NULL;
	g_ptexHaujobb		= NULL;
	g_ptexInf			= NULL;
	g_ptexKvasigen		= NULL;
	g_ptexOrange		= NULL;
	g_ptexPopsyTeam		= NULL;
	g_ptexProgress		= NULL;
	g_ptexSunflower		= NULL;
	g_ptexYaphan		= NULL;
	return S_OK;
}



//-----------------------------------------------------------------------------
// Name: InitD3D()
// Desc: Initializes Direct3D
//-----------------------------------------------------------------------------
HRESULT InitD3D( HWND hWnd )
{
	HRESULT hr = S_OK;

    // Create the D3D object.
    if( NULL == ( g_pD3D = Direct3DCreate8( D3D_SDK_VERSION ) ) )
        return E_FAIL;

    // Get the current desktop display mode, so we can set up a back
    // buffer of the same format
    D3DDISPLAYMODE d3ddm;
    if( FAILED( g_pD3D->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &d3ddm ) ) )
        return E_FAIL;

    // Set up the structure used to create the D3DDevice. Since we are now
    // using more complex geometry, we will create a device with a zbuffer.
    D3DPRESENT_PARAMETERS d3dpp; 
    ZeroMemory( &d3dpp, sizeof(d3dpp) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = d3ddm.Format;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.BackBufferCount = 2;
	d3dpp.BackBufferWidth = WINDOW_WIDTH;
	d3dpp.BackBufferHeight = WINDOW_HEIGHT;

#ifdef FULLSCREEN
	d3dpp.Windowed = FALSE;
	d3dpp.BackBufferWidth = WINDOW_WIDTH;
	d3dpp.BackBufferHeight = WINDOW_HEIGHT;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.FullScreen_RefreshRateInHz = d3ddm.RefreshRate;
	d3dpp.FullScreen_PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;
#endif

    // Create the D3DDevice
    if( FAILED( hr = g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                      D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,
                                      &d3dpp, &g_pd3dDevice ) ) )
    {
		DisplayErrorMsg2( hr, NULL );
        return E_FAIL;
    }

    // Turn on the zbuffer
    g_pd3dDevice->SetRenderState( D3DRS_ZENABLE, TRUE );

    // Turn on ambient lighting 
    g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );

    return S_OK;
}




//-----------------------------------------------------------------------------
// Name: FinalCleanup()
// Desc: Called before the app exits, this function gives the app the chance
//       to cleanup after itself.
//-----------------------------------------------------------------------------
HRESULT FinalCleanup()
{
    HRESULT hr = S_OK;

    SAFE_DELETE( g_pFont );

	SAFE_RELEASE( g_pd3dDevice );
	SAFE_RELEASE( g_pD3D );

#ifdef PLAYMUSIC 
	FSOUND_Close();
#endif
    return hr;
}



//-----------------------------------------------------------------------------
// Name: InitDeviceObjects()
// Desc: Initialize scene objects.
//-----------------------------------------------------------------------------
HRESULT InitDeviceObjects()
{
	HRESULT hr	= S_OK;

//-----------------------------------------------------------------------------
//	Restore part
//-----------------------------------------------------------------------------

	g_pd3dDevice->SetRenderState( D3DRS_ZENABLE, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_ZWRITEENABLE, TRUE );	
	g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0x00000000 );
	g_pd3dDevice->SetRenderState( D3DRS_FILLMODE, GLOBAL_FILLMODE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
	g_pd3dDevice->SetRenderState( D3DRS_POINTSIZE, *((DWORD*)&g_fPointSize) );

#ifdef FULLSCREEN
	SetCursor( NULL );
	g_pd3dDevice->ShowCursor( FALSE );
#endif

	g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW );

	g_pd3dDevice->GetRenderTarget( &g_psOrigRenderTarget );
	g_pd3dDevice->GetDepthStencilSurface( &g_psOrigStencilTarget );

	// Initialize the font 
    if ( FAILED(hr = g_pFont->InitDeviceObjects(g_pd3dDevice)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	g_pFont->RestoreDeviceObjects();
	
	D3DXMatrixIdentity( &g_matIdentity );
	
	LPDIRECT3DSURFACE8 pBackbuffer;
	g_pd3dDevice->GetBackBuffer( 0, D3DBACKBUFFER_TYPE_MONO, &pBackbuffer );
	pBackbuffer->GetDesc( &g_d3dsdBackBuffer );
	SAFE_RELEASE( pBackbuffer );

	g_fAspect		= (FLOAT)g_d3dsdBackBuffer.Width / (FLOAT)g_d3dsdBackBuffer.Height;
	g_cWindowX		= g_d3dsdBackBuffer.Width;
	g_cWindowY		= g_d3dsdBackBuffer.Height;
	g_fWindowX		= (FLOAT)g_d3dsdBackBuffer.Width;;
	g_fWindowY		= (FLOAT)g_d3dsdBackBuffer.Height;
	g_fMidWindowX	= (FLOAT)g_cWindowX / 2.0f;
	g_fMidWindowY	= (FLOAT)g_cWindowY / 2.0f;
	g_midWindowX	= (INT)g_fMidWindowX;
	g_midWindowY	= (INT)g_fMidWindowY;
	g_fScaleX		= g_fWindowX / 1024.0f;
	g_fScaleY		= g_fWindowY / 768.0f;
    g_rcScreen.right  = g_cWindowX;    
    g_rcScreen.bottom = g_cWindowY;
	

	// Set up a standard material for general purpose (most use this)
	ZeroMemory( &g_stdMtrl, sizeof(D3DMATERIAL8) );
	g_stdMtrl.Diffuse.r = g_stdMtrl.Ambient.r = 1.0f;
	g_stdMtrl.Diffuse.g = g_stdMtrl.Ambient.g = 1.0f;
	g_stdMtrl.Diffuse.b = g_stdMtrl.Ambient.b = 1.0f;
	g_stdMtrl.Diffuse.a = g_stdMtrl.Ambient.a = 1.0f;
	g_pd3dDevice->SetMaterial( &g_stdMtrl );

	// Set up a general purpose point light
	ZeroMemory( &g_pointLight, sizeof(g_pointLight) );
	g_pointLight.Type = D3DLIGHT_POINT;
	g_pointLight.Diffuse.r	= 0xff;
	g_pointLight.Diffuse.g	= 0xff;
	g_pointLight.Diffuse.b	= 0xff;
	g_pointLight.Diffuse.a	= 0xff;
	g_pointLight.Position	= D3DXVECTOR3( 0.0f, .0f, 0.0f );
	g_pointLight.Range		= 200.0f;
	g_pointLight.Attenuation1 = 1.0f;
	g_pd3dDevice->SetLight( LIGHT_POINT, &g_pointLight );

	// Set up a general purpose directional light (direction vector is 'diagonal' by default)
	ZeroMemory( &g_dirLight, sizeof(g_dirLight) );
	g_dirLight.Type = D3DLIGHT_DIRECTIONAL;
	g_dirLight.Diffuse.r = 0xff;
	g_dirLight.Diffuse.g = 0xff;
	g_dirLight.Diffuse.b = 0xff;
	g_dirLight.Diffuse.a = 0xff;
	g_dirLight.Direction = D3DXVECTOR3( 1.0f, -1.0f, -1.0f);
	g_pd3dDevice->SetLight( LIGHT_DIRECTIONAL, &g_dirLight );


	// Set gamma
	D3DGAMMARAMP ramp;
	g_pd3dDevice->GetGammaRamp( &ramp );
	for ( INT r=0; r<256; r++ )
		ramp.red[r] = (WORD)min((ramp.red[r] * GAMMA_RED), 65535L);

	for ( INT g=0; g<256; g++ )
		ramp.green[g] = (WORD)min((ramp.green[g] * GAMMA_GREEN), 65535L);

	for ( INT b=0; b<256; b++ )
		ramp.blue[b] = (WORD)min((ramp.blue[b] * GAMMA_BLUE), 65535L);

	g_pd3dDevice->SetGammaRamp( D3DSGR_CALIBRATE, &ramp );


	// General purpose resources

	if ( FAILED(hr = D3DXCreateTexture( g_pd3dDevice, 64, 64, 1, D3DUSAGE_RENDERTARGET, g_d3dsdBackBuffer.Format, D3DPOOL_DEFAULT, &g_ptexScaleScreen)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTexture( g_pd3dDevice, 512, 512, 1, D3DUSAGE_RENDERTARGET, g_d3dsdBackBuffer.Format, D3DPOOL_DEFAULT, &g_ptexBlender)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTexture( g_pd3dDevice, WINDOW_WIDTH, WINDOW_HEIGHT, 1, D3DUSAGE_RENDERTARGET, g_d3dsdBackBuffer.Format, D3DPOOL_DEFAULT, &g_ptexScreenBuffer)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}


	if ( FAILED(hr = g_pd3dDevice->CreateCubeTexture( CUBEMAP_RES, 1, D3DUSAGE_RENDERTARGET, g_d3dsdBackBuffer.Format, D3DPOOL_DEFAULT, &g_ptexEnvmap)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	if ( FAILED(hr = g_pd3dDevice->CreateDepthStencilSurface( CUBEMAP_RES, CUBEMAP_RES, D3DFMT_D16, D3DMULTISAMPLE_NONE, &g_psEnvmapStencil)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}




//-----------------------------------------------------------------------------
//	InitDevice part
//-----------------------------------------------------------------------------

	//m_hwndManipl = CreateDialog( m_hInst, MAKEINTRESOURCE(IDD_MANIPULATOR), m_hWnd, ManipulatorProc );


	// General purpose
	if ( FAILED(hr = g_pd3dDevice->CreateVertexBuffer( 4*sizeof(TLVERTEX), 0, D3DFVF_TLVERTEX, D3DPOOL_MANAGED, &g_pvbFadeRect)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	if ( FAILED(hr = g_pd3dDevice->CreateVertexBuffer( 4*sizeof(TTVERTEX), 0, D3DFVF_TLVERTEX, D3DPOOL_MANAGED, &g_pvbTexture)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}




//-------------------------------------------------------------------------
//	Loader part, this takes time so we render a loadscreen first
//-------------------------------------------------------------------------

#ifdef PLAY_LOADSCREEN


	if ( FAILED(hr = D3DXCreateTextureFromFile( g_pd3dDevice, "data\\bitmaps\\loadingscreen.jpg", &g_ptexLoadScreen)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}	

	if( FAILED(hr = g_pd3dDevice->BeginScene()) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	g_pd3dDevice->Clear( 0L, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(0xff,0x00,0x00,0x00), 1.0f, NULL );	// Clear the scene		



	if ( FAILED(hr = LoadScreen(g_fDTime)) )
		return hr;

	g_pd3dDevice->EndScene();
	g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
#endif




#ifdef PLAYMUSIC 
	FSOUND_Init(44100, 32, 0);
	g_psampleMusic = FSOUND_Sample_Load( FSOUND_FREE, "intro.mp3", FSOUND_LOOP_OFF, NULL );
#endif


	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\white.jpg", &g_ptexWhite)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}	

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\black.jpg", &g_ptexBlack)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}	

	// Scene 01
#ifdef PLAY_SCENE01
	if ( FAILED(InitScene01()) )
		return E_FAIL;
#endif

	// Scene 02
#ifdef PLAY_SCENE02
	if ( FAILED(hr = g_tunnel.InitDeviceObjects()) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}
#endif

	// Scene 03
#ifdef PLAY_SCENE03
		if ( FAILED(hr = g_textScene.InitDeviceObjects()) )
		{
			DisplayErrorMsg2( hr, NULL );
			return hr;
		}
#endif

	// Scene 04
#ifdef PLAY_SCENE04	
	if ( FAILED(hr = g_metaBall.InitDeviceObjects()) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}
#endif


	// Scene 05
#ifdef PLAY_SCENE05
	if ( FAILED(hr = g_tunnel2.InitDeviceObjects()) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	if ( FAILED(hr = g_bParticles.InitDeviceObjects()) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	D3DXComputeNormals( g_tunnel2.m_pmeshTunnel );	// Oddly enough, computenormals cannot be initiated right after GenerateTunnel()
	
#endif


	// Scene 06
#ifdef PLAY_SCENE06
	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene06\\forest.jpg", &g_ptexSplash2)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}
#endif 


	// Scene 07
#ifdef PLAY_SCENE07
	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene07\\credit1.jpg", &g_ptexCredit1)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene07\\credit2.jpg", &g_ptexCredit2)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene07\\credit3.jpg", &g_ptexCredit3)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene07\\hello.jpg", &g_ptexHello)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

#endif 

	// Scene 08
#ifdef PLAY_SCENE08
	if ( FAILED(g_scene08.InitDeviceObjects()) )
		return E_FAIL;
#endif

	// Scene 09
#ifdef PLAY_SCENE08
	if ( FAILED(InitScene09()) )
		return E_FAIL;
#endif

	// Scene 10
#ifdef PLAY_SCENE10
	if ( FAILED(g_scene10.InitDeviceObjects()) )
		return E_FAIL;
#endif

    return hr;
}



//-----------------------------------------------------------------------------
// Name: InitScene01()
// Desc: Initializes resources for scene01
//-----------------------------------------------------------------------------

HRESULT InitScene01()
{
	HRESULT hr = S_OK;

#ifdef PLAY_SCENE01

	if ( FAILED(hr = D3DXCreateMeshFVF( WATER_FACES, WATER_VERTS, D3DXMESH_MANAGED, WATER_FVF, g_pd3dDevice, &g_pmeshWater->m_pSysMemMesh)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	g_pmeshWater->GetSysMemMesh()->GetVertexBuffer( &g_pvbWater );
	g_pmeshWater->GetSysMemMesh()->GetIndexBuffer( &g_pibWater );
	g_pmeshWater->UseMeshMaterials( FALSE );



	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene01\\iamfeeling.png"), &g_ptexIAmFeeling)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene01\\inaviolated.png"), &g_ptexInAViolated)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene01\\icannolonger.png"), &g_ptexICanNoLonger)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene01\\thethings.png"), &g_ptexTheThings)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene01\\ihaveforsaken.png"), &g_ptexIHaveForsaken)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}


	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene01\\heed.png"), &g_ptexHeed)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene01\\presents.png"), &g_ptexPresents)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}
	
	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene01\\ourfirst.png"), &g_ptexOurFirst)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}
	
	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene01\\demoever.png"), &g_ptexDemoEver)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}


	
	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene01\\logo.png", &g_ptexLogo)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene01\\splash.jpg", &g_ptexSplash1)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene01\\shadow.png", &g_ptexShadow)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene01\\bluewater.jpg", &g_ptexWater )) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}


	if ( FAILED(hr = g_flyGroup1.InitDeviceObjects()) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}
	
	if ( FAILED(hr = g_pd3dDevice->CreateCubeTexture( CUBEMAP_RES, 1, D3DUSAGE_RENDERTARGET, g_d3dsdBackBuffer.Format, D3DPOOL_DEFAULT, &g_ptexWaterEnvmap)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	for ( INT i=0; i<6; i++ )
	{
		SetRenderTargetToCubemap( i, g_ptexWaterEnvmap, NULL );
		ShowTexture( g_ptexWater, 0.0f, 0.0f, (FLOAT)CUBEMAP_RES, (FLOAT)CUBEMAP_RES );
	}
	RestoreRenderTarget();

#endif

	return hr;
}



//-----------------------------------------------------------------------------
// Name: InitScene09()
// Desc: Initializes resources for scene01
//-----------------------------------------------------------------------------

HRESULT InitScene09()
{
	HRESULT hr = S_OK;

#ifdef PLAY_SCENE01

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene09\\darkcodex.png"), &g_ptexDarkCodex)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene09\\exceed.png"), &g_ptexExceed)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene09\\excess.png"), &g_ptexExcess)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene09\\fairlight.png"), &g_ptexFairlight)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}


	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene09\\farbrausch.png"), &g_ptexFarbrausch)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene09\\futurecrew.png"), &g_ptexFutureCrew)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}
	
	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene09\\haujobb.png"), &g_ptexHaujobb)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}
	
	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene09\\inf.png"), &g_ptexInf)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene09\\kvasigen.png"), &g_ptexKvasigen)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene09\\orange.png"), &g_ptexOrange)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}
	
	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene09\\popsyteam.png"), &g_ptexPopsyTeam)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}
	
	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene09\\progress.png"), &g_ptexProgress)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene09\\sunflower.png"), &g_ptexSunflower)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene09\\yaphan.png"), &g_ptexYaphan)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	g_ptexGreets[0] = g_ptexDarkCodex;
	g_ptexGreets[1] = g_ptexExceed;
	g_ptexGreets[2] = g_ptexExcess;
	g_ptexGreets[3] = g_ptexFairlight;
	g_ptexGreets[4] = g_ptexFarbrausch;
	g_ptexGreets[5] = g_ptexFutureCrew;
	g_ptexGreets[6] = g_ptexHaujobb;
	g_ptexGreets[7] = g_ptexInf;
	g_ptexGreets[8] = g_ptexKvasigen;
	g_ptexGreets[9] = g_ptexOrange;
	g_ptexGreets[10] = g_ptexPopsyTeam;
	g_ptexGreets[11] = g_ptexProgress;
	g_ptexGreets[12] = g_ptexSunflower;
	g_ptexGreets[13] = g_ptexYaphan;

	
#endif

	return hr;
}


HRESULT InvalidateScene09()
{
	HRESULT hr = S_OK;

	SAFE_RELEASE( g_ptexDarkCodex );
	SAFE_RELEASE( g_ptexExceed );
	SAFE_RELEASE( g_ptexExcess );
	SAFE_RELEASE( g_ptexFairlight );
	SAFE_RELEASE( g_ptexFarbrausch );
	SAFE_RELEASE( g_ptexFutureCrew );
	SAFE_RELEASE( g_ptexHaujobb );
	SAFE_RELEASE( g_ptexInf );
	SAFE_RELEASE( g_ptexKvasigen );
	SAFE_RELEASE( g_ptexOrange );
	SAFE_RELEASE( g_ptexPopsyTeam );
	SAFE_RELEASE( g_ptexProgress );
	SAFE_RELEASE( g_ptexSunflower );
	SAFE_RELEASE( g_ptexYaphan );

	return hr;
}

//-----------------------------------------------------------------------------
// Name: InvalidateDeviceObjects()
// Desc: 
//-----------------------------------------------------------------------------
HRESULT InvalidateDeviceObjects()
{
    HRESULT hr = S_OK;

	// General purpose
	g_pFont->InvalidateDeviceObjects();
	g_pFont->DeleteDeviceObjects();
	
    SAFE_RELEASE( g_ptexBlender );	
	SAFE_RELEASE( g_ptexEnvmap );
	SAFE_RELEASE( g_psEnvmapStencil );
	SAFE_RELEASE( g_ptexScreenMask );
	SAFE_RELEASE( g_ptexScaleScreen );
	SAFE_RELEASE( g_ptexScreenBuffer );
	SAFE_RELEASE( g_psOrigRenderTarget );
	SAFE_RELEASE( g_psOrigStencilTarget );
	SAFE_RELEASE( g_pvbFadeRect );
	SAFE_RELEASE( g_pvbTexture );
	SAFE_RELEASE( g_ptexWhite );
	SAFE_RELEASE( g_ptexBlack );


	// Loadscreen
#ifdef PLAY_LOADSCREEN
	SAFE_RELEASE( g_ptexLoadScreen );
#endif

	// Scene 01
#ifdef PLAY_SCENE01
	g_flyGroup1.InvalidateDeviceObjects();
	g_pmeshWater->InvalidateDeviceObjects();
	g_pmeshWater->Destroy();
	SAFE_DELETE( g_pmeshWater );

	SAFE_RELEASE( g_ptexWaterEnvmap );
	SAFE_RELEASE( g_ptexLogo );
	SAFE_RELEASE( g_ptexSplash1 );
	SAFE_RELEASE( g_ptexShadow );

	SAFE_RELEASE( g_ptexIAmFeeling );
	SAFE_RELEASE( g_ptexInAViolated );
	SAFE_RELEASE( g_ptexICanNoLonger );
	SAFE_RELEASE( g_ptexTheThings );
	SAFE_RELEASE( g_ptexIHaveForsaken );
	SAFE_RELEASE( g_ptexHeed );
	SAFE_RELEASE( g_ptexPresents );
	SAFE_RELEASE( g_ptexOurFirst );
	SAFE_RELEASE( g_ptexDemoEver );
	SAFE_RELEASE( g_ptexWater );
	SAFE_RELEASE( g_pvbWater );
	SAFE_RELEASE( g_pibWater );
#endif

	// Scene 02
#ifdef PLAY_SCENE02
	g_tunnel.InvalidateDeviceObjects();
#endif

	// Scene 03
#ifdef PLAY_SCENE03
	g_textScene.InvalidateDeviceObjects();
#endif

	// Scene 04
#ifdef PLAY_SCENE04
	g_metaBall.InvalidateDeviceObjects();
#endif

	// Scene 05
#ifdef PLAY_SCENE05
	g_tunnel2.InvalidateDeviceObjects();
	g_bParticles.InvalidateDeviceObjects();
#endif

	// Scene 06
#ifdef PLAY_SCENE06
	SAFE_RELEASE( g_ptexSplash2 );
#endif


	// Scene 07
#ifdef PLAY_SCENE07
	SAFE_RELEASE( g_ptexCredit1 );
	SAFE_RELEASE( g_ptexCredit2 );
	SAFE_RELEASE( g_ptexCredit3 );
	SAFE_RELEASE( g_ptexHello );
#endif

	// Scene 08
#ifdef PLAY_SCENE08
	g_scene08.InvalidateDeviceObjects();
#endif

	// Scene 09
#ifdef PLAY_SCENE09
	InvalidateScene09();
#endif

	// Scene 10
#ifdef PLAY_SCENE10
	g_scene10.InvalidateDeviceObjects();
#endif


    return hr;
}




//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Called once per frame, the call is the entry point for 3d
//       rendering. This function sets up render states, clears the
//       viewport, and renders the scene.
//-----------------------------------------------------------------------------
HRESULT Render()
{
    HRESULT hr = S_OK;
	INT iFaces = 0;
	TCHAR szTmp[50] = "";
	TCHAR szFPS[20] = "";
	TCHAR szFreeMem[50] = "";
	
	static BOOL		bFirstTime = TRUE;
	static DWORD	dwFrameCount = 0;
	static INT		iFPS = 0;
	static FLOAT	fLastSecond = 0.0f;


	g_fTBoost = DEF_TIMEJUMP;

	if ( bFirstTime )
	{
		g_fDemoStartTime = DXUtil_Timer( TIMER_GETABSOLUTETIME );

		bFirstTime = FALSE;
	}

		
		// Store elapsed time in a textbuffer
		g_fDTime = (DXUtil_Timer(TIMER_GETABSOLUTETIME) - g_fDemoStartTime) * SLOWMO_FACTOR + g_fTBoost;
		sprintf( szDemoTime, _T("Time elapsed: %f"), g_fDTime );



		// Draw scene
		if( FAILED(hr = g_pd3dDevice->BeginScene()) )
		{
			DisplayErrorMsg2( hr, NULL );
			return hr;
		}

		g_pd3dDevice->Clear( 0L, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, g_dwBackgroundColor, 1.0f, NULL );	// Clear the scene		


#ifdef PLAY_SCENE01
		if ( iOnlyPlayScene == 1 || (!ONLY_PLAY_SCENE && g_fDTime >= TIME_SCENE01 && g_fDTime < TIME_SCENE02) )
			if ( FAILED(hr = AScene01(g_fDTime)) )
				return hr;
#endif

#ifdef PLAY_SCENE02
		if ( iOnlyPlayScene == 2 || (!ONLY_PLAY_SCENE && g_fDTime >= TIME_SCENE02 && g_fDTime < TIME_SCENE03) )
			if ( FAILED(hr = AScene02(g_fDTime)) )
				return hr;
#endif

#ifdef PLAY_SCENE03
		if ( iOnlyPlayScene == 3 || (!ONLY_PLAY_SCENE && g_fDTime >= TIME_SCENE03 && g_fDTime < TIME_SCENE04) )
			if ( FAILED(hr = AScene03(g_fDTime)) )
				return hr;
#endif

#ifdef PLAY_SCENE04
		if ( iOnlyPlayScene == 4 || (!ONLY_PLAY_SCENE && g_fDTime >= TIME_SCENE04 && g_fDTime < TIME_SCENE05) )
			if ( FAILED(hr = AScene04(g_fDTime)) )
				return hr;
#endif

#ifdef PLAY_SCENE05
		if ( iOnlyPlayScene == 5 || (!ONLY_PLAY_SCENE && g_fDTime >= TIME_SCENE05 && g_fDTime < TIME_SCENE06) )
			if ( FAILED(hr = AScene05(g_fDTime)) )
				return hr;
#endif

#ifdef PLAY_SCENE06
		if ( iOnlyPlayScene == 6 || (!ONLY_PLAY_SCENE && g_fDTime >= TIME_SCENE06 && g_fDTime < TIME_SCENE07) )
			if ( FAILED(hr = AScene06(g_fDTime)) )
				return hr;
#endif

#ifdef PLAY_SCENE07
		if ( iOnlyPlayScene == 7 || (!ONLY_PLAY_SCENE && g_fDTime >= TIME_SCENE07 && g_fDTime < TIME_SCENE08) )
			if ( FAILED(hr = AScene07(g_fDTime)) )
				return hr;
#endif

#ifdef PLAY_SCENE08
		if ( iOnlyPlayScene == 8 || (!ONLY_PLAY_SCENE && g_fDTime >= TIME_SCENE08 && g_fDTime < TIME_SCENE09) )
			if ( FAILED(hr = AScene08(g_fDTime)) )
				return hr;
#endif

#ifdef PLAY_SCENE09
		if ( iOnlyPlayScene == 9 || (!ONLY_PLAY_SCENE && g_fDTime >= TIME_SCENE09 && g_fDTime < TIME_SCENE10) )
			if ( FAILED(hr = AScene09(g_fDTime)) )
				return hr;
#endif

#ifdef PLAY_SCENE10
		if ( iOnlyPlayScene == 10 || (!ONLY_PLAY_SCENE && g_fDTime >= TIME_SCENE10 && g_fDTime < TIME_SCENE11) )
			if ( FAILED(hr = AScene10(g_fDTime)) )
				return hr;
#endif


	if ( !ONLY_PLAY_SCENE && g_fDTime >= TIME_SCENE11 )	// End of demo, return with error to close application
		return E_FAIL;
  
		dwFrameCount++;
		if ( g_fDTime > fLastSecond + 1.0f )
		{
			iFPS = dwFrameCount;
			fLastSecond = g_fDTime;
			dwFrameCount = 0;
		}
		sprintf( szFPS, "FPS: %i", iFPS );

#ifdef INFOTEXT
		// Show informative text at the upperleft part of screen
		g_pFont->DrawText( 2, 0,  g_dwTextColor, g_szInfoLine1 );
		g_pFont->DrawText( 2, 20, g_dwTextColor, g_szInfoLine2 );
		g_pFont->DrawText( 2, 40, g_dwTextColor, szFPS);
		g_pFont->DrawText( 2, 60, g_dwTextColor, szDemoTime );
#endif
		ShowTexture( NULL, 0.0f, 0.0f, 1.0f, 1.0f );

		g_pd3dDevice->EndScene();
		g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
 
    return hr;
}



//-----------------------------------------------------------------------------
// Name: AScene01()
// Desc: The introscene, with text on an animated watersurface.
//-----------------------------------------------------------------------------

HRESULT AScene01( FLOAT fTime )
{
    HRESULT hr = S_OK;

#ifdef PLAY_SCENE01

	static WAVEDATA wdAmbient;
	static WAVEDATA wdWave1;
	static WAVEDATA wdWave2;
	static D3DSURFACE_DESC sdDesc;
	static BOOL bFirstTime = TRUE;
	static FLOAT fStartTime = fTime;	
	static FLOAT fLastTime = 0.0f;
    static BOOL  bDrawWater = TRUE;

	FLOAT fLocalTime = (fTime - TIME_SCENE01);

	FLOAT fTStartText1	= 0.0f;		FLOAT fTEndText1	= 6.0f;		// I am feeling
	FLOAT fTStartText2	= 3.3f;		FLOAT fTEndText2	= 9.3f;		// In a violated form
	FLOAT fTStartText3	= 8.5f;		FLOAT fTEndText3	= 14.0f;	// I can no longer
	FLOAT fTStartText4	= 10.0f;	FLOAT fTEndText4	= 16.0f;	// The things that
	FLOAT fTStartText5	= 15.2f;	FLOAT fTEndText5	= 20.0f;	// I have forsaken them

	FLOAT fTStartText6	= 42.7f;	FLOAT fTEndText6	= 52.0f;	// heed
	FLOAT fTStartText7	= 44.7f;	FLOAT fTEndText7	= 52.5f;	// presents
	FLOAT fTStartText8	= 53.2f;	FLOAT fTEndText8	= 60.0f;	// our first
	FLOAT fTStartText9	= 55.0f;	FLOAT fTEndText9	= 60.5f;	// demo ever

	FLOAT fCameraStart	= 61.0f;
	FLOAT fCameraEnd	= 63.0f;


	FLOAT fText1X1 = 030.0f;	FLOAT fText2X1 = 120.0f;
	FLOAT fText1X2 = 100.0f;	FLOAT fText2X2 = 020.0f;
	FLOAT fText1Y1 = 140.0f;	FLOAT fText2Y1 = 190.0f;
	FLOAT fText1Y2 = 170.0f;	FLOAT fText2Y2 = 250.0f;

	FLOAT fText3X1 = 100.0f;	FLOAT fText4X1 = 150.0f;
	FLOAT fText3X2 = 180.0f;	FLOAT fText4X2 = 080.0f;
	FLOAT fText3Y1 = 150.0f;	FLOAT fText4Y1 = 195.0f;
	FLOAT fText3Y2 = 190.0f;	FLOAT fText4Y2 = 250.0f;

	FLOAT fText5X1 = 200.0f;	
	FLOAT fText5X2 = 250.0f;	
	FLOAT fText5Y1 = 150.0f;
	FLOAT fText5Y2 = 190.0f;	

	
	FLOAT fText6X1 = 150.0f;	FLOAT fText7X1 = 100.0f;	
	FLOAT fText6X2 = 220.0f;	FLOAT fText7X2 = 250.0f;	
	FLOAT fText6Y1 = 150.0f;	FLOAT fText7Y1 = 220.0f;	
	FLOAT fText6Y2 = 190.0f;	FLOAT fText7Y2 = 270.0f;	

	FLOAT fText8X1 = 400.0f;	FLOAT fText9X1 = 380.0f;
	FLOAT fText8X2 = 450.0f;	FLOAT fText9X2 = 500.0f;
	FLOAT fText8Y1 = 170.0f;	FLOAT fText9Y1 = 240.0f;
	FLOAT fText8Y2 = 210.0f;	FLOAT fText9Y2 = 280.0f;

	FRECT frcText = { 0.0f, 0.0f, 512.0f*0.85f, 64.0f*0.85f };
	FRECT frcWater = { 0.0f, 0.0f, 512.0f, 512.0f };

	if ( bFirstTime )
	{
		wdAmbient.bDataIsSet	= FALSE;
		wdAmbient.fPosX			= -100.0f;
		wdAmbient.fPosY			= -100.0f;
		wdAmbient.fRadius		= 300.0f;
        wdAmbient.fWaveWidth    = 100.0f;
		wdAmbient.fStrength		= 0.05f;
		wdAmbient.fTimeStart	= -100.0f;
		wdAmbient.fTimeEnd		= 1000.0f;	// Wave isn't supposed to end

		wdWave1.bDataIsSet	= FALSE;
		wdWave1.fPosX		= 10.0f;
		wdWave1.fPosY		= 10.0f;
		wdWave1.fRadius		= 50.0f;
        wdWave1.fWaveWidth  = 75.0f;
		wdWave1.fStrength	= 0.30f;
		wdWave1.fTimeStart	= fTStartText6;
		wdWave1.fTimeEnd	= fTStartText6+10.0f;

		wdWave2.bDataIsSet	= FALSE;
		wdWave2.fPosX		= -5.0f;
		wdWave2.fPosY		= -5.0f;
		wdWave2.fRadius		= 50.0f;
        wdWave2.fWaveWidth  = 75.0f;
		wdWave2.fStrength	= 0.25f;
		wdWave2.fTimeStart	= fTStartText8;
		wdWave2.fTimeEnd	= fTStartText8+10.0f;

		g_waterPlaneWidth = 100;
		g_waterPlaneHeight = 100;


		ZeroMemory( &g_pointLight, sizeof(D3DLIGHT8) );
		g_pointLight.Type = D3DLIGHT_POINT;
		g_pointLight.Position.x = 0.0f;
		g_pointLight.Position.y = 14.0f;
		g_pointLight.Position.z = 0.0f;
		g_pointLight.Diffuse.r	= 100.0f*4.0f;
		g_pointLight.Diffuse.g	= 100.0f*4.0f;
		g_pointLight.Diffuse.b	= 100.0f*4.0f;
		g_pointLight.Range		= 50.0f;
		g_pointLight.Attenuation0 = 1.0f;
		g_pointLight.Attenuation1 = 1.0f;
		g_pointLight.Attenuation2 = 1.0f;

		g_pd3dDevice->SetLight( 0, &g_pointLight );
		g_pd3dDevice->LightEnable( 0, TRUE );


		g_cam.SetViewParams(D3DXVECTOR3(    0.0f,   5.0f,  -50.0f),
							D3DXVECTOR3(    0.0f,   0.0f,    0.0f),
							D3DXVECTOR3(    0.0f,   1.0f,    0.0f) );

		g_cam.SetProjParams( D3DX_PI/4, g_fAspect, 1.0f, 200.0f );

		// Set world to identity matrix
		g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );
		g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
		g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &g_cam.GetProjMatrix() );

		g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0x00000000 );
		g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
		g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );	

#ifdef PLAYMUSIC 
		FSOUND_PlaySound( FSOUND_FREE, g_psampleMusic );
#endif


		bFirstTime = NULL;
	}


	

	if ( FAILED(hr = SetVB3DPlaneRect( g_pvbWater, g_pibWater, WATER_FVF, D3DXVECTOR3(-50.0f, 0.0f, 50.0f), D3DXVECTOR3(50.0f, 0.0f, -50.0f), WATER_VX, WATER_VY, 255.0f)) )		
		return hr;


	if ( fLocalTime < TIME_SPLASH01 )
	{

		// Constant "natural" waves
		if ( FAILED(hr = DisturbWater(g_pvbWater, g_pibWater, WATER_FVF, &wdAmbient, fLocalTime)) )
			return hr;

		// Drop-in waves
		if ( FAILED(hr = DisturbWater(g_pvbWater, g_pibWater, WATER_FVF, &wdWave1, fLocalTime)) )
			return hr;

		if ( FAILED(hr = DisturbWater(g_pvbWater, g_pibWater, WATER_FVF, &wdWave2, fLocalTime)) )
			return hr;


		if ( fLocalTime >= fCameraStart && fLocalTime < fCameraEnd )
		{
			g_cam.SetViewParams( 
				D3DXVECTOR3(
				0.0f, 
				5.0f + LinearChange( 0.0f, 80.0f, fCameraStart, fLocalTime, fCameraEnd), 
				0.0f + LinearChange( -50.0f, -15.0f, fCameraStart, fLocalTime, fCameraEnd)), 
				D3DXVECTOR3(
				0.0f,
				0.0f + LinearChange( 0.0f, 90.0f, fCameraStart, fLocalTime, fCameraEnd), 
				0.0f),
				g_cam.GetUpVec() );

			g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
		}

		// Fade in scene1
		Fade( D3DCOLOR_ARGB(0xff,0x00,0x00,0x00), D3DCOLOR_ARGB(0xff,0x00,0x00,0x00), 0.0f, fLocalTime, 10.7f );
		Fade( D3DCOLOR_ARGB(0xff,0x00,0x00,0x00), D3DCOLOR_ARGB(0x00,0x00,0x00,0x00), 10.7f, fLocalTime, 21.0f );

		// Fade to scene2
        Fade( D3DCOLOR_ARGB(0x00,0x00,0x00,0x00), D3DCOLOR_ARGB(0xff,0x00,0x00,0x00), 62.75f, fLocalTime, 63.75f );
        Fade( D3DCOLOR_ARGB(0x00,0xff,0xff,0xff), D3DCOLOR_ARGB(0xff,0xff,0xff,0xff), 63.75f, fLocalTime, 64.0f, 1.0f );       
            

		if ( bDrawWater )
		{
			D3DXComputeNormals( g_pmeshWater->GetSysMemMesh() );

			g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0x00000000 );
			g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, TRUE );
			g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, FALSE );
			g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
			g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA );	


			g_pd3dDevice->SetMaterial( &g_stdMtrl );
			g_pd3dDevice->SetLight( LIGHT_POINT, &g_pointLight );
			g_pd3dDevice->LightEnable( LIGHT_POINT, TRUE );

			g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,		D3DTOP_MODULATE );
			g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1,	D3DTA_TEXTURE );
			g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG2,	D3DTA_DIFFUSE );
			g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,		D3DTOP_MODULATE );
			g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1,	D3DTA_TEXTURE );
			g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG2,	D3DTA_DIFFUSE );
			
			g_pd3dDevice->SetTexture( 0, g_ptexWaterEnvmap );
			g_pd3dDevice->SetVertexShader( WATER_FVF );
			g_pd3dDevice->SetStreamSource( 0, g_pvbWater, sizeof(WATER_VERTEX) );
			g_pd3dDevice->SetIndices( g_pibWater, 0 );
			g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );
			g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );

			g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR );
			g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT3 );

			if ( FAILED(hr = g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, WATER_VERTS, 0, WATER_FACES)) )
				return hr;
			
			g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_PASSTHRU );
			g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE );


			g_pd3dDevice->SetTexture( 0, NULL );

			FireFlies( fLocalTime );
		 }
	}

	FLOAT fTextWidth = 800.0f;
	FLOAT fTextHeight = 100.0f;
	FLOAT fTextWidth2 = 400.0f;
	FLOAT fTextHeight2 = 50.0f;

	if ( fLocalTime >= TIME_SPLASH01 )
	{
		SplashScreen1( fLocalTime );

		Fade( D3DCOLOR_ARGB(0xff,0xff,0xff,0xff), D3DCOLOR_ARGB(0x00,0xff,0xff,0xff), 65.0f, fLocalTime,  66.5f );       
		bDrawWater = FALSE;
	}

	// Handle eventual fades (must be done after all drawing, and before text)
	if ( g_bFading )
	{
		FadeRect( g_dwFadeColor, g_rcScreen, TRUE );
	}

	if ( fLocalTime >= fTStartText1 && fLocalTime < fTEndText1 )
	{
		frcText.left = LinearChange( fText1X1, fText1X2, fTStartText1, fLocalTime, fTEndText1 );
		frcText.top  = LinearChange( fText1Y1, fText1Y2, fTStartText1, fLocalTime, fTEndText1 );

		if ( fLocalTime < fTStartText1+1.0f )
			ShowTexture( g_ptexIAmFeeling, frcText.left, frcText.top, fTextWidth, fTextHeight, LinearChange(0.0f, 180.0f, fTStartText1, fLocalTime, fTStartText1+1.0f) );
		else
			ShowTexture( g_ptexIAmFeeling, frcText.left, frcText.top, fTextWidth, fTextHeight, LinearChange(180.0f, 0.0f, fTEndText1-1.0f, fLocalTime, fTEndText1) );
	}


	if ( fLocalTime >= fTStartText2 && fLocalTime < fTEndText2)
	{
		frcText.left = LinearChange( fText2X1, fText2X2, fTStartText2, fLocalTime, fTEndText2 );
		frcText.top  = LinearChange( fText2Y1, fText2Y2, fTStartText2, fLocalTime, fTEndText2 );
		
		if ( fLocalTime < fTStartText2+1.0f )
			ShowTexture( g_ptexInAViolated, frcText.left, frcText.top, fTextWidth, fTextHeight, LinearChange(0.0f, 180.0f, fTStartText2, fLocalTime, fTStartText2+1.0f) );
		else
			ShowTexture( g_ptexInAViolated, frcText.left, frcText.top, fTextWidth, fTextHeight, LinearChange(180.0f, 0.0f, fTEndText2-1.0f, fLocalTime, fTEndText2) );
	}			


	if ( fLocalTime >= fTStartText3 && fLocalTime < fTEndText3)
	{
		frcText.left = LinearChange( fText3X1, fText3X2, fTStartText3, fLocalTime, fTEndText3 );
		frcText.top  = LinearChange( fText3Y1, fText3Y2, fTStartText3, fLocalTime, fTEndText3 );
		
		if ( fLocalTime < fTStartText3+1.0f )
			ShowTexture( g_ptexICanNoLonger, frcText.left, frcText.top, fTextWidth, fTextHeight, LinearChange(0.0f, 180.0f, fTStartText3, fLocalTime, fTStartText3+1.0f) );
		else
			ShowTexture( g_ptexICanNoLonger, frcText.left, frcText.top, fTextWidth, fTextHeight, LinearChange(180.0f, 0.0f, fTEndText3-1.0f, fLocalTime, fTEndText3) );
	}			

	if ( fLocalTime >= fTStartText4 && fLocalTime < fTEndText4)
	{
		frcText.left = LinearChange( fText4X1, fText4X2, fTStartText4, fLocalTime, fTEndText4 );
		frcText.top  = LinearChange( fText4Y1, fText4Y2, fTStartText4, fLocalTime, fTEndText4 );
		
		if ( fLocalTime < fTStartText4+1.0f )
			ShowTexture( g_ptexTheThings, frcText.left, frcText.top, fTextWidth, fTextHeight, LinearChange(0.0f, 180.0f, fTStartText4, fLocalTime, fTStartText4+1.0f) );
		else
			ShowTexture( g_ptexTheThings, frcText.left, frcText.top, fTextWidth, fTextHeight, LinearChange(180.0f, 0.0f, fTEndText4-1.0f, fLocalTime, fTEndText4) );
	}			

	if ( fLocalTime >= fTStartText5 && fLocalTime < fTEndText5)
	{
		frcText.left = LinearChange( fText5X1, fText5X2, fTStartText5, fLocalTime, fTEndText5 );
		frcText.top  = LinearChange( fText5Y1, fText5Y2, fTStartText5, fLocalTime, fTEndText5 );
		
		if ( fLocalTime < fTStartText5+1.0f )
			ShowTexture( g_ptexIHaveForsaken, frcText.left, frcText.top, fTextWidth, fTextHeight, LinearChange(0.0f, 180.0f, fTStartText5, fLocalTime, fTStartText5+1.0f) );
		else
			ShowTexture( g_ptexIHaveForsaken, frcText.left, frcText.top, fTextWidth, fTextHeight, LinearChange(180.0f, 0.0f, fTEndText5-1.0f, fLocalTime, fTEndText5) );
	}			


	if ( fLocalTime >= fTStartText6 && fLocalTime < fTEndText6 )
	{
		frcText.left = LinearChange( fText6X1, fText6X2, fTStartText6, fLocalTime, fTEndText6 );
		frcText.top  = LinearChange( fText6Y1, fText6Y2, fTStartText6, fLocalTime, fTEndText6 );
		
		if ( fLocalTime < fTStartText6+1.0f )
			ShowTexture( g_ptexHeed, frcText.left, frcText.top, fTextWidth2, fTextHeight2, LinearChange(0.0f, 180.0f, fTStartText6, fLocalTime, fTStartText6+1.0f) );
		else
			ShowTexture( g_ptexHeed, frcText.left, frcText.top, fTextWidth2, fTextHeight2, LinearChange(180.0f, 0.0f, fTEndText6-1.0f, fLocalTime, fTEndText6) );
	}			


	if ( fLocalTime >= fTStartText7 && fLocalTime < fTEndText7 )
	{
		frcText.left = LinearChange( fText7X1, fText7X2, fTStartText7, fLocalTime, fTEndText7 );
		frcText.top  = LinearChange( fText7Y1, fText7Y2, fTStartText7, fLocalTime, fTEndText7 );
		
		if ( fLocalTime < fTStartText7+1.0f )
			ShowTexture( g_ptexPresents, frcText.left, frcText.top, fTextWidth2, fTextHeight2, LinearChange(0.0f, 180.0f, fTStartText7, fLocalTime, fTStartText7+1.0f) );
		else
			ShowTexture( g_ptexPresents, frcText.left, frcText.top, fTextWidth2, fTextHeight2, LinearChange(180.0f, 0.0f, fTEndText7-1.0f, fLocalTime, fTEndText7) );
	}			


	if ( fLocalTime >= fTStartText8 && fLocalTime < fTEndText8 )
	{
		frcText.left = LinearChange( fText8X1, fText8X2, fTStartText8, fLocalTime, fTEndText8 );
		frcText.top  = LinearChange( fText8Y1, fText8Y2, fTStartText8, fLocalTime, fTEndText8 );
		
		if ( fLocalTime < fTStartText8+1.0f )
			ShowTexture( g_ptexOurFirst, frcText.left, frcText.top, fTextWidth2, fTextHeight2, LinearChange(0.0f, 180.0f, fTStartText8, fLocalTime, fTStartText8+1.0f) );
		else
			ShowTexture( g_ptexOurFirst, frcText.left, frcText.top, fTextWidth2, fTextHeight2, LinearChange(180.0f, 0.0f, fTEndText8-1.0f, fLocalTime, fTEndText8) );
	}			


	if ( fLocalTime >= fTStartText9 && fLocalTime < fTEndText9 )
	{
		frcText.left = LinearChange( fText9X1, fText9X2, fTStartText9, fLocalTime, fTEndText9 );
		frcText.top  = LinearChange( fText9Y1, fText9Y2, fTStartText9, fLocalTime, fTEndText9 );
		
		if ( fLocalTime < fTStartText9+1.0f )
			ShowTexture( g_ptexDemoEver, frcText.left, frcText.top, fTextWidth2, fTextHeight2, LinearChange(0.0f, 180.0f, fTStartText9, fLocalTime, fTStartText9+1.0f) );
		else
			ShowTexture( g_ptexDemoEver, frcText.left, frcText.top, fTextWidth2, fTextHeight2, LinearChange(180.0f, 0.0f, fTEndText9-1.0f, fLocalTime, fTEndText9) );
	}			

	
	fLastTime = fLocalTime;
#endif // PLAY_SCENE01
	
	return hr;
}



//-----------------------------------------------------------------------------
// Name: AScene02()
// Desc: 
//-----------------------------------------------------------------------------

HRESULT AScene02( FLOAT fTime )
{
	HRESULT hr = S_OK;
	
#ifdef PLAY_SCENE02
	static BOOL bFirstTime = TRUE;
	static FLOAT fStartTime = fTime;
	FLOAT fLocalTime = (fTime - TIME_SCENE02);
	INT iNumWaypoints = 0;
	
	if ( bFirstTime )
	{
		g_cam.SetViewParams(D3DXVECTOR3(    0.0f,  10.0f,  -50.0f),
							D3DXVECTOR3(    0.0f,   0.0f,    0.0f),
							D3DXVECTOR3(    0.0f,   1.0f,    0.0f) );

		g_cam.SetProjParams( D3DX_PI/4, g_fAspect, 1.0f, 200.0f );

		FLOAT fFogStart = 0.0f;
		FLOAT fFogEnd	= TUNNEL_LENGTH*1.0f;
		FLOAT fDensity	= 1.0f;

		// Set world to identity matrix
		g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );
		g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
		g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &g_cam.GetProjMatrix() );

		g_pd3dDevice->LightEnable( LIGHT_POINT, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
		g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		
		g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_FOGCOLOR, 0xff000000 );
		g_pd3dDevice->SetRenderState( D3DRS_FOGVERTEXMODE, D3DFOG_LINEAR );
		g_pd3dDevice->SetRenderState( D3DRS_FOGSTART,	*(DWORD *)(&fFogStart) );
		g_pd3dDevice->SetRenderState( D3DRS_FOGEND,		*(DWORD *)(&fFogEnd) );
		g_pd3dDevice->SetRenderState( D3DRS_FOGDENSITY, *(DWORD *)(&fDensity) );

		g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW );
		g_pd3dDevice->SetRenderState( D3DRS_FILLMODE, GLOBAL_FILLMODE );	
		bFirstTime = FALSE;
	}

	
	if ( FAILED(hr = g_tunnel.Animate(fLocalTime)) )
		return hr;
	if ( FAILED(hr = g_tunnel.Render()) )
		return hr;
	if ( FAILED(hr = g_tunnel.Overlay(fLocalTime)) )
		return hr;

	Fade( D3DCOLOR_ARGB(0x00,0x00,0x00,0x00), D3DCOLOR_ARGB(0xff,0x00,0x00,0x00), TIME_SCENE03-0.5f, g_fDTime, TIME_SCENE03 ); 

	// Handle eventual fades (must be done after all drawing, and before text)
	if ( g_bFading )
		FadeRect( g_dwFadeColor, g_rcScreen, TRUE );

#endif	// PLAY_SCENE02
	return hr;
}





//-----------------------------------------------------------------------------
// Name: AScene03()
// Desc: 
//-----------------------------------------------------------------------------

HRESULT AScene03( FLOAT fTime )
{
	HRESULT hr = S_OK;

#ifdef PLAY_SCENE03

	static BOOL bFirstTime = TRUE;
	static FLOAT fStartTime = fTime;
	FLOAT fLocalTime = (fTime - TIME_SCENE03);

	if ( bFirstTime )
	{
		g_cam.SetViewParams(D3DXVECTOR3(   75.0f, 150.0f, -350.0f),
							D3DXVECTOR3(    0.0f,   0.0f,    0.0f),
							D3DXVECTOR3(    0.0f,   1.0f,   0.0f) );

		g_cam.SetProjParams( D3DX_PI/4, g_fAspect, 1.0f, GRID_DEPTH );

		// Set world to identity matrix
		g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );
		g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
		g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &g_cam.GetProjMatrix() );

		g_pd3dDevice->LightEnable( LIGHT_DIRECTIONAL, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
		g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );
		
		g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_FILLMODE, GLOBAL_FILLMODE );	

		bFirstTime = FALSE;
	}

    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_SELECTARG1 );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSU,  D3DTADDRESS_WRAP );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSV,  D3DTADDRESS_WRAP );


	// Fog parameters
	FLOAT fFogStart = 0.0f;
	FLOAT fFogEnd	= GRID_DEPTH/2;
	FLOAT fDensity	= 0.005f;
	
	g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_FOGCOLOR, 0xff000000 );
	g_pd3dDevice->SetRenderState( D3DRS_FOGVERTEXMODE, D3DFOG_LINEAR );
	g_pd3dDevice->SetRenderState( D3DRS_FOGSTART,	*(DWORD *)(&fFogStart) );
	g_pd3dDevice->SetRenderState( D3DRS_FOGEND,		*(DWORD *)(&fFogEnd) );
	g_pd3dDevice->SetRenderState( D3DRS_FOGDENSITY, *(DWORD *)(&fDensity) );


	g_textScene.Animate( fLocalTime );
	g_textScene.Render();
	g_textScene.Overlay( fLocalTime );

	g_pd3dDevice->SetTexture( 0, NULL );

#endif	// PLAY_SCENE03
	return hr;
}



//-----------------------------------------------------------------------------
// Name: AScene04()
// Desc: 
//-----------------------------------------------------------------------------

HRESULT AScene04( FLOAT fTime )
{
	HRESULT hr = S_OK;
	
#ifdef PLAY_SCENE04

	static BOOL bFirstTime = TRUE;
	static FLOAT fStartTime = fTime;
	FLOAT fLocalTime = (fTime - TIME_SCENE04);


	if ( bFirstTime )
	{
//		g_metaBall.GenerateMetaMesh( fTime );
		
		g_cam.SetViewParams(D3DXVECTOR3(0.0f,   0.0f,  150.0f),
							D3DXVECTOR3(0.0f,   0.0f,    0.0f),
							D3DXVECTOR3(0.0f,   1.0f,    0.0f) );

		g_cam.SetProjParams( D3DX_PI/4, g_fAspect, 1.0f, 500.0f );


		// Set world to identity matrix
		g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );
		g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
		g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &g_cam.GetProjMatrix() );

		g_pd3dDevice->LightEnable( LIGHT_DIRECTIONAL, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xff5f5f5f );
		g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW );
		g_pd3dDevice->SetRenderState( D3DRS_FILLMODE, GLOBAL_FILLMODE );	

		bFirstTime = FALSE;
	}

    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_MODULATE );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSU,  D3DTADDRESS_WRAP );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSV,  D3DTADDRESS_WRAP );


	g_metaBall.Animate( fLocalTime );
	g_metaBall.Render();
	g_metaBall.Overlay( fLocalTime );
	g_pd3dDevice->SetTexture( 0, NULL );

	Fade( D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(0, 255, 255, 255), TIME_SCENE04, g_fDTime, TIME_SCENE04+0.5f );

	// Handle eventual fades (must be done after all drawing, and before text)
	if ( g_bFading )
		FadeRect( g_dwFadeColor, g_rcScreen, TRUE );

#endif	// PLAY_SCENE04
	return hr;
}




//-----------------------------------------------------------------------------
// Name: AScene05()
// Desc: 
//-----------------------------------------------------------------------------

HRESULT AScene05( FLOAT fTime )
{
	HRESULT hr = S_OK;
	
#ifdef PLAY_SCENE05

	static BOOL bFirstTime = TRUE;
	static FLOAT fStartTime = fTime;
	FLOAT fLocalTime = (fTime - TIME_SCENE05);
	
	if ( bFirstTime )
	{
		g_cam.SetViewParams(D3DXVECTOR3(    0.0f,  10.0f,  -50.0f),
							D3DXVECTOR3(    0.0f,   0.0f,    0.0f),
							D3DXVECTOR3(    0.0f,   1.0f,    0.0f) );

		g_cam.SetProjParams( D3DX_PI/4.0f, g_fAspect, 1.0f, 200.0f );

		FLOAT fFogStart = 0.0f;
		FLOAT fFogEnd	= TUNNEL2_LENGTH*1.0f;
		FLOAT fDensity	= 1.0f;

		// Set world to identity matrix
		g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );
		g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
		g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &g_cam.GetProjMatrix() );

		g_pd3dDevice->LightEnable( LIGHT_DIRECTIONAL, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
		g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		
		g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_FOGCOLOR, 0xff000000 );
		g_pd3dDevice->SetRenderState( D3DRS_FOGVERTEXMODE, D3DFOG_LINEAR );
		g_pd3dDevice->SetRenderState( D3DRS_FOGSTART,	*(DWORD *)(&fFogStart) );
		g_pd3dDevice->SetRenderState( D3DRS_FOGEND,		*(DWORD *)(&fFogEnd) );
		g_pd3dDevice->SetRenderState( D3DRS_FOGDENSITY, *(DWORD *)(&fDensity) );

		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSU,  D3DTADDRESS_WRAP );
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSV,  D3DTADDRESS_WRAP );

#ifdef PLAYMUSIC 
		//FSOUND_PlaySound( FSOUND_FREE, g_psampleMusic );
#endif

#ifdef PLAYMUSIC
		FSOUND_DSP_SetActive(FSOUND_DSP_GetFFTUnit(), TRUE);
#endif
		
		g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW );
		g_pd3dDevice->SetRenderState( D3DRS_FILLMODE, GLOBAL_FILLMODE );
		bFirstTime = FALSE;
	}

	if ( FAILED(hr = g_tunnel2.Animate( fLocalTime)) )
		return hr;
	if ( FAILED(hr = g_tunnel2.Render()) )
		return hr;
	if ( FAILED(hr = g_bParticles.Render()) )
		return hr;
	if ( FAILED(hr = g_tunnel2.Overlay(fLocalTime)) )
		return hr;



	Fade( D3DCOLOR_ARGB(0x00,0x00,0x00,0x00), D3DCOLOR_ARGB(0xff,0x00,0x00,0x00), TIME_SCENE06-1.5f, g_fDTime, TIME_SCENE06 );

	// Handle eventual fades (must be done after all drawing, and before text)
	if ( g_bFading )
		FadeRect( g_dwFadeColor, g_rcScreen, TRUE );

#endif	// PLAY_SCENE05
	return hr;
}


//-----------------------------------------------------------------------------
// Name: AScene06()
// Desc: 
//-----------------------------------------------------------------------------

HRESULT AScene06( FLOAT fTime )
{
	HRESULT hr = S_OK;

#ifdef PLAY_SCENE06

	static BOOL bFirstTime = TRUE;
	static FLOAT fStartTime = fTime;
	FLOAT fLocalTime = (fTime - TIME_SCENE06);

	if ( bFirstTime )
	{
		g_cam.SetViewParams(D3DXVECTOR3(    0.0f,  50.0f,  -50.0f),
							D3DXVECTOR3(    0.0f,   0.0f,    0.0f),
							D3DXVECTOR3(    0.0f,   1.0f,    0.0f) );

		g_cam.SetProjParams( D3DX_PI/4, g_fAspect, 1.0f, 500.0f );

		// Set world to identity matrix
		g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );
		g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
		g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &g_cam.GetProjMatrix() );

		g_pd3dDevice->LightEnable( LIGHT_DIRECTIONAL, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
		g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW );
		
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_MODULATE );
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_DIFFUSE );
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,   D3DTOP_MODULATE );
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE );
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1, D3DTA_DIFFUSE );

		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSU,  D3DTADDRESS_WRAP );
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSV,  D3DTADDRESS_WRAP );

		g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_FILLMODE, GLOBAL_FILLMODE );	

		g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
		g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA );	

		bFirstTime = FALSE;
	}

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_PASSTHRU );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE );

	SplashScreen2( fLocalTime );

	Fade( D3DCOLOR_ARGB(0xff,0x00,0x00,0x00), D3DCOLOR_ARGB(0x00,0x00,0x00,0x00), 0.0f, fLocalTime, 2.0f );
	Fade( D3DCOLOR_ARGB(0x00,0xff,0xff,0xff), D3DCOLOR_ARGB(0xff,0xff,0xff,0xff), TIME_SCENE07-0.10f, g_fDTime, TIME_SCENE07 );

	// Handle eventual fades (must be done after all drawing, and before text)
	if ( g_bFading )
		FadeRect( g_dwFadeColor, g_rcScreen, TRUE );


#endif // PLAY_SCENE06

	return hr;
}


//-----------------------------------------------------------------------------
// Name: AScene07()
// Desc: 
//-----------------------------------------------------------------------------

HRESULT AScene07( FLOAT fTime )
{
	HRESULT hr = S_OK;

#ifdef PLAY_SCENE07

	static BOOL bFirstTime = TRUE;
	static FLOAT fStartTime = fTime;
	FLOAT fLocalTime = (fTime - TIME_SCENE07);

	if ( bFirstTime )
	{
		g_cam.SetViewParams(	D3DXVECTOR3(    0.0f,  50.0f,  -50.0f),
							D3DXVECTOR3(    0.0f,   0.0f,    0.0f),
							D3DXVECTOR3(    0.0f,   1.0f,    0.0f) );

		g_cam.SetProjParams( D3DX_PI/4, g_fAspect, 1.0f, 500.0f );

		// Set world to identity matrix
		g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );
		g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
		g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &g_cam.GetProjMatrix() );

		g_pd3dDevice->LightEnable( LIGHT_DIRECTIONAL, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
		g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		
		g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_FILLMODE, GLOBAL_FILLMODE );	
		

		bFirstTime = FALSE;
	}

    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_SELECTARG1 );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSU,  D3DTADDRESS_WRAP );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSV,  D3DTADDRESS_WRAP );


	if ( g_fDTime-TIME_SCENE01 < 180.0f + 38.8f )
	{
		ShowTexture( g_ptexCredit1, 0.0f, 0.0f, g_fWindowX, g_fWindowY );
	}
	if ( g_fDTime-TIME_SCENE01 >= 180.0f + 38.8f && g_fDTime-TIME_SCENE01 < 180.0f + 44.0f )
	{
		ShowTexture( g_ptexCredit2, 0.0f, 0.0f, g_fWindowX, g_fWindowY );
	}
	if ( g_fDTime-TIME_SCENE01 >= 180.0f + 44.0f && g_fDTime-TIME_SCENE01 < 180.0f + 49.5f )
	{
		ShowTexture( g_ptexCredit3, 0.0f, 0.0f, g_fWindowX, g_fWindowY );
	}
	if ( g_fDTime-TIME_SCENE01 >= 180.0f + 49.3f )
	{
		ShowTexture( g_ptexHello, 0.0f, 0.0f, g_fWindowX, g_fWindowY );
	}


	Fade( D3DCOLOR_ARGB(0x00,0xff,0xff,0xff), D3DCOLOR_ARGB(0xff,0xff,0xff,0xff), TIME_SCENE07, g_fDTime, TIME_SCENE07+0.1f );
	Fade( D3DCOLOR_ARGB(0xff,0xff,0xff,0xff), D3DCOLOR_ARGB(0x00,0xff,0xff,0xff), TIME_SCENE07+0.1f, g_fDTime, TIME_SCENE07+0.2f );
	
	Fade( D3DCOLOR_ARGB(0x00,0xff,0xff,0xff), D3DCOLOR_ARGB(0xff,0xff,0xff,0xff), 180.0f + 38.8f, g_fDTime-TIME_SCENE01, 180.0f + 38.8f + 0.1f );
	Fade( D3DCOLOR_ARGB(0xff,0xff,0xff,0xff), D3DCOLOR_ARGB(0x00,0xff,0xff,0xff), 180.0f + 38.8f + 0.1f, g_fDTime-TIME_SCENE01, 180.0f + 38.8f + 0.2f );

	Fade( D3DCOLOR_ARGB(0x00,0xff,0xff,0xff), D3DCOLOR_ARGB(0xff,0xff,0xff,0xff), 180.0f + 44.0f, g_fDTime-TIME_SCENE01, 180.0f + 44.0f + 0.1f );
	Fade( D3DCOLOR_ARGB(0xff,0xff,0xff,0xff), D3DCOLOR_ARGB(0x00,0xff,0xff,0xff), 180.0f + 44.0f + 0.1f, g_fDTime-TIME_SCENE01, 180.0f + 44.0f + 0.2f );

	// Handle eventual fades (must be done after all drawing, and before text)
	if ( g_bFading )
		FadeRect( g_dwFadeColor, g_rcScreen, TRUE );


#endif // PLAY_SCENE07

	return hr;
}



//-----------------------------------------------------------------------------
// Name: AScene08()
// Desc: 
//-----------------------------------------------------------------------------

HRESULT AScene08( FLOAT fTime )
{
	HRESULT hr = S_OK;

#ifdef PLAY_SCENE08

	static BOOL bFirstTime = TRUE;
	static FLOAT fStartTime = fTime;
	FLOAT fLocalTime = (fTime - TIME_SCENE08);

	if ( bFirstTime )
	{
		g_cam.SetViewParams(D3DXVECTOR3(    0.0f,  50.0f,  -100.0f),
							D3DXVECTOR3(    0.0f,   0.0f,    0.0f),
							D3DXVECTOR3(    0.0f,   1.0f,    0.0f) );

		g_cam.SetProjParams( D3DX_PI/4, g_fAspect, 1.0f, 500.0f );

		// Set world to identity matrix
		g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );
		g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
		g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &g_cam.GetProjMatrix() );

		g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW );
		g_pd3dDevice->LightEnable( LIGHT_DIRECTIONAL, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
		g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		
		g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_FILLMODE, GLOBAL_FILLMODE );	

		g_dwBackgroundColor = D3DCOLOR_ARGB(0xff,0xff,0xff,0xff);

		bFirstTime = FALSE;
	}

    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_SELECTARG1 );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSU,  D3DTADDRESS_WRAP );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSV,  D3DTADDRESS_WRAP );

    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_SELECTARG1 );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSU,  D3DTADDRESS_MIRROR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSV,  D3DTADDRESS_MIRROR );

	g_scene08.Animate( fLocalTime );
	g_scene08.Render();

	RECT rc1 = { 0, 0, (INT)g_fWindowX, 170 };
	RECT rc2 = { 0, (INT)g_fWindowY-170, (INT)g_fWindowX, (INT)g_fWindowY };
	FadeRect( 0xff000000, rc1, TRUE, TRUE );
	FadeRect( 0xff000000, rc2, TRUE, TRUE );

#endif // PLAY_SCENE08

	return hr;
}



//-----------------------------------------------------------------------------
// Name: AScene09()
// Desc: 
//-----------------------------------------------------------------------------

HRESULT AScene09( FLOAT fTime )
{
	HRESULT hr = S_OK;

#ifdef PLAY_SCENE09

	static BOOL bFirstTime = TRUE;
	static FLOAT fStartTime = fTime;
	FLOAT fLocalTime = (fTime - TIME_SCENE09);

	if ( bFirstTime )
	{
		g_cam.SetViewParams(D3DXVECTOR3(    0.0f,  50.0f,  -100.0f),
							D3DXVECTOR3(    0.0f,   0.0f,    0.0f),
							D3DXVECTOR3(    0.0f,   1.0f,    0.0f) );

		g_cam.SetProjParams( D3DX_PI/4, g_fAspect, 1.0f, 500.0f );

		// Set world to identity matrix
		g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );
		g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
		g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &g_cam.GetProjMatrix() );

		g_pd3dDevice->LightEnable( LIGHT_DIRECTIONAL, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
		g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		
		g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_FILLMODE, GLOBAL_FILLMODE );	

		g_dwBackgroundColor = D3DCOLOR_ARGB(0xff,0xff,0xff,0xff);
		
		bFirstTime = FALSE;
	}

    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_SELECTARG1 );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSU,  D3DTADDRESS_WRAP );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSV,  D3DTADDRESS_WRAP );

    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_SELECTARG1 );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSU,  D3DTADDRESS_MIRROR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSV,  D3DTADDRESS_MIRROR );

	g_scene08.Animate( fLocalTime );
	g_scene08.Render();
	Scene09Overlay( fLocalTime );

	RECT rc1 = { 0, 0, (INT)g_fWindowX, 170 };
	RECT rc2 = { 0, (INT)g_fWindowY-170, (INT)g_fWindowX, (INT)g_fWindowY };
	FadeRect( 0xff000000, rc1, TRUE, TRUE );
	FadeRect( 0xff000000, rc2, TRUE, TRUE );

	Fade( D3DCOLOR_ARGB(0x00,0xff,0xff,0xff), D3DCOLOR_ARGB(0xff,0xff,0xff,0xff), TIME_SCENE10-3.0f, g_fDTime, TIME_SCENE10 );

	// Handle eventual fades (must be done after all drawing, and before text)
	if ( g_bFading )
		FadeRect( g_dwFadeColor, g_rcScreen, TRUE );


#endif // PLAY_SCENE09

	return hr;
}



//-----------------------------------------------------------------------------
// Name: AScene10()
// Desc: 
//-----------------------------------------------------------------------------

HRESULT AScene10( FLOAT fTime )
{
	HRESULT hr = S_OK;

#ifdef PLAY_SCENE10

	static BOOL bFirstTime = TRUE;
	static FLOAT fStartTime = fTime;
	FLOAT fLocalTime = (fTime - TIME_SCENE10);

	if ( bFirstTime )
	{
		g_cam.SetViewParams(D3DXVECTOR3(    0.0f,   0.0f,    0.0f),
							D3DXVECTOR3(    0.0f,   0.0f,    1.0f),
							D3DXVECTOR3(    0.0f,   1.0f,    0.0f) );

		g_cam.SetProjParams( D3DX_PI/4, g_fAspect, 1.0f, 500.0f );

		// Set world to identity matrix
		g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );
		g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
		g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &g_cam.GetProjMatrix() );

		g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW );
		g_pd3dDevice->LightEnable( LIGHT_DIRECTIONAL, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
		g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		
		g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, FALSE );
		g_pd3dDevice->SetRenderState( D3DRS_FILLMODE, GLOBAL_FILLMODE );	

		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_PASSTHRU );
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE );

		g_dwBackgroundColor = D3DCOLOR_ARGB(0xff,0x00,0x00,0x00);

		bFirstTime = FALSE;
	}

    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_SELECTARG1 );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSU,  D3DTADDRESS_WRAP );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSV,  D3DTADDRESS_WRAP );

    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_SELECTARG1 );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSU,  D3DTADDRESS_MIRROR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSV,  D3DTADDRESS_MIRROR );

	g_scene10.Animate( fLocalTime );
	g_scene10.Render();


#endif // PLAY_SCENE10

	return hr;
}



//-----------------------------------------------------------------------------
// Name: Animate()
// Desc: Handles animation of text in the scene
//-----------------------------------------------------------------------------

HRESULT CTextGrid::Animate( FLOAT fLocalTime )
{
	HRESULT hr = S_OK;
	FLOAT fMinMove = -GRID_WIDTH*0.5f;
	FLOAT fMaxMove = -GRID_WIDTH*0.75f;
	static FLOAT camPrevX = 0.0f;
	static FLOAT camPrevY = 0.0f;
	static FLOAT camPrevZ = 0.0f;
	static FLOAT camTargetX = fMaxMove*0.85f;//RandRange( fMinMove, fMaxMove );
	static FLOAT camTargetY = fMaxMove*0.95f;//RandRange( fMinMove, fMaxMove );
	static FLOAT camTargetZ = fMaxMove*0.75f;//RandRange( fMinMove, fMaxMove );
	static FLOAT fTargetTime = GRID_MOVETIME;
	static FLOAT fStartTime = 0.0f;


	g_cam.SetViewParams(	D3DXVECTOR3(LinearChange( camPrevX, camTargetX, fStartTime, fLocalTime, fTargetTime ), 
										LinearChange( camPrevY, camTargetY, fStartTime, fLocalTime, fTargetTime ), 
										LinearChange( camPrevZ, camTargetZ, fStartTime, fLocalTime, fTargetTime ) ),
							D3DXVECTOR3(    -80000.0f,  -80000.0f,   -60000.0f),
							D3DXVECTOR3(       0.0f,     1.0f,      0.0f) );

	D3DXMATRIX matRot;
	D3DXMatrixRotationYawPitchRoll( &matRot, fLocalTime/3.0f, fLocalTime/3.0f, fLocalTime/3.0f );
	D3DXMatrixMultiply( &matRot, &g_cam.GetViewMatrix(), &matRot );
	g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
	g_pd3dDevice->SetTransform( D3DTS_VIEW, &matRot );

	if ( fLocalTime	>= fTargetTime )
	{
		camPrevX = camTargetX;
		camPrevY = camTargetY;
		camPrevZ = camTargetZ;

		camTargetX = camTargetX + fMaxMove*0.85f;//RandRange( fMinMove, fMaxMove );
		camTargetY = camTargetY + fMinMove*0.95f;//RandRange( fMinMove, fMaxMove );
		camTargetZ = camTargetZ + fMaxMove*0.75f;//RandRange( fMinMove, fMaxMove );
		fTargetTime += GRID_MOVETIME;
		fStartTime += GRID_MOVETIME;
	}


	D3DXVECTOR3 vPos;
	vPos = g_cam.GetEyePt();

	INT iNewCubeX = (INT)(vPos.x / GRID_SPACE_X);
	INT iNewCubeY = (INT)(vPos.y / GRID_SPACE_Y);
	INT iNewCubeZ = (INT)(vPos.z / GRID_SPACE_Z);

	BOOL bUpdateGrid = FALSE;

	if ( iNewCubeX != m_iCubeX )
	{
		m_iCubeX = iNewCubeX;
		bUpdateGrid = TRUE;
	}
	if ( iNewCubeY != m_iCubeY )
	{
		m_iCubeY = iNewCubeY;
		bUpdateGrid = TRUE;
	}
	if ( iNewCubeZ != m_iCubeZ )
	{
		m_iCubeZ = iNewCubeZ;
		bUpdateGrid = TRUE;
	}
	
	ScrollText( 0.003f );	

	if ( bUpdateGrid )
	{
		GenerateGrid( m_iCubeX, m_iCubeY, m_iCubeZ );	// Generate grid in the direction that camera has moved		
	}

	//SortGrid();


	return hr;
}



//-----------------------------------------------------------------------------
// Name: CTextGrid()
// Desc: 
//-----------------------------------------------------------------------------

CTextGrid::CTextGrid()
{
	ZeroMemory( &m_light, sizeof(D3DLIGHT8) );
	m_ptexText1			= NULL;
	m_ptexOverlay		= NULL;
	m_ptexOverlayText	= NULL;
	
	m_pVB			= NULL;
	m_pIB			= NULL;

	m_iCubeX = 0;
	m_iCubeY = 0;
	m_iCubeZ = 0;
	m_fScrollOffsetX = 0.0f;
	m_fScrollOffsetY = 0.0f;
	m_fScrollOffsetZ = 0.0f;
}



//-----------------------------------------------------------------------------
// Name: GenerateGrid()
// Desc: Generates the vertexbuffer used for the grid.
//-----------------------------------------------------------------------------

HRESULT CTextGrid::GenerateGrid( INT iCubeX, INT iCubeY, INT iCubeZ )
{
	HRESULT hr = S_OK;

	GRID_VERTEX* pVertices;
	if ( FAILED(hr = m_pVB->Lock(0, NULL, (BYTE**)&pVertices, NULL)) )
		return hr;

	GRID_VERTEX vBuffer[4];
	ZeroMemory( vBuffer, sizeof(vBuffer) );

	// Initialize vertexbuffer for the textgrid
	D3DXVECTOR3 v1; 
	D3DXVECTOR3 v2;
	INT x, y, z;
	INT iVert=0;

	// Left of cube (YZ-X)
	for ( y=0; y<GRID_LINES_Y-1; y++ )
	{
		for ( z=0; z<GRID_LINES_Z-1; z++ )
		{
			v1.x = GRID_SEG_LENGTH*0.2f + (iCubeX*GRID_SPACE_X) - GRID_WIDTH/2;		// Use this vertex as v1
			v1.y = GRID_SEG_LENGTH*0.2f + (y+iCubeY)*GRID_SPACE_Y - GRID_HEIGHT/2;	
			v1.z = GRID_SEG_LENGTH*0.2f + (z+iCubeZ)*GRID_SPACE_Z - GRID_DEPTH/2;

			v2.x = GRID_SEG_LENGTH*0.2f + (iCubeX*GRID_SPACE_X) + (GRID_WIDTH / 2);		// v2 in the x-direction
			v2.y = v1.y;	
			v2.z = v1.z;

			FLOAT fTUOffset = ((FLOAT)iCubeX*(GRID_SPACE_Y/GRID_HEIGHT));

			SetGridQuad( vBuffer, v1, v2, ALPHA_FULL, GRID_TILES, fTUOffset + m_fScrollOffsetX );
			memcpy( pVertices+iVert, vBuffer, sizeof(vBuffer) );
			iVert += 4;
		}
	}

	// Bottom of cube (XZ-Y)
	for ( x=0; x<GRID_LINES_X-1; x++ )	// Don't handle the vertices at the start-edges of the cube (since quads will use current vertex -> next vertex to create quad)
	{
		for ( z=0; z<GRID_LINES_Z-1; z++ )
		{
			v1.x = (x+iCubeX)*GRID_SPACE_X - GRID_WIDTH/2;		// Use this vertex as v1
			v1.y = (iCubeY*GRID_SPACE_Y) - GRID_HEIGHT/2;	
			v1.z = (z+iCubeZ)*GRID_SPACE_Z - GRID_DEPTH/2;

			v2.x = v1.x;		// v2 in the x-direction
			v2.y = (iCubeY*GRID_SPACE_Y) + (GRID_HEIGHT / 2);	
			v2.z = v1.z;

			FLOAT fTUOffset = ((FLOAT)iCubeY*(GRID_SPACE_Z/GRID_DEPTH));

			SetGridQuad( vBuffer, v1, v2, ALPHA_FULL, GRID_TILES, fTUOffset + m_fScrollOffsetY );
			memcpy( pVertices+iVert, vBuffer, sizeof(vBuffer) );
			iVert += 4;
		}
	}


	// Front of cube (XY-Z)
	for ( x=0; x<GRID_LINES_X-1; x++ )
	{
		for ( y=0; y<GRID_LINES_Y-1; y++ )
		{
			v1.x = -GRID_SEG_LENGTH*0.2f + (x+iCubeX)*GRID_SPACE_X - GRID_WIDTH/2;		// Use this vertex as v1
			v1.y = -GRID_SEG_LENGTH*0.2f + (y+iCubeY)*GRID_SPACE_Y - GRID_HEIGHT/2;	
			v1.z = -GRID_SEG_LENGTH*0.2f + (iCubeZ*GRID_SPACE_Z) - GRID_DEPTH/2;

			v2.x = v1.x;		// v2 in the x-direction
			v2.y = v1.y;	
			v2.z = -GRID_SEG_LENGTH*0.2f + (iCubeZ*GRID_SPACE_Z) + (GRID_DEPTH / 2);


			FLOAT fTUOffset = ((FLOAT)iCubeZ*(GRID_SPACE_X/GRID_WIDTH));

			SetGridQuad( vBuffer, v1, v2, ALPHA_FULL, GRID_TILES, fTUOffset + m_fScrollOffsetZ );
			memcpy( pVertices+iVert, vBuffer, sizeof(vBuffer) );
			iVert += 4;
		}
	}


	m_pVB->Unlock();

	return hr;
}



//-----------------------------------------------------------------------------
// Name: InitDeviceObjects()
// Desc: Restores all devicedependent resources used by this class.
//-----------------------------------------------------------------------------

HRESULT CTextGrid::InitDeviceObjects()
{
	HRESULT hr = S_OK;

#ifdef PLAY_SCENE03
	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene03\\sentence.png", &m_ptexText1 )) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}		

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene03\\scene4overlay.png", &m_ptexOverlay )) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}			

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, "data\\bitmaps\\scene03\\textscroll.png", &m_ptexOverlayText )) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}			

	if ( FAILED(hr = g_pd3dDevice->CreateVertexBuffer( GRID_VERTS*sizeof(GRID_VERTEX), 0, GRID_FVF, D3DPOOL_MANAGED, &m_pVB)) )	// Set up a quad for each linesegment
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	if ( FAILED(hr = g_pd3dDevice->CreateIndexBuffer( GRID_INDICES*sizeof(WORD), NULL, D3DFMT_INDEX16, D3DPOOL_MANAGED, &m_pIB )) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}


	GenerateGrid( NULL, NULL, NULL );


#endif	// PLAY_SCENE03
	return hr;
}



//-----------------------------------------------------------------------------
// Name: InvalidateDeviceObjects()
// Desc: Deallocates and releases any devicedependent resources.
//-----------------------------------------------------------------------------

HRESULT CTextGrid::InvalidateDeviceObjects()
{
	HRESULT hr = S_OK;

	SAFE_RELEASE( m_ptexText1 );
	SAFE_RELEASE( m_pVB );
	SAFE_RELEASE( m_pIB );
	SAFE_RELEASE( m_ptexOverlay );
	SAFE_RELEASE( m_ptexOverlayText );

	return hr;
}



//-----------------------------------------------------------------------------
// Name: Overlay()
// Desc: Handles all overlay effects in text scene
//-----------------------------------------------------------------------------

	HRESULT CTextGrid::Overlay( FLOAT fLocalTime )
{
	HRESULT hr = S_OK;

	FLOAT fWidth = g_fWindowX / 4.0f;
	FLOAT fOffsetX = g_fWindowX - fWidth;
	
	D3DCOLOR vcol[4] = 
	{
		0x00ffffff,
		0xffffffff,
		0x80ffffff,
		0x00ffffff		
	};

	FRECT frc1 = { 0.0f, 0.0f, 0.0f, 0.0f };
	ShowTextureEx( m_ptexOverlay, frc1, vcol, fOffsetX, 0.0f, fWidth, g_fWindowY, 255.0f );
	ShowTextureExTile( m_ptexOverlayText, vcol, fOffsetX, 0.0f, fWidth, g_fWindowY, 2.0f, 1.5f, 0.0f, fLocalTime/4.0f, 255.0f );

	return hr;
}


//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Renders the text in the scene.
//-----------------------------------------------------------------------------

HRESULT CTextGrid::Render()
{
	HRESULT hr = S_OK;
	
	g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );
	
	//g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
	g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &g_cam.GetProjMatrix() );

	g_pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
	g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );	

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,		D3DTOP_MODULATE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1,	D3DTA_TEXTURE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG2,	D3DTA_DIFFUSE );

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,		D3DTOP_MODULATE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1,	D3DTA_TEXTURE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG2,	D3DTA_DIFFUSE );

	g_pd3dDevice->SetTexture( 0, m_ptexText1 );
	g_pd3dDevice->SetVertexShader( GRID_FVF );
	g_pd3dDevice->SetStreamSource( 0, m_pVB, sizeof(GRID_VERTEX) );

	g_pd3dDevice->SetRenderState( D3DRS_ZWRITEENABLE, FALSE );

	
	for ( INT v=0; v<(GRID_LINES-1)*4; v+=4 )
	{
		if ( FAILED(hr = g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN, v, 2)) )
			return hr;
	}

	g_pd3dDevice->SetRenderState( D3DRS_ZWRITEENABLE, TRUE );
	g_pd3dDevice->SetTexture( 0, NULL );
	return hr;
}



//-----------------------------------------------------------------------------
// Name: ScrollText()
// Desc: Manipulates the texcoords of the text quads so that the text scrolls.
//-----------------------------------------------------------------------------

HRESULT CTextGrid::ScrollText( FLOAT fSpeed )
{
    HRESULT hr = S_OK;

	GRID_VERTEX* pVertex;
	GRID_VERTEX* pVertices;

	if ( FAILED(hr = m_pVB->Lock(0, NULL, (BYTE**)&pVertices, NULL)) )
		return hr;

	FLOAT fSpeedX = -fSpeed*1.0f;
	FLOAT fSpeedY = -fSpeed*1.2f;
	FLOAT fSpeedZ = -fSpeed*2.5f;

	m_fScrollOffsetX += fSpeedX;
	m_fScrollOffsetY += fSpeedY;
	m_fScrollOffsetZ += fSpeedZ;
	
	INT iVert=0;
	for ( INT v=0; v<GRID_LINES_Y*GRID_LINES_Z*4; v++ )
	{
		pVertex = pVertices+iVert;
		pVertex->tu += fSpeedX;

		iVert++;
	}

	for ( v=0; v<GRID_LINES_X*GRID_LINES_Z*4; v++ )
	{
		pVertex = pVertices+iVert;
		pVertex->tu += fSpeedY;

		iVert++;
	}

	for ( v=0; v<GRID_LINES_X*GRID_LINES_Y*4; v++ )
	{
		pVertex = pVertices+iVert;
		pVertex->tu += fSpeedZ;

		iVert++;
	}


	m_pVB->Unlock();

	return hr;
}




//-----------------------------------------------------------------------------
// Name: SetGridQuad()
// Desc: Takes a GRID_VERTEX array and generates a 3D-quad from two points
//-----------------------------------------------------------------------------

HRESULT CTextGrid::SetGridQuad( GRID_VERTEX vBuffer[4], D3DXVECTOR3 v1, D3DXVECTOR3 v2, FLOAT fAlpha, FLOAT fTile, FLOAT fTileOffset )
{
    HRESULT hr = S_OK;

	vBuffer[0].x		= v1.x;			// "topleft" corner
	vBuffer[0].y		= v1.y;
	vBuffer[0].z		= v1.z;
	vBuffer[0].nx		= 0.0f;
	vBuffer[0].ny		= 1.0f;
	vBuffer[0].nz		= 0.0f;
	vBuffer[0].diffuse	= 0xffffffff;
	vBuffer[0].tu		= 0.0f + fTileOffset;
	vBuffer[0].tv		= 0.0f;
										// "topright" corner
	vBuffer[1].x		= v2.x;
	vBuffer[1].y		= v2.y;
	vBuffer[1].z		= v2.z;
	vBuffer[1].nx		= 0.0f;
	vBuffer[1].ny		= 1.0f;
	vBuffer[1].nz		= 0.0f;
	vBuffer[1].diffuse	= 0xffffffff;
	vBuffer[1].tu		= (1.0f*fTile) + fTileOffset;
	vBuffer[1].tv		= 0.0f;
										// "bottomright" corner	
	vBuffer[2].x		= v2.x + ((v2.y != v1.y) ? GRID_SEG_SIZE : 0.0f);		// If vertex2 differs from vertex1 in height, use x to generate quad
	vBuffer[2].y		= v2.y + ((v2.x != v1.x || v2.z != v1.z) ? -GRID_SEG_SIZE : 0.0f);	// If vertex2 differs from vertex1 in width or depth, use y to generate quad
	vBuffer[2].z		= v2.z;
	vBuffer[2].nx		= 0.0f;
	vBuffer[2].ny		= 1.0f;
	vBuffer[2].nz		= 0.0f;
	vBuffer[2].diffuse	= 0xffffffff;
	vBuffer[2].tu		= (1.0f*fTile) + fTileOffset;
	vBuffer[2].tv		= 1.0f;
										// "bottomleft" corner
	vBuffer[3].x		= v1.x + ((v2.y != v1.y) ? GRID_SEG_SIZE : 0.0f);		// If vertex2 differs from vertex1 in height, use x to generate quad
	vBuffer[3].y		= v1.y + ((v2.x != v1.x || v2.z != v1.z) ? -GRID_SEG_SIZE : 0.0f);	// If vertex2 differs from vertex1 in width or depth, use y to generate quad
	vBuffer[3].z		= v1.z;
	vBuffer[3].nx		= 0.0f;
	vBuffer[3].ny		= 1.0f;
	vBuffer[3].nz		= 0.0f;
	vBuffer[3].diffuse	= 0xffffffff;
	vBuffer[3].tu		= 0.0f + fTileOffset;
	vBuffer[3].tv		= 1.0f;

	return hr;
}



//-----------------------------------------------------------------------------
// Name: SortGrid()
// Desc: Takes a GRID_VERTEX array and generates a 3D-quad from two points
//-----------------------------------------------------------------------------

HRESULT CTextGrid::SortGrid()
{
    HRESULT hr = S_OK;

	GRID_VERTEX vTable[4*GRID_QUADS];	
	ZeroMemory( vTable, sizeof(vTable) );

	GRID_VERTEX* pVertices;
	if ( FAILED(hr = m_pVB->Lock(0, NULL, (BYTE**)&pVertices, NULL)) )
		return hr;	

	memcpy( vTable, pVertices, sizeof(vTable) );
	qsort( (VOID*)vTable, GRID_QUADS, sizeof(GRID_VERTEX)*4, GridCompare );
	memcpy( pVertices, vTable, sizeof(vTable) );

	m_pVB->Unlock();

	return hr;
}



//-----------------------------------------------------------------------------
// Name: Animate()
// Desc: Animates the tunnel surfaces
//-----------------------------------------------------------------------------

HRESULT CTunnel::Animate( FLOAT fLocalTime )
{
	HRESULT hr = S_OK;

	static FLOAT fStartTime = fLocalTime;
	static FLOAT fLastTime = fLocalTime;
	FLOAT fProgress = 0.0f;

	m_fLocalTime = fLocalTime;	// Local time of class is the same as localtime for scene02()
	fProgress = (fLocalTime-fLastTime) * TUNNEL_SPEED;

	FlyCamera( fProgress, FALSE );

	if ( fProgress > 1.0f )
	{
		fProgress -= 1.0f;
		GenerateTunnel( m_pvbTunnel1, m_pibTunnel1, 7.5f, TRUE );
		GenerateTunnel( m_pvbTunnel2, m_pibTunnel2, 6.25f, FALSE );
		GenerateTunnel( m_pvbTunnel3, m_pibTunnel3, 5.0f, FALSE );

		fLastTime = fLocalTime;
	}

	RotateTexCoords( m_pvbTunnel1, m_pibTunnel1, 0.3f );
	RotateTexCoords( m_pvbTunnel2, m_pibTunnel2, -0.2f, 205.0f );
	RotateTexCoords( m_pvbTunnel3, m_pibTunnel3, 0.15f, 205.0f );


	g_pointLight.Position = m_vCamPos;	
	g_pd3dDevice->SetLight( LIGHT_POINT, &g_pointLight );

	return hr;
}




//-----------------------------------------------------------------------------
// Name: CTunnel()
// Desc: Constructor of CTunnel class. Prepares the object for use.
//-----------------------------------------------------------------------------

CTunnel::CTunnel()
{
	HRESULT hr = S_OK;
	
	m_ptexTunnel	= NULL;
	m_ptexPlasma	= NULL;
	m_ptexPlasma2	= NULL;
	m_pvbTunnel1	= NULL;
	m_pibTunnel1	= NULL;
	m_pvbTunnel2	= NULL;
	m_pibTunnel2	= NULL;
	m_pvbTunnel3	= NULL;
	m_pibTunnel3	= NULL;

	m_iNumTexts				= 8;
	ZeroMemory( m_ptexText, sizeof(m_ptexText) );
	
	m_ptexWhatIf			= NULL;		
	m_ptexWereBlaim			= NULL;		
	m_ptexHumansAre			= NULL;		
	m_ptexPsychologically	= NULL;		
	m_ptexTheSun			= NULL;
	m_ptexTheEarth			= NULL;
	m_ptexWillBlaim			= NULL;
	m_ptexUsAlone			= NULL;

	ZeroMemory( m_wpWaypoint, sizeof(m_wpWaypoint) );
	ZeroMemory( &m_mtrl, sizeof(D3DMATERIAL8) );

	m_fLocalTime		= 0.0f;	
	m_vCamPos			= D3DXVECTOR3( 0.0f, 0.0f, 0.0f );
	m_vOldCamPos		= D3DXVECTOR3( 0.0f, 0.0f, 0.0f );
	m_vCamLookAt		= D3DXVECTOR3( 0.0f, 0.0f, 0.0f );
	m_fCamProgress		= 0.0f;
	m_iNumWaypoints		= 0;
	m_iCurrentWaypoint	= 1;	// Camera starts at waypoint1 (since waypoint0 is a controlpoint)

}



//-----------------------------------------------------------------------------
// Name: FlyCamera()
// Desc: Flies the camera through the tunnel.
//-----------------------------------------------------------------------------

HRESULT CTunnel::FlyCamera( FLOAT fProgress, BOOL bWaypointChanged )
{
	HRESULT hr = S_OK;

	static FLOAT fLastTime = m_fLocalTime;
	INT iWPOffset = 0;

	m_fCamProgress = m_fLocalTime-fLastTime;//max(0.0f, (m_fLocalTime - m_wpWaypoint[1].fTime)) / (m_wpWaypoint[1+1].fTime - m_wpWaypoint[1].fTime);
	m_vOldCamPos = m_vCamPos;

	D3DXVec3CatmullRom( &m_vCamPos, 
						&m_wpWaypoint[0].v,
						&m_wpWaypoint[1].v,
						&m_wpWaypoint[2].v,
						&m_wpWaypoint[3].v,
						fProgress );


	FLOAT fLookAtProgress = fProgress + 0.3f;
	if ( fLookAtProgress >= 1.0f )
	{
		fLookAtProgress -= 1.0f;
		iWPOffset = 1;
	}

	D3DXVec3CatmullRom( &m_vCamLookAt, 
					&m_wpWaypoint[1+iWPOffset].v,
					&m_wpWaypoint[2+iWPOffset].v,
					&m_wpWaypoint[3+iWPOffset].v,
					&m_wpWaypoint[4+iWPOffset].v,
					fLookAtProgress );


	if ( !MOUSECONTROL )
	{
		g_cam.SetViewParams( m_vCamPos, m_vCamLookAt, g_cam.GetUpVec() );
	}

	return hr;
}



//-----------------------------------------------------------------------------
// Name: GenerateTunnel()
// Desc: Generates the vertex/index buffers for the tunnel used in scene02().
//-----------------------------------------------------------------------------

HRESULT CTunnel::GenerateTunnel( LPDIRECT3DVERTEXBUFFER8 pVB, LPDIRECT3DINDEXBUFFER8 pIB, FLOAT fTunnelRadius, BOOL bGenerateWaypoint )
{
	HRESULT hr = S_OK;

	static BOOL bFirstTime = TRUE;
	INT i=0;

	if ( bFirstTime )	// Generate a set of waypoints to start with
	{
		m_iNumWaypoints = 0;
		for ( i=0; i<TUNNEL_WAYPOINTS+2; i++ )	// Loop through and set all waypoints (plus endpoints) in array
		{
			m_wpWaypoint[i].v = D3DXVECTOR3( RandRange(-TUNNEL_WILD_RADIUS, TUNNEL_WILD_RADIUS), 
											 RandRange(-TUNNEL_WILD_RADIUS, TUNNEL_WILD_RADIUS), 
											 (FLOAT)(m_iNumWaypoints*(TUNNEL_LENGTH)) );

			m_wpWaypoint[i].fTime = m_iNumWaypoints * 1.0f;	// Create a temporary x sec difference between waypoints. TIME NOT USED!
			m_iNumWaypoints++;
		}
		bFirstTime = FALSE;
	}


	if ( bGenerateWaypoint )
	{
		for ( i=0; i < TUNNEL_WAYPOINTS+2-1; i++ )	
		{
			m_wpWaypoint[i].fTime = m_wpWaypoint[i+1].fTime;	// Shift waypoints towards first element of array	TIME NOT USED!
			m_wpWaypoint[i].v     = m_wpWaypoint[i+1].v;
		}

		m_wpWaypoint[i].v = D3DXVECTOR3( RandRange(-TUNNEL_WILD_RADIUS,TUNNEL_WILD_RADIUS),	// Then generate last waypoint
										 RandRange(-TUNNEL_WILD_RADIUS, TUNNEL_WILD_RADIUS), 
										 (FLOAT)(m_iNumWaypoints*(TUNNEL_LENGTH)) );

		m_wpWaypoint[i].fTime = m_iNumWaypoints * 1.0f;
		m_iNumWaypoints++;		
	}


	TUNNEL_VERTEX vTable[TUNNEL_VERTS];
	WORD iTable[TUNNEL_INDICES];

	D3DXVECTOR3	vCMToWaypoint;	// Interpolated vector between PrevWaypoint and NextWaypoint, depending on progress
	D3DXVECTOR3 vNormal;
	INT iSegInWaypoint=0;
	INT numVerts=0;
	for ( INT wp=1; wp<TUNNEL_WAYPOINTS+2-1; wp++ )
	{
		for ( INT seg=0; seg<TUNNEL_SEGS_PER_WAYPOINT; seg++ )	// Create a clone segment for each segment (used to create better texture coord control)
		{
			FLOAT fSplineSegProgress = ((FLOAT)seg / (TUNNEL_SEGS_PER_WAYPOINT-1));

			if ( fSplineSegProgress > 1.0f )
			{
				MessageBoxOK( _T("fSplineSegProgress > 1.0f") );
				fSplineSegProgress -= 1.0f;
			}


			D3DXVec3CatmullRom( &vCMToWaypoint, 
								&m_wpWaypoint[wp-1].v,
								&m_wpWaypoint[wp+0].v,
								&m_wpWaypoint[wp+1].v,
								&m_wpWaypoint[wp+2].v,
								fSplineSegProgress );
	

			for ( INT segVert=0; segVert<TUNNEL_SEGMENT_VERTS; segVert++ )
			{
				if ( numVerts > TUNNEL_VERTS-2 )
				{
					MessageBoxOK( _T("numVerts > TUNNEL_VERTS-2") );
					return E_FAIL;
				}
				
				FLOAT theta = ((FLOAT)segVert/(TUNNEL_SEGMENT_VERTS-1)) * 2.0f*D3DX_PI;
			
				if ( (segVert == (TUNNEL_SEGMENT_VERTS-1)) )	// loop-correction for cos() and sin(), probably not needed
					theta = 0.0f;


				vTable[numVerts].x = cosf ( theta ) * fTunnelRadius + vCMToWaypoint.x;
				vTable[numVerts].y = sinf ( theta ) * fTunnelRadius + vCMToWaypoint.y;
				vTable[numVerts].z = vCMToWaypoint.z;
				
				vNormal = D3DXVECTOR3( vTable[numVerts].x, vTable[numVerts].y, 0.0f );
				D3DXVec3Normalize( &vNormal, &vNormal );
				vNormal *= -1.0f;				

				vTable[numVerts].nx		 = vNormal.x;
				vTable[numVerts].ny		 = vNormal.y;
				vTable[numVerts].nz		 = vNormal.z;
				vTable[numVerts].diffuse = 0xffffffff;
				vTable[numVerts].tu		 = ((FLOAT)seg / (TUNNEL_SEGS_PER_WAYPOINT-1));
				vTable[numVerts].tv		 = (FLOAT)segVert / (TUNNEL_SEGMENT_VERTS-1);

				// Clone each vertex. Only texcoords differ.
				vTable[numVerts+1].x		= vTable[numVerts].x;
				vTable[numVerts+1].y		= vTable[numVerts].y;
				vTable[numVerts+1].z		= vTable[numVerts].z;
				vTable[numVerts+1].nx		= vTable[numVerts].nx;
				vTable[numVerts+1].ny		= vTable[numVerts].ny;
				vTable[numVerts+1].nz		= vTable[numVerts].nz;
				vTable[numVerts+1].diffuse	= vTable[numVerts].diffuse;
				vTable[numVerts+1].tu		= vTable[numVerts].tu;
				vTable[numVerts+1].tv		= vTable[numVerts].tv;
				numVerts += 2;
			}
		}
	}

	TUNNEL_VERTEX* pVertices;
	if ( FAILED(hr = pVB->Lock( 0, NULL, (BYTE**)&pVertices, NULL)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	memcpy( pVertices, vTable, sizeof(vTable) );
	pVB->Unlock();

	INT v=0;
	for ( i=0; i<TUNNEL_INDICES; i+=6 )
	{
		if ( i+5 > TUNNEL_INDICES-1 )	
		{
			MessageBoxOK( _T("i+5 > TUNNEL_INDICES-1") );
			return E_FAIL;
		}

		iTable[i+2] = v+0;								// Order is flipped so that tunnel-prmitives face inward 
		iTable[i+1] = v+0+(TUNNEL_SEGMENT_VERTS*2);
		iTable[i+0] = v+2;

		iTable[i+5] = v+2;
		iTable[i+4] = v+0+(TUNNEL_SEGMENT_VERTS*2);
		iTable[i+3] = v+2+(TUNNEL_SEGMENT_VERTS*2);

		v+=2;	// All vertices are cloned, so step with 2
	}

	WORD* pIndices;
	if ( FAILED(hr = pIB->Lock( 0, NULL, (BYTE**)&pIndices, NULL)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}
		
	memcpy( pIndices, iTable, sizeof(iTable) );
	pIB->Unlock();

	return hr;
}



//-----------------------------------------------------------------------------
// Name: InitDeviceObjects()
// Desc: Initializes and allocates all device dependent resources used by this class.
//-----------------------------------------------------------------------------

HRESULT CTunnel::InitDeviceObjects()
{
	HRESULT hr = S_OK;

#ifdef PLAY_SCENE02

   	if ( FAILED(hr = g_pd3dDevice->CreateVertexBuffer(TUNNEL_VERTS*sizeof(TUNNEL_VERTEX), NULL, TUNNEL_FVF, D3DPOOL_MANAGED, &m_pvbTunnel1)) )
		return hr;

	if ( FAILED(hr = g_pd3dDevice->CreateIndexBuffer(TUNNEL_INDICES*sizeof(WORD), NULL, D3DFMT_INDEX16, D3DPOOL_MANAGED, &m_pibTunnel1)) )
		return hr;

   	if ( FAILED(hr = g_pd3dDevice->CreateVertexBuffer(TUNNEL_VERTS*sizeof(TUNNEL_VERTEX), NULL, TUNNEL_FVF, D3DPOOL_MANAGED, &m_pvbTunnel2)) )
		return hr;

	if ( FAILED(hr = g_pd3dDevice->CreateIndexBuffer(TUNNEL_INDICES*sizeof(WORD), NULL, D3DFMT_INDEX16, D3DPOOL_MANAGED, &m_pibTunnel2)) )
		return hr;

   	if ( FAILED(hr = g_pd3dDevice->CreateVertexBuffer(TUNNEL_VERTS*sizeof(TUNNEL_VERTEX), NULL, TUNNEL_FVF, D3DPOOL_MANAGED, &m_pvbTunnel3)) )
		return hr;

	if ( FAILED(hr = g_pd3dDevice->CreateIndexBuffer(TUNNEL_INDICES*sizeof(WORD), NULL, D3DFMT_INDEX16, D3DPOOL_MANAGED, &m_pibTunnel3)) )
		return hr;

// what if
// we were the ones to blaim
// humans are juvenile and naive
// psychologically inanimated
// the sun is fading
// the earth will fall
// and we will be the ones to blaim
// us Alone


	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene02\\whatif.png"), &m_ptexWhatIf)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene02\\wereblaim.png"), &m_ptexWereBlaim)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene02\\humansare.png"), &m_ptexHumansAre)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene02\\psychologically.png"), &m_ptexPsychologically)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene02\\thesun.png"), &m_ptexTheSun)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene02\\theearth.png"), &m_ptexTheEarth)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene02\\willblaim.png"), &m_ptexWillBlaim)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene02\\usalone.png"), &m_ptexUsAlone)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}



	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene02\\bluewater8.jpg"), &m_ptexTunnel)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene02\\plasma.png"), &m_ptexPlasma)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene02\\plasma2.png"), &m_ptexPlasma2)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	m_ptexText[0] = m_ptexWhatIf;
	m_ptexText[1] = m_ptexWereBlaim;
	m_ptexText[2] = m_ptexHumansAre;
	m_ptexText[3] = m_ptexPsychologically;
	m_ptexText[4] = m_ptexTheSun;
	m_ptexText[5] = m_ptexTheEarth;
	m_ptexText[6] = m_ptexWillBlaim;
	m_ptexText[7] = m_ptexUsAlone;


	ZeroMemory( &m_mtrl, sizeof(D3DMATERIAL8) );
	m_mtrl.Diffuse.r = m_mtrl.Ambient.r = 1.0f;
	m_mtrl.Diffuse.g = m_mtrl.Ambient.g = 1.0f;
	m_mtrl.Diffuse.b = m_mtrl.Ambient.b = 1.0f;
	m_mtrl.Diffuse.a = m_mtrl.Ambient.a = 1.0f;
	g_pd3dDevice->SetMaterial( &m_mtrl );

	g_pointLight.Range = 20.0f;
	g_pointLight.Attenuation0 = 0.0f;
	g_pointLight.Attenuation1 = 10.0f;
	g_pointLight.Attenuation2 = 0.0f;

	GenerateTunnel( m_pvbTunnel1, m_pibTunnel1, 7.5f, TRUE );
	GenerateTunnel( m_pvbTunnel2, m_pibTunnel2, 6.25f, FALSE );
	GenerateTunnel( m_pvbTunnel3, m_pibTunnel3, 5.0f, FALSE );

#endif	// PLAY_SCENE02

	return hr;
}



//-----------------------------------------------------------------------------
// Name: InvalidateDeviceObjects()
// Desc: Releases and deallocates all resources used by this class instance
//-----------------------------------------------------------------------------

HRESULT CTunnel::InvalidateDeviceObjects()
{
	HRESULT hr = S_OK;

	SAFE_RELEASE( m_ptexTunnel );
	SAFE_RELEASE( m_ptexPlasma );
	SAFE_RELEASE( m_ptexPlasma2 );
	SAFE_RELEASE( m_pvbTunnel1 );
	SAFE_RELEASE( m_pibTunnel1 );
	SAFE_RELEASE( m_pvbTunnel2 );
	SAFE_RELEASE( m_pibTunnel2 );
	SAFE_RELEASE( m_pvbTunnel3 );
	SAFE_RELEASE( m_pibTunnel3 );

	SAFE_RELEASE( m_ptexWhatIf );
	SAFE_RELEASE( m_ptexWereBlaim );
	SAFE_RELEASE( m_ptexHumansAre );
	SAFE_RELEASE( m_ptexPsychologically );
	SAFE_RELEASE( m_ptexTheSun );
	SAFE_RELEASE( m_ptexTheEarth );
	SAFE_RELEASE( m_ptexWillBlaim );
	SAFE_RELEASE( m_ptexUsAlone );

	return hr;
}



HRESULT CTunnel::Overlay( FLOAT fLocalTime )
{
	HRESULT hr = S_OK;

// what if
// we were the ones to blaim
// humans are juvenile and naive
// psychologically inanimated
// the sun is fading
// the earth will fall
// and we will be the ones to blaim
// us Alone


	FLOAT fAlpha;
	FLOAT fOffsetY;
	FLOAT fScrollY = LinearChange( g_fWindowY, -g_fWindowY+100.0f, TIME_SCENE02, g_fDTime, TIME_SCENE03 );
	for ( INT i=0; i<m_iNumTexts; i++ )
	{
		fOffsetY = ((FLOAT)i / (m_iNumTexts-1)) * 600.0f + fScrollY;

	 

		if ( fOffsetY >= g_fMidWindowY )
			//fAlpha = 1 - ((fOffsetY-g_fMidWindowY) / g_fMidWindowY);
			fAlpha = LinearChange(1.0f, 0.0f, g_fMidWindowY, fOffsetY, 600.0f );
		if ( fOffsetY < g_fMidWindowY )
			fAlpha = LinearChange(0.0f, 1.0f, 0.0f, fOffsetY, g_fMidWindowY );

		ShowTexture( m_ptexText[i], 100.0f, fOffsetY, NULL, NULL, fAlpha*255.0f );
	}
	

	return hr;
}

//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Renders the tunnel
//-----------------------------------------------------------------------------

HRESULT CTunnel::Render()
{
	HRESULT hr = S_OK;

	g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,		D3DTOP_MODULATE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1,	D3DTA_TEXTURE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG2,	D3DTA_DIFFUSE );

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,		D3DTOP_MODULATE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1,	D3DTA_TEXTURE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG2,	D3DTA_DIFFUSE );
	
	g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
	g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );	


	// Background tunnel layer

	g_pd3dDevice->SetTexture( 0, m_ptexTunnel );
	g_pd3dDevice->SetVertexShader( TUNNEL_FVF );
	g_pd3dDevice->SetStreamSource( 0, m_pvbTunnel1, sizeof(TUNNEL_VERTEX) );
	g_pd3dDevice->SetIndices( m_pibTunnel1, 0 );
	
	m_mtrl.Diffuse.r = m_mtrl.Ambient.r = 1.0f;
	m_mtrl.Diffuse.g = m_mtrl.Ambient.g = 1.0f;
	m_mtrl.Diffuse.b = m_mtrl.Ambient.b = 1.0f;
	m_mtrl.Diffuse.a = m_mtrl.Ambient.a = 1.0f;
	g_pd3dDevice->SetMaterial( &m_mtrl );		

	if ( FAILED(hr = g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, TUNNEL_VERTS, 0, TUNNEL_FACES-1)) )
		return hr;


	// Tunnel layer 1

	g_pd3dDevice->SetTexture( 0, m_ptexPlasma );
	g_pd3dDevice->SetVertexShader( TUNNEL_FVF );
	g_pd3dDevice->SetStreamSource( 0, m_pvbTunnel2, sizeof(TUNNEL_VERTEX) );
	g_pd3dDevice->SetIndices( m_pibTunnel2, 0 );

	m_mtrl.Diffuse.r = m_mtrl.Ambient.r = 1.0f;
	m_mtrl.Diffuse.g = m_mtrl.Ambient.g = 1.0f;
	m_mtrl.Diffuse.b = m_mtrl.Ambient.b = 1.0f;
	m_mtrl.Diffuse.a = m_mtrl.Ambient.a = 1.0f;
	g_pd3dDevice->SetMaterial( &m_mtrl );		

	if ( FAILED(hr = g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, TUNNEL_VERTS/2, 0, TUNNEL_FACES)) )
		return hr;


	// Tunnel layer 2

	g_pd3dDevice->SetTexture( 0, m_ptexPlasma2 );
	g_pd3dDevice->SetVertexShader( TUNNEL_FVF );
	g_pd3dDevice->SetStreamSource( 0, m_pvbTunnel3, sizeof(TUNNEL_VERTEX) );
	g_pd3dDevice->SetIndices( m_pibTunnel3, 0 );

	m_mtrl.Diffuse.r = m_mtrl.Ambient.r = 1.0f;
	m_mtrl.Diffuse.g = m_mtrl.Ambient.g = 1.0f;
	m_mtrl.Diffuse.b = m_mtrl.Ambient.b = 1.0f;
	m_mtrl.Diffuse.a = m_mtrl.Ambient.a = 1.0f;
	g_pd3dDevice->SetMaterial( &m_mtrl );		

	if ( FAILED(hr = g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, TUNNEL_VERTS/2, 0, TUNNEL_FACES)) )
		return hr;

	g_pd3dDevice->SetTexture( 0, NULL );

	return hr;
}



HRESULT	CTunnel::RotateTexCoords( LPDIRECT3DVERTEXBUFFER8 pVB, LPDIRECT3DINDEXBUFFER8 pIB, FLOAT fRot, FLOAT fAlpha )
{
	HRESULT hr = S_OK;

	TUNNEL_VERTEX* pVertices = NULL;
	TUNNEL_VERTEX* pVertex = NULL;
	INT		   numVerts = 0;
	static FLOAT fLastTime = m_fLocalTime;
	FLOAT fTimeDiff = m_fLocalTime - fLastTime;

	if ( FAILED(hr = pVB->Lock( 0, NULL, (BYTE**)&pVertices, NULL)) )
		return hr;

	for ( INT wp=0; wp<TUNNEL_WAYPOINTS; wp++ )
	{
		for ( INT seg=0; seg<TUNNEL_SEGS_PER_WAYPOINT; seg++ )
		{
			for ( INT segVert=0; segVert<TUNNEL_SEGMENT_VERTS; segVert++ )
			{
				pVertex = pVertices+numVerts;

				if ( numVerts > TUNNEL_VERTS-2 )
				{
					MessageBoxOK( _T("> TUNNEL_VERTS-2") );
					return E_FAIL;
				}

//				if ( fTimeDiff >= 1.0f )
//					fTimeDiff -= 1.0f;

				pVertex->diffuse = D3DCOLOR_ARGB( (BYTE)fAlpha, 255, 255, 255 );
				pVertex->tv = ((FLOAT)segVert / (TUNNEL_SEGMENT_VERTS-1)) + (fRot * fTimeDiff); 
				pVertex->tu = (FLOAT)seg / (TUNNEL_SEGS_PER_WAYPOINT-1) + (0.5f * fTimeDiff);
	
				numVerts+=2;
			}
		}
	}

	pVB->Unlock();

//	if ( m_fLocalTime >= fLastTime+0.001f )
//	fLastTime = m_fLocalTime;

	return hr;
}



//-----------------------------------------------------------------------------
// Name: Animate()
// Desc: Animates the tunnel surfaces
//-----------------------------------------------------------------------------

HRESULT CTunnel2::Animate( FLOAT fLocalTime )
{
	HRESULT hr = S_OK;
	static FLOAT fStartTime = fLocalTime;
	static FLOAT fLastTime = fLocalTime;
	FLOAT fProgress = 0.0f;

	m_fLocalTime = fLocalTime;	// Local time of class is the same as localtime for scene05()
	fProgress = (fLocalTime-fLastTime) * TUNNEL2_SPEED;

	if ( fProgress > 1.0f )
	{
		fProgress -= 1.0f;
		GenerateTunnel( m_pvbTunnel, m_pibTunnel, 10.0f, TRUE );
		D3DXComputeNormals( m_pmeshTunnel );	

		fLastTime = fLocalTime;
	}

	FlyCamera( fProgress, FALSE );

	if ( FAILED(hr = g_bParticles.Animate(fLocalTime, fProgress)) )
		return hr;

	g_pointLight.Position = m_vCamPos;	
	g_pd3dDevice->SetLight( LIGHT_POINT, &g_pointLight );
	return hr;
}




//-----------------------------------------------------------------------------
// Name: CTunnel2()
// Desc: Constructor of CTunnel2 class. Prepares the object for use.
//-----------------------------------------------------------------------------

CTunnel2::CTunnel2()
{
	m_pmeshTunnel	= NULL;
	m_ptexTunnel	= NULL;
	m_pvbTunnel		= NULL;
	m_pibTunnel		= NULL;

	g_ptexSymbol1	= NULL;
	g_ptexSymbol2	= NULL;
	g_ptexSymbol3	= NULL;
	g_ptexSymbol4	= NULL;

	ZeroMemory( m_wpWaypoint, sizeof(m_wpWaypoint) );
	ZeroMemory( &m_mtrl, sizeof(D3DMATERIAL8) );

	m_fLocalTime		= 0.0f;	
	m_vCamPos			= D3DXVECTOR3( 0.0f, 0.0f, 0.0f );
	m_vOldCamPos		= D3DXVECTOR3( 0.0f, 0.0f, 0.0f );
	m_vCamLookAt		= D3DXVECTOR3( 0.0f, 0.0f, 0.0f );
	m_fCamProgress		= 0.0f;
	m_iNumWaypoints		= 0;
	m_iCurrentWaypoint	= 1;	// Camera starts at waypoint1 (since waypoint0 is a controlpoint)
}



//-----------------------------------------------------------------------------
// Name: FlyCamera()
// Desc: Flies the camera through the tunnel.
//-----------------------------------------------------------------------------

HRESULT CTunnel2::FlyCamera( FLOAT fProgress, BOOL bWaypointChanged )
{
	HRESULT hr = S_OK;
	static FLOAT fLastCameraTime = m_fLocalTime;
	static D3DXVECTOR3 vCameraWildLookAt = D3DXVECTOR3( 0.0f, 0.0f, 0.0f );
	static D3DXVECTOR3 vCameraOldLookAt = vCameraWildLookAt;
	static D3DXVECTOR3 vCameraNewLookAt = vCameraWildLookAt;

	INT iWPOffset = 0;

	static iLookAtListIndex = 0;
	static D3DXVECTOR3 vLookAtList[10] = 
	{
		D3DXVECTOR3(+TUNNEL2_WILDCAM_RADIUS, -TUNNEL2_WILDCAM_RADIUS/2, +15.0f),
		D3DXVECTOR3(-TUNNEL2_WILDCAM_RADIUS, +TUNNEL2_WILDCAM_RADIUS/2, +15.0f),
		D3DXVECTOR3(+TUNNEL2_WILDCAM_RADIUS, -TUNNEL2_WILDCAM_RADIUS/2, +15.0f),
		D3DXVECTOR3(-TUNNEL2_WILDCAM_RADIUS, +TUNNEL2_WILDCAM_RADIUS/2, +15.0f),
		D3DXVECTOR3(-TUNNEL2_WILDCAM_RADIUS, -TUNNEL2_WILDCAM_RADIUS/2, +15.0f),
		D3DXVECTOR3(+TUNNEL2_WILDCAM_RADIUS, +TUNNEL2_WILDCAM_RADIUS/2, +15.0f),
		D3DXVECTOR3(-TUNNEL2_WILDCAM_RADIUS, -TUNNEL2_WILDCAM_RADIUS/2, -15.0f),
		D3DXVECTOR3(-TUNNEL2_WILDCAM_RADIUS, +TUNNEL2_WILDCAM_RADIUS/2, -15.0f),
		D3DXVECTOR3(+TUNNEL2_WILDCAM_RADIUS, -TUNNEL2_WILDCAM_RADIUS/2, -15.0f),
		D3DXVECTOR3(+TUNNEL2_WILDCAM_RADIUS, +TUNNEL2_WILDCAM_RADIUS/2, -15.0f),
	};

	D3DXVec3CatmullRom( &m_vCamPos, 
						&m_wpWaypoint[1].v,
						&m_wpWaypoint[2].v,
						&m_wpWaypoint[3].v,
						&m_wpWaypoint[4].v,
						fProgress );

	FLOAT fLookAtProgress = fProgress + 0.81f;
	if ( fLookAtProgress >= 1.0f )
	{
		fLookAtProgress -= 1.0f;
		iWPOffset = 1;
	}

	D3DXVec3CatmullRom( &m_vCamLookAt, 
					&m_wpWaypoint[1+iWPOffset].v,
					&m_wpWaypoint[2+iWPOffset].v,
					&m_wpWaypoint[3+iWPOffset].v,
					&m_wpWaypoint[4+iWPOffset].v,
					fLookAtProgress );

	m_vCamLookAt *= 1.0f;

	if ( g_fDTime-TIME_SCENE01 >= 170.7f )	 // Camera goes maniac at this part
	{	
		if ( m_fLocalTime - fLastCameraTime >= TUNNEL2_WILDCAM_TIME )
		{
			iLookAtListIndex++;
			if ( iLookAtListIndex >= 10 )
				iLookAtListIndex = 0;

			fLastCameraTime = m_fLocalTime;
			vCameraOldLookAt = vCameraWildLookAt;
			vCameraNewLookAt = vLookAtList[iLookAtListIndex];
		}

		vCameraWildLookAt.x = LinearChange( vCameraOldLookAt.x, vCameraNewLookAt.x, fLastCameraTime, m_fLocalTime, fLastCameraTime+1.0f );
		vCameraWildLookAt.y = LinearChange( vCameraOldLookAt.y, vCameraNewLookAt.y, fLastCameraTime, m_fLocalTime, fLastCameraTime+1.0f );
		vCameraWildLookAt.z = LinearChange( vCameraOldLookAt.z, vCameraNewLookAt.z, fLastCameraTime, m_fLocalTime, fLastCameraTime+1.0f );

		m_vCamLookAt = m_vCamPos + vCameraWildLookAt;

#ifdef PLAYMUSIC
		FLOAT fSpectrum[256];
		FLOAT* fPtr = FSOUND_DSP_GetSpectrum();
		
		memcpy( fSpectrum, fPtr, sizeof(fSpectrum) );	// The spectrum actually has 512 entries, but only the 256 first are of interest

		FLOAT fSample = 255.0f * fSpectrum[3];
		m_vCamPos.x += (fSample-0.5f) * TUNNEL2_SHAKERADIUS;
		m_vCamPos.y += (fSample-0.5f) * TUNNEL2_SHAKERADIUS;
		m_vCamPos.z += (fSample-0.5f) * TUNNEL2_SHAKERADIUS;
#endif

	}

	g_cam.SetViewParams( m_vCamPos, m_vCamLookAt, g_cam.GetUpVec() );
	g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );

	D3DXMATRIX matRot;
	D3DXMatrixRotationYawPitchRoll( &matRot, 0.0f, 0.0f, -sinf(g_fDTime*1.0f)*1.0f );
	D3DXMatrixMultiply( &matRot, &g_cam.GetViewMatrix(), &matRot );
	g_pd3dDevice->SetTransform( D3DTS_VIEW, &matRot );

	return hr;
}



//-----------------------------------------------------------------------------
// Name: GenerateTunnel()
// Desc: Generates the vertex/index buffers for the tunnel used in scene02().
//-----------------------------------------------------------------------------

HRESULT CTunnel2::GenerateTunnel( LPDIRECT3DVERTEXBUFFER8 pVB, LPDIRECT3DINDEXBUFFER8 pIB, FLOAT fTunnelRadius, BOOL bGenerateWaypoint )
{
	HRESULT hr = S_OK;
	static BOOL bFirstTime = TRUE;
	INT i=0;

	if ( bFirstTime )	// Generate a set of waypoints to start with
	{
		m_iNumWaypoints = 0;
		for ( i=0; i<TUNNEL2_WAYPOINTS+2; i++ )	// Loop through and set all waypoints (plus endpoints) in array
		{
			m_wpWaypoint[i].v = D3DXVECTOR3( RandRange(-TUNNEL2_WILD_RADIUS, TUNNEL2_WILD_RADIUS), 
											 RandRange(-TUNNEL2_WILD_RADIUS, TUNNEL2_WILD_RADIUS), 
											 (FLOAT)(m_iNumWaypoints*(TUNNEL2_LENGTH)) );

			m_wpWaypoint[i].fTime = 0.0f;	// TIME NOT USED!
			m_iNumWaypoints++;
		}

		bFirstTime = FALSE;
	}


	if ( bGenerateWaypoint )
	{
		for ( i=0; i < TUNNEL2_WAYPOINTS+2-1; i++ )	
		{
			m_wpWaypoint[i].fTime = m_wpWaypoint[i+1].fTime;	// Shift waypoints towards first element of array	TIME NOT USED!
			m_wpWaypoint[i].v     = m_wpWaypoint[i+1].v;
		}

		m_wpWaypoint[i].v = D3DXVECTOR3( RandRange(-TUNNEL2_WILD_RADIUS, TUNNEL2_WILD_RADIUS),	// Then generate last waypoint
										 RandRange(-TUNNEL2_WILD_RADIUS, TUNNEL2_WILD_RADIUS), 
										 (FLOAT)(m_iNumWaypoints*(TUNNEL2_LENGTH)) );

		m_wpWaypoint[i].fTime = m_iNumWaypoints * 1.0f;
		m_iNumWaypoints++;		
	}

	

	TUNNEL2_VERTEX* pVertices;
	if ( FAILED(hr = pVB->Lock( 0, NULL, (BYTE**)&pVertices, NULL)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}


	D3DXVECTOR3	vCMToWaypoint;	// Interpolated vector between PrevWaypoint and NextWaypoint, depending on progress
	D3DXVECTOR3 vNormal;
	INT iSegInWaypoint=0;
	INT numVerts=0;
	for ( INT wp=1; wp<TUNNEL2_WAYPOINTS+2-1; wp++ )
	{
		for ( INT seg=0; seg<TUNNEL2_SEGS_PER_WAYPOINT; seg++ )	// Create a clone segment for each segment (used to create better texture coord control)
		{
			FLOAT fSplineSegProgress = ((FLOAT)seg / (TUNNEL2_SEGS_PER_WAYPOINT-1));

			if ( fSplineSegProgress > 1.0f )
			{
				MessageBoxOK( _T("fSplineSegProgress > 1.0f") );
				fSplineSegProgress -= 1.0f;
			}


			D3DXVec3CatmullRom( &vCMToWaypoint, 
								&m_wpWaypoint[wp-1].v,
								&m_wpWaypoint[wp+0].v,
								&m_wpWaypoint[wp+1].v,
								&m_wpWaypoint[wp+2].v,
								fSplineSegProgress );
	

			for ( INT segVert=0; segVert<TUNNEL2_SEGMENT_VERTS; segVert++ )
			{
				if ( numVerts > TUNNEL2_VERTS-2 )
				{
					MessageBoxOK( _T("numVerts > TUNNEL2_VERTS-2") );
					return E_FAIL;
				}
				
				FLOAT theta = ((FLOAT)segVert/(TUNNEL2_SEGMENT_VERTS-1)) * 2.0f*D3DX_PI;
				FLOAT phi = ((FLOAT)seg/(TUNNEL2_SEGS_PER_WAYPOINT-1) + theta*0.9f) * 2.0f*D3DX_PI;
			
				FLOAT fBumpRadius = fTunnelRadius + 
					(cosf( TUNNEL2_SEGBUMPS*theta ) * TUNNEL2_BUMPSTRENGTH) +
					(cosf( TUNNEL2_WPBUMPS*phi ) * TUNNEL2_BUMPSTRENGTH);

				if ( (segVert == (TUNNEL2_SEGMENT_VERTS-1)) )	// loop-correction for cos() and sin(), probably not needed
					theta = 0.0f;
				
				pVertices[numVerts].x = cosf ( theta ) * fBumpRadius + vCMToWaypoint.x;
				pVertices[numVerts].y = sinf ( theta ) * fBumpRadius + vCMToWaypoint.y;
				pVertices[numVerts].z = vCMToWaypoint.z;
				
				vNormal = D3DXVECTOR3( pVertices[numVerts].x, pVertices[numVerts].y, 0.0f );
				D3DXVec3Normalize( &vNormal, &vNormal );
				vNormal *= -1.0f;				

				pVertices[numVerts].nx		 = vNormal.x;
				pVertices[numVerts].ny		 = vNormal.y;
				pVertices[numVerts].nz		 = vNormal.z;
				pVertices[numVerts].diffuse = 0xffffffff;

				// Clone each vertex. Only texcoords differ.
				pVertices[numVerts+1].x			= pVertices[numVerts].x;
				pVertices[numVerts+1].y			= pVertices[numVerts].y;
				pVertices[numVerts+1].z			= pVertices[numVerts].z;
				pVertices[numVerts+1].nx		= pVertices[numVerts].nx;
				pVertices[numVerts+1].ny		= pVertices[numVerts].ny;
				pVertices[numVerts+1].nz		= pVertices[numVerts].nz;
				pVertices[numVerts+1].diffuse	= pVertices[numVerts].diffuse;
				numVerts += 2;
			}
		}
	}

	pVB->Unlock();



	WORD* pIndices;
	if ( FAILED(hr = pIB->Lock( 0, NULL, (BYTE**)&pIndices, NULL)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	INT v=0;
	for ( i=0; i<TUNNEL2_INDICES; i+=6 )
	{
		if ( i+5 > TUNNEL2_INDICES-1 )	
		{
			MessageBoxOK( _T("i+5 > TUNNEL2_INDICES-1") );
			return E_FAIL;
		}

		pIndices[i+0] = v+0;							// ?? Order is flipped, so that tunnel-primitives face inward
		pIndices[i+1] = v+0+(TUNNEL2_SEGMENT_VERTS*2);
		pIndices[i+2] = v+2;

		pIndices[i+3] = v+2;
		pIndices[i+4] = v+0+(TUNNEL2_SEGMENT_VERTS*2);
		pIndices[i+5] = v+2+(TUNNEL2_SEGMENT_VERTS*2);

		v+=2;	// All vertices are cloned, so step with 2
	}

	pIB->Unlock();
	
	return hr;
}



//-----------------------------------------------------------------------------
// Name: InitDeviceObjects()
// Desc: Initializes and allocates all device dependent resources used by this class.
//-----------------------------------------------------------------------------

HRESULT CTunnel2::InitDeviceObjects()
{
	HRESULT hr = S_OK;

#ifdef PLAY_SCENE05
	INT iFaces = TUNNEL2_FACES;
	INT iVerts = TUNNEL2_VERTS;
	
	if ( FAILED(hr = D3DXCreateMeshFVF( TUNNEL2_FACES, TUNNEL2_VERTS, D3DXMESH_MANAGED, TUNNEL2_FVF, g_pd3dDevice, &m_pmeshTunnel)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	m_pmeshTunnel->GetVertexBuffer( &m_pvbTunnel );
	m_pmeshTunnel->GetIndexBuffer( &m_pibTunnel );


	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\scene05\\redwater.jpg"), &m_ptexTunnel)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\texts\\symbol1.png"), &g_ptexSymbol1)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\texts\\symbol2.png"), &g_ptexSymbol2)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\texts\\symbol3.png"), &g_ptexSymbol3)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}

	if ( FAILED(hr = D3DXCreateTextureFromFile(g_pd3dDevice, _T("data\\bitmaps\\texts\\symbol4.png"), &g_ptexSymbol4)) )
	{
		DisplayErrorMsg2( D3DAPPERR_MEDIANOTFOUND, NULL );
		return hr;
	}


	ZeroMemory( &m_mtrl, sizeof(D3DMATERIAL8) );
	m_mtrl.Diffuse.r = m_mtrl.Ambient.r = 1.0f;
	m_mtrl.Diffuse.g = m_mtrl.Ambient.g = 1.0f;
	m_mtrl.Diffuse.b = m_mtrl.Ambient.b = 1.0f;
	m_mtrl.Diffuse.a = m_mtrl.Ambient.a = 1.0f;
	g_pd3dDevice->SetMaterial( &m_mtrl );

	g_pointLight.Range = 20.0f;
	g_pointLight.Attenuation0 = 0.0f;
	g_pointLight.Attenuation1 = 10.0f;
	g_pointLight.Attenuation2 = 0.0f;

	GenerateTunnel( m_pvbTunnel, m_pibTunnel, 10.0f, TRUE );
	
#endif	// PLAY_SCENE05

	return hr;
}



//-----------------------------------------------------------------------------
// Name: InvalidateDeviceObjects()
// Desc: Releases and deallocates all resources used by this class instance
//-----------------------------------------------------------------------------

HRESULT CTunnel2::InvalidateDeviceObjects()
{
	HRESULT hr = S_OK;

	SAFE_RELEASE( m_ptexTunnel );
//	SAFE_RELEASE( m_pvbTunnel );
//	SAFE_RELEASE( m_pibTunnel );

	SAFE_RELEASE( g_ptexSymbol1 );
	SAFE_RELEASE( g_ptexSymbol2 );
	SAFE_RELEASE( g_ptexSymbol3 );
	SAFE_RELEASE( g_ptexSymbol4 );

	SAFE_RELEASE( m_pmeshTunnel );

	return hr;
}



HRESULT CTunnel2::Overlay( FLOAT fLocalTime )
{
	HRESULT hr = S_OK;

	D3DCOLOR colTable[4] = 
	{
		{ 0x80ffffff },
		{ 0x80ffffff },
		{ 0x80ffffff },
		{ 0x80ffffff },
	};
	

	ShowTextureExTile( g_ptexSymbol1, colTable, 0.0f, 650.0f, g_fWindowX, 64.0f, 3.0f, 1.0f, -g_fDTime * 0.2f, 0.0f );
	ShowTextureExTile( g_ptexSymbol2, colTable, 0.0f, 670.0f, g_fWindowX, 64.0f, 3.0f, 1.0f, -g_fDTime * 0.4f, 0.0f );
	ShowTextureExTile( g_ptexSymbol3, colTable, 0.0f, 690.0f, g_fWindowX, 64.0f, 3.0f, 1.0f, -g_fDTime * 0.3f, 0.0f );
	ShowTextureExTile( g_ptexSymbol4, colTable, 0.0f, 710.0f, g_fWindowX, 64.0f, 3.0f, 1.0f, -g_fDTime * 0.1f, 0.0f );

	return hr;
}


//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Renders the tunnel
//-----------------------------------------------------------------------------

HRESULT CTunnel2::Render()
{
	HRESULT hr = S_OK;
	g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,		D3DTOP_MODULATE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1,	D3DTA_TEXTURE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG2,	D3DTA_DIFFUSE );

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,		D3DTOP_MODULATE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1,	D3DTA_TEXTURE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG2,	D3DTA_DIFFUSE );
	
	//g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_cam.GetViewMatrix() );
	g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &g_cam.GetProjMatrix() );
	g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );	


	// Background tunnel layer

	m_mtrl.Diffuse.r = m_mtrl.Ambient.r = 1.0f;
	m_mtrl.Diffuse.g = m_mtrl.Ambient.g = 1.0f;
	m_mtrl.Diffuse.b = m_mtrl.Ambient.b = 1.0f;
	m_mtrl.Diffuse.a = m_mtrl.Ambient.a = 1.0f;
	g_pd3dDevice->SetMaterial( &m_mtrl );		


    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSU,  D3DTADDRESS_MIRROR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ADDRESSV,  D3DTADDRESS_MIRROR );

	// Generate spheremap texture coords, and shift them over
	D3DXMATRIX mat;
	mat._11 = 0.5f; mat._12 = 0.0f; mat._13 = 0.0f; mat._14 = 0.0f; 
	mat._21 = 0.0f; mat._22 =-0.5f; mat._23 = 0.0f; mat._24 = 0.0f; 
	mat._31 = 0.0f; mat._32 = 0.0f; mat._33 = 1.0f; mat._34 = 0.0f; 
	mat._41 = 0.5f; mat._42 = 0.5f; mat._43 = 0.0f; mat._44 = 1.0f; 

	g_pd3dDevice->SetTransform( D3DTS_TEXTURE0, &mat );

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT2 );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_CAMERASPACENORMAL );	

	g_pd3dDevice->SetTexture( 0, m_ptexTunnel );
	g_pd3dDevice->SetVertexShader( TUNNEL2_FVF );
	g_pd3dDevice->SetStreamSource( 0, m_pvbTunnel, sizeof(TUNNEL2_VERTEX) );
	g_pd3dDevice->SetIndices( m_pibTunnel, 0 );

	if ( FAILED(hr = g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, TUNNEL2_VERTS, 0, TUNNEL2_FACES-1)) )
		return hr;

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_PASSTHRU );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE );

	g_pd3dDevice->SetTexture( 0, NULL );

	return hr;
}



//-----------------------------------------------------------------------------
// Name: DisplayErrorMsg2()
// Desc: Displays error messages in a message box. Copied from d3dapp.cpp.
//-----------------------------------------------------------------------------
HRESULT DisplayErrorMsg2( HRESULT hr, DWORD dwType )
{
    TCHAR strMsg[512] = { "Error: " };

    switch( hr )
    {
        case D3DAPPERR_NODIRECT3D:
            _tcscpy( strMsg, _T("Could not initialize Direct3D. You may\n")
                             _T("want to check that the latest version of\n")
                             _T("DirectX is correctly installed on your\n")
                             _T("system.  Also make sure that this program\n")
                             _T("was compiled with header files that match\n")
                             _T("the installed DirectX DLLs.") );
            break;

        case D3DAPPERR_NOCOMPATIBLEDEVICES:
            _tcscpy( strMsg, _T("Could not find any compatible Direct3D\n")
                             _T("devices.") );
            break;

        case D3DAPPERR_NOWINDOWABLEDEVICES:
            _tcscpy( strMsg, _T("This sample cannot run in a desktop\n")
                             _T("window with the current display settings.\n")
                             _T("Please change your desktop settings to a\n")
                             _T("16- or 32-bit display mode and re-run this\n")
                             _T("sample.") );
            break;

        case D3DAPPERR_NOHARDWAREDEVICE:
            _tcscpy( strMsg, _T("No hardware-accelerated Direct3D devices\n")
                             _T("were found.") );
            break;

        case D3DAPPERR_HALNOTCOMPATIBLE:
            _tcscpy( strMsg, _T("This sample requires functionality that is\n")
                             _T("not available on your Direct3D hardware\n")
                             _T("accelerator.") );
            break;

        case D3DAPPERR_NOWINDOWEDHAL:
            _tcscpy( strMsg, _T("Your Direct3D hardware accelerator cannot\n")
                             _T("render into a window.\n")
                             _T("Press F2 while the app is running to see a\n")
                             _T("list of available devices and modes.") );
            break;

        case D3DAPPERR_NODESKTOPHAL:
            _tcscpy( strMsg, _T("Your Direct3D hardware accelerator cannot\n")
                             _T("render into a window with the current\n")
                             _T("desktop display settings.\n")
                             _T("Press F2 while the app is running to see a\n")
                             _T("list of available devices and modes.") );
            break;

        case D3DAPPERR_NOHALTHISMODE:
            _tcscpy( strMsg, _T("This sample requires functionality that is\n")
                             _T("not available on your Direct3D hardware\n")
                             _T("accelerator with the current desktop display\n")
                             _T("settings.\n")
                             _T("Press F2 while the app is running to see a\n")
                             _T("list of available devices and modes.") );
            break;

        case D3DAPPERR_MEDIANOTFOUND:
            _tcscpy( strMsg, _T("Could not load required media." ) );
            break;

        case D3DAPPERR_RESIZEFAILED:
            _tcscpy( strMsg, _T("Could not reset the Direct3D device." ) );
            break;

        case D3DAPPERR_NONZEROREFCOUNT:
            _tcscpy( strMsg, _T("A D3D object has a non-zero reference\n")
                             _T("count (meaning things were not properly\n")
                             _T("cleaned up).") );
            break;

        case E_OUTOFMEMORY:
            _tcscpy( strMsg, _T("Not enough memory.") );
            break;

        case D3DERR_OUTOFVIDEOMEMORY:
            _tcscpy( strMsg, _T("Not enough video memory.") );
            break;

        default:
			if ( D3DAPPERR_MEDIANOTFOUND == dwType )
				lstrcpy( strMsg, "Media not found." );
			else
				D3DXGetErrorString( hr, &strMsg[7], 512 );	// Print error message after 7 characters 'Error: '
    }

    if( MSGERR_APPMUSTEXIT == dwType )
    {
        _tcscat( strMsg, _T("\n\nThis sample will now exit.") );
        MessageBox( NULL, strMsg, NULL, MB_ICONERROR|MB_OK );

        // Close the window, which shuts down the app
        if( g_hWnd )
            SendMessage( g_hWnd, WM_CLOSE, 0, 0 );
    }
    else
    {
        if( MSGWARN_SWITCHEDTOREF == dwType )
            _tcscat( strMsg, _T("\n\nSwitching to the reference rasterizer,\n")
                             _T("a software device that implements the entire\n")
                             _T("Direct3D feature set, but runs very slowly.") );
        MessageBox( NULL, strMsg, NULL, MB_ICONWARNING|MB_OK );
    }

    return hr;
}



//-----------------------------------------------------------------------------
// Name: DisturbWater()
// Desc: Animates the water surface with waves from a sourcepoint.
//-----------------------------------------------------------------------------

HRESULT DisturbWater( LPDIRECT3DVERTEXBUFFER8 pVB, LPDIRECT3DINDEXBUFFER8 pIB, DWORD dwFVF, WAVEDATA* wd, FLOAT fLocalTime )
{
	HRESULT hr = S_OK;

    if ( fLocalTime < wd->fTimeStart || fLocalTime > wd->fTimeEnd )
		return S_OK;

	if ( !pVB || !pIB )
	{
		MessageBoxOK( _T("DisturbWater()\nA buffer pointer is NULL!") );
		return E_FAIL;
	}

	DWORD dwStride = D3DXGetFVFVertexSize( dwFVF );
	FLOAT fExpandProg = (min(max(fLocalTime, wd->fTimeStart), wd->fTimeStart + 2.0f) - wd->fTimeStart) / (2.0f);	// 2 second expansion of waves
	FLOAT fLifeProg = (max(min(fLocalTime, wd->fTimeEnd), wd->fTimeStart) - wd->fTimeStart) / (wd->fTimeEnd - wd->fTimeStart);
	FLOAT fOldY;

	ALLVERTEX* pVertex;
	BYTE* pVertices;
	if ( FAILED(hr = pVB->Lock( 0, NULL, &pVertices, NULL)) )
		return hr;
	
	for ( INT v=0; v<WATER_VERTS; v++ )
	{
		pVertex = (ALLVERTEX*) (pVertices + v*dwStride);
		fOldY = pVertex->y;
		
		if ( wd->bDataIsSet == FALSE )
		{
			wd->fVertDist[v] = sqrtf( powf(pVertex->x - wd->fPosX,2.0f) + powf(pVertex->z - wd->fPosY,2.0f) );
			wd->fVertAffection[v] = wd->fStrength - (wd->fStrength*(wd->fVertDist[v] / wd->fRadius));
		}
		
		if ( wd->fVertDist[v] < wd->fRadius * fExpandProg )
		{
			pVertex->y = sinf( ((wd->fVertDist[v] / wd->fWaveWidth)-(fLocalTime/WATER_DELAY)) * (180.0f/D3DX_PI) ) * wd->fVertAffection[v] * (1.0f-fLifeProg);
			pVertex->y += fOldY;
		}

	}


	pVB->Unlock();

	if ( wd->bDataIsSet == FALSE )
		wd->bDataIsSet = TRUE;

	return hr;
}



//-----------------------------------------------------------------------------
// Name: DrawLine()
// Desc: Draws a 2D line from XY1 to XY2, with the given color.
//-----------------------------------------------------------------------------

HRESULT DrawLine( FLOAT fX1, FLOAT fY1, FLOAT fX2, FLOAT fY2, D3DCOLOR dwCol, FLOAT fAlpha )
{
	HRESULT hr = S_OK;
	LPDIRECT3DVERTEXBUFFER8 pVB = NULL;

	dwCol &= 0x00ffffff;
	dwCol += ((DWORD)fAlpha << 24);

	TLVERTEX vTable[2] = 
	{
		{ fX1, fY1, 0.0f, 1.0f, dwCol },
		{ fX2, fY2, 0.0f, 1.0f, dwCol },
	};


	if ( FAILED(hr = g_pd3dDevice->CreateVertexBuffer(2*sizeof(TLVERTEX), NULL, D3DFVF_TLVERTEX, D3DPOOL_MANAGED, &pVB)) )
		return hr;

	TLVERTEX* pVertices = NULL;
	if ( FAILED(hr = pVB->Lock(0, NULL, (BYTE**)&pVertices, NULL)) )
		return hr;

	memcpy( pVertices, vTable, sizeof(vTable) );
	pVB->Unlock();

	g_pd3dDevice->SetVertexShader( D3DFVF_TLVERTEX );
	g_pd3dDevice->SetStreamSource( 0, pVB, sizeof(TLVERTEX) );

	g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
	g_pd3dDevice->SetMaterial( &g_stdMtrl );

	if ( FAILED(hr = g_pd3dDevice->DrawPrimitive(D3DPT_LINELIST, 0, 1)) )
		return hr;

	g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, TRUE );

	SAFE_RELEASE( pVB );

	
	return hr;
}



//-----------------------------------------------------------------------------
// Name: DrawRect()
// Desc: Draws a 2D rectangle with lines from XY1 to XY2, with the given color.
//-----------------------------------------------------------------------------

HRESULT DrawRect( FLOAT fX1, FLOAT fY1, FLOAT fX2, FLOAT fY2, D3DCOLOR dwCol, FLOAT fAlpha )
{
	HRESULT hr = S_OK;
	LPDIRECT3DVERTEXBUFFER8 pVB = NULL;

	dwCol &= 0x00ffffff;
	dwCol += ((DWORD)fAlpha << 24);

	TLVERTEX vTable[2*4] = 
	{
		{ fX1, fY1, 0.0f, 1.0f, dwCol },
		{ fX2, fY1, 0.0f, 1.0f, dwCol },

		{ fX2, fY1, 0.0f, 1.0f, dwCol },
		{ fX2, fY2, 0.0f, 1.0f, dwCol },

		{ fX2, fY2, 0.0f, 1.0f, dwCol },
		{ fX1, fY2, 0.0f, 1.0f, dwCol },

		{ fX1, fY2, 0.0f, 1.0f, dwCol },
		{ fX1, fY1, 0.0f, 1.0f, dwCol },
	};


	if ( FAILED(hr = g_pd3dDevice->CreateVertexBuffer(8*sizeof(TLVERTEX), NULL, D3DFVF_TLVERTEX, D3DPOOL_MANAGED, &pVB)) )
		return hr;

	TLVERTEX* pVertices = NULL;
	if ( FAILED(hr = pVB->Lock(0, NULL, (BYTE**)&pVertices, NULL)) )
		return hr;

	memcpy( pVertices, vTable, sizeof(vTable) );
	pVB->Unlock();

	g_pd3dDevice->SetVertexShader( D3DFVF_TLVERTEX );
	g_pd3dDevice->SetStreamSource( 0, pVB, sizeof(TLVERTEX) );

	g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
	g_pd3dDevice->SetMaterial( &g_stdMtrl );

	for ( INT i=0; i<4; i++ )
	{
		if ( FAILED(hr = g_pd3dDevice->DrawPrimitive(D3DPT_LINELIST, i*2, 1)) )
			return hr;
	}

	g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, TRUE );

	SAFE_RELEASE( pVB );

	
	return hr;
}


//-----------------------------------------------------------------------------
// Name: Fade()
// Desc: Handles a fade-in or -out based on two color values and a timeline.
//-----------------------------------------------------------------------------

HRESULT Fade( D3DCOLOR dwColorStart, D3DCOLOR dwColorEnd, FLOAT fTStart, FLOAT fTCurrent, FLOAT fTEnd, FLOAT fTHold )
{
    if ( fTCurrent < fTStart || fTCurrent >= fTEnd+fTHold )
        return S_OK;

	HRESULT hr = S_OK;
	ARGB colStart   = { (BYTE)(dwColorStart >> 24), (BYTE)((dwColorStart & 0x00ff0000) >> 16), (BYTE)((dwColorStart & 0x0000ff00) >> 8), (BYTE)((dwColorStart & 0x000000ff)) };
	ARGB colEnd	    = { (BYTE)(dwColorEnd   >> 24), (BYTE)((dwColorEnd   & 0x00ff0000) >> 16), (BYTE)((dwColorEnd   & 0x0000ff00) >> 8), (BYTE)((dwColorEnd   & 0x000000ff)) };
    ARGB colCalc    = { colStart.a, colStart.r, colStart.g, colStart.b };

	g_bFading = TRUE;	// This is turned off in FadeRect()
    g_fFadeStart    = min(fTStart + (g_fDTime - fTCurrent), g_fFadeStart);
    g_fFadeEnd      = max(fTEnd + (g_fDTime - fTCurrent) + fTHold, g_fFadeEnd);
	g_dwFadeColor   = D3DCOLOR_ARGB( (BYTE)LinearChange(colStart.a, colEnd.a, fTStart, fTCurrent, fTEnd), colCalc.r, colCalc.g, colCalc.b );

	return hr;
}




//-----------------------------------------------------------------------------
// Name: FadeRect()
// Desc: Draws a 2D-rect on the screen specified by color and screen-offset
//-----------------------------------------------------------------------------

HRESULT FadeRect( D3DCOLOR dwColor, RECT rcArea, BOOL bUpdateRect, BOOL bOverrideFade )
{
	HRESULT hr = S_OK;

	if (  !bOverrideFade && (g_fDTime < g_fFadeStart || g_fDTime >= g_fFadeEnd) )
	{
		g_bFading = FALSE;
		return S_OK;
	}

	if ( (dwColor & 0x00ffffff) )
		ShowTexture( g_ptexWhite, (FLOAT)rcArea.left, (FLOAT)rcArea.top, (FLOAT)rcArea.right, (FLOAT)rcArea.bottom, (BYTE)(dwColor>>24) );
	else
		ShowTexture( g_ptexBlack, (FLOAT)rcArea.left, (FLOAT)rcArea.top, (FLOAT)rcArea.right, (FLOAT)rcArea.bottom, (BYTE)(dwColor>>24) );


/*    if ( bUpdateRect )
    {
        TLVERTEX* pVertices;
        TLVERTEX vTable[] = 
        {
            { (FLOAT)rcArea.left,  (FLOAT)rcArea.top,    0.0f, 1.0f, dwColor },
            { (FLOAT)rcArea.right, (FLOAT)rcArea.top,    0.0f, 1.0f, dwColor },
            { (FLOAT)rcArea.right, (FLOAT)rcArea.bottom, 0.0f, 1.0f, dwColor },
            { (FLOAT)rcArea.left,  (FLOAT)rcArea.bottom, 0.0f, 1.0f, dwColor },
        };

        if ( FAILED(hr = g_pvbFadeRect->Lock(0, NULL, (BYTE**)&pVertices, NULL)) )
        {
            DisplayErrorMsg2( hr, NULL );
            return hr;
        }
           
        memcpy( pVertices, vTable, sizeof(vTable) );
        g_pvbFadeRect->Unlock();        
    }

	g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,	D3DTOP_SELECTARG1 );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_DIFFUSE );
    
    g_pd3dDevice->SetVertexShader( D3DFVF_TLVERTEX );
    g_pd3dDevice->SetStreamSource( 0, g_pvbFadeRect, sizeof(TLVERTEX) );

    if ( FAILED(hr = g_pd3dDevice->DrawPrimitive( D3DPT_TRIANGLEFAN, 0, 2 )) )
    {
        DisplayErrorMsg2( hr, NULL );
        return hr;
    }

    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,	D3DTOP_MODULATE );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
    g_pd3dDevice->SetTexture( 0, NULL );
*/
	return hr;
}



//-----------------------------------------------------------------------------
// Name: FillTexture()
// Desc: Fills texture2 with texture1, rescaled to fit.
//-----------------------------------------------------------------------------
HRESULT FillTexture( LPDIRECT3DTEXTURE8 pTex1, LPDIRECT3DTEXTURE8 pTex2 )
{
	HRESULT hr = S_OK;

	if ( FALSE == pTex1 || FALSE == pTex2)
	{
		MessageBoxOK( _T("FillTexture()\nA paramter is NULL!") );
		return E_FAIL;
	}

	D3DSURFACE_DESC destDesc;
	pTex2->GetLevelDesc( 0, &destDesc );

	SetRenderTargetToTexture( pTex2 );

	ShowTexture( pTex1, 0.0f, 0.0f, (FLOAT)destDesc.Width, (FLOAT)destDesc.Height );

	RestoreRenderTarget();

	return hr;
}




//-----------------------------------------------------------------------------
// Name: FireFlies()
// Desc: Used in introscene to spawn and animate fireflies in the scene.
//-----------------------------------------------------------------------------

HRESULT FireFlies( FLOAT fSceneTime )
{
    HRESULT hr = S_OK;
	static FLOAT fTimeStart = fSceneTime;
	static BOOL bFirstTime = TRUE;

	if ( bFirstTime )	
	{							// FIX ADDFLIES
		g_flyGroup1.AddFlies( 1, D3DXVECTOR3( 30.0f, 17.0f, 20.0f), 10.7f, fSceneTime, 0.0f, 1 );
		g_flyGroup1.AddFlies( 4, D3DXVECTOR3(-30.0f,  3.0f,-40.0f), 15.0f, fSceneTime, 1.0f, 1 );
		g_flyGroup1.AddFlies( 6, D3DXVECTOR3(  0.0f, 15.0f, 30.0f), 20.5f, fSceneTime, 0.7f, 1 );
		g_flyGroup1.AddFlies( 8, D3DXVECTOR3( 10.0f, 13.0f,-40.0f), 32.0f, fSceneTime, 0.8f, 1 );

		bFirstTime = FALSE;
	}

	g_flyGroup1.Animate( fSceneTime );
	g_flyGroup1.Render();

	return hr;
}



//-----------------------------------------------------------------------------
// Name: GridCompare()
// Desc: A compare function, used by qsort() in sorting the grids by distance.
//-----------------------------------------------------------------------------

INT GridCompare( const VOID* arg1, const VOID* arg2 )
{
	GRID_VERTEX* pArg1 = (GRID_VERTEX*)arg1;
	GRID_VERTEX* pArg2 = (GRID_VERTEX*)arg2;

	D3DXVECTOR3 vP1 = D3DXVECTOR3( pArg1->x, pArg1->y, pArg1->z );
	D3DXVECTOR3 vP2 = D3DXVECTOR3( pArg2->x, pArg2->y, pArg2->z );
	D3DXVECTOR3 vDist1 = vP1 - g_cam.GetEyePt();
	D3DXVECTOR3 vDist2 = vP2 - g_cam.GetEyePt();

	FLOAT fDist1 = (FLOAT)sqrt( vDist1.x * vDist1.y * vDist1.z );
	FLOAT fDist2 = (FLOAT)sqrt( vDist2.x * vDist2.y * vDist2.z );

	if ( fabs(fDist1) > fabs(fDist2) )	// arg1 > arg2
		return 1;
	else
		if ( fabs(fDist1) < fabs(fDist2) )	// arg1 < arg2
			return -1;
		else
			return 0;	// arguments are equal

	MessageBoxOK( _T("GridCompare. No if statements applied.") );
	
	return 0;
}



//-----------------------------------------------------------------------------
// Name: LinearChange()
// Desc: Calculates a linear change based on starttime, current time, end time
//		 and two values to interpolate between.
//-----------------------------------------------------------------------------

FLOAT LinearChange( FLOAT fStart, FLOAT fEnd, FLOAT fTimeStart, FLOAT fLocalTime, FLOAT fTimeEnd )
{
	return ( (max(min(fLocalTime,fTimeEnd),fTimeStart)-fTimeStart) / (fTimeEnd-fTimeStart) * (fEnd-fStart) + fStart );
}



//-----------------------------------------------------------------------------
// Name: LinearChangeVector()
// Desc: Calculates a linear vector change based on starttime, current time, end time
//		 and two vectors to interpolate between.
//-----------------------------------------------------------------------------

D3DXVECTOR3 LinearChangeVector( D3DXVECTOR3 vStart, D3DXVECTOR3 vEnd, FLOAT fTimeStart, FLOAT fLocalTime, FLOAT fTimeEnd )
{
	D3DXVECTOR3 vResult;
	vResult.x = (max(min(fLocalTime,fTimeEnd),fTimeStart)-fTimeStart) / (fTimeEnd-fTimeStart) * (vEnd.x-vStart.x) + vStart.x;
	vResult.y = (max(min(fLocalTime,fTimeEnd),fTimeStart)-fTimeStart) / (fTimeEnd-fTimeStart) * (vEnd.y-vStart.y) + vStart.y;
	vResult.z = (max(min(fLocalTime,fTimeEnd),fTimeStart)-fTimeStart) / (fTimeEnd-fTimeStart) * (vEnd.z-vStart.z) + vStart.z;

	return vResult;
}


//-----------------------------------------------------------------------------
// Name: LoadScreen()
// Desc: The loadscreen splash.
//-----------------------------------------------------------------------------

HRESULT LoadScreen( FLOAT fTime )
{
	HRESULT hr = S_OK;
	
#ifdef PLAY_LOADSCREEN

	static BOOL bFirstTime = TRUE;
	static FLOAT fStartTime = fTime;
	FLOAT fLocalTime = (fTime - TIME_SCENE05);

	if ( bFirstTime )
	{
		g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
		g_pd3dDevice->SetRenderState( D3DRS_FILLMODE, D3DFILL_SOLID );

		bFirstTime = FALSE;
	}

    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_SELECTARG1 );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
    g_pd3dDevice->SetTextureStageState( 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );


	g_pd3dDevice->SetTexture( 0, NULL );

	ShowTexture( g_ptexLoadScreen, 0.0f, 0.0f, g_fWindowX, g_fWindowY );

#endif	// PLAY_LOADSCREE
	return hr;
}




//-----------------------------------------------------------------------------
// Name: ManipulatorProc()
// Desc: The WinProc for the manipulator window. 
//-----------------------------------------------------------------------------

INT_PTR CALLBACK ManipulatorProc( HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	HWND hwndSlider0 = GetDlgItem( hwndDlg, IDC_SLIDER0 );
	HWND hwndSlider1 = GetDlgItem( hwndDlg, IDC_SLIDER1 );
	HWND hwndSlider2 = GetDlgItem( hwndDlg, IDC_SLIDER2 );
	HWND hwndSlider3 = GetDlgItem( hwndDlg, IDC_SLIDER3 );
	INT iValue[4];

	g_hwndManipl = hwndDlg;

	switch( uMsg )
	{
	case WM_INITDIALOG:
		SendMessage( hwndSlider0, TBM_SETRANGE, TRUE, MAKELONG( -75, 75) );
		SendMessage( hwndSlider1, TBM_SETRANGE, TRUE, MAKELONG(  0,  50) );
		SendMessage( hwndSlider2, TBM_SETRANGE, TRUE, MAKELONG( -75, 75) );
		SendMessage( hwndSlider3, TBM_SETRANGE, TRUE, MAKELONG(  0,  50) );
		return TRUE;

	case WM_NOTIFY:
		iValue[0] = SendMessage( hwndSlider0, TBM_GETPOS, NULL, NULL );
		iValue[1] = SendMessage( hwndSlider1, TBM_GETPOS, NULL, NULL );
		iValue[2] = SendMessage( hwndSlider2, TBM_GETPOS, NULL, NULL );
		iValue[3] = SendMessage( hwndSlider3, TBM_GETPOS, NULL, NULL );

		SetDlgItemInt( hwndDlg, IDC_VALUE0, iValue[0], TRUE );
		SetDlgItemInt( hwndDlg, IDC_VALUE1, iValue[1], TRUE );
		SetDlgItemInt( hwndDlg, IDC_VALUE2, iValue[2], TRUE );
		SetDlgItemInt( hwndDlg, IDC_VALUE3, iValue[3], TRUE );
		break;

	case WM_COMMAND:
		switch( LOWORD(wParam) )
		{
		case IDOK:
			EndDialog( hwndDlg, DBR_OK );
			return TRUE;

		case IDCANCEL:
			EndDialog( hwndDlg, DBR_CANCEL );
			return TRUE;
		}
		break;
	}
	return FALSE;
}

    

//-----------------------------------------------------------------------------
// Name: MsgProc()
// Desc: The window's message handler
//-----------------------------------------------------------------------------
LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
	case WM_COMMAND:
		switch( HIWORD(wParam) )
		{
		case IDM_EXIT:
			SendMessage( g_hWnd, WM_CLOSE, NULL, NULL );
			break;

		case IDM_CHANGEDEVICE:
			break;

		case IDM_TOGGLEFULLSCREEN:
			break;

#ifdef FULLSCREEN
        case WM_SETCURSOR:
            // Turn off Windows cursor in fullscreen mode
			SetCursor( NULL );
			g_pd3dDevice->ShowCursor( TRUE );

			return TRUE;	// prevent Windows from setting cursor to window class cursor
#endif
		}

	case WM_DESTROY:
		PostQuitMessage( 0 );
		return 0;
    }

    return DefWindowProc( hWnd, msg, wParam, lParam );
}




//-----------------------------------------------------------------------------
// Name: RandRange()
// Desc: Calculates a random value between and including 'high' and 'low'
//-----------------------------------------------------------------------------

inline 	FLOAT RandRange( FLOAT low, FLOAT high)
{ 
	return (FLOAT)rand() / (RAND_MAX / (high - low + 1.0f)) + low; 
}



//-----------------------------------------------------------------------------
// Name: RestoreRenderTarget()
// Desc: Restores the render target to the backbuffer and its stencilbuffer.
//-----------------------------------------------------------------------------

HRESULT RestoreRenderTarget()
{
	g_pd3dDevice->SetRenderTarget( g_psOrigRenderTarget, g_psOrigStencilTarget );

	return S_OK;
}



HRESULT Scene09Overlay( FLOAT fLocalTime )
{
	HRESULT hr = S_OK;

	FLOAT fOffsetY;
	for ( INT i=0; i<g_iNumGreets; i++ )
	{
		fOffsetY = LinearChange( g_fWindowY, -g_fWindowY, TIME_SCENE09, g_fDTime, TIME_SCENE10 );
		ShowTexture( g_ptexGreets[i], 768.0f, fOffsetY + i*80.0f, NULL, NULL );
	}

	return hr;
}

//-----------------------------------------------------------------------------
// Name: SetDetailedVBRect()
// Desc: Sets up vertex table 
//-----------------------------------------------------------------------------

HRESULT SetDetailedVBRect( LPDIRECT3DVERTEXBUFFER8 pVB, FLOAT fOffsetX, FLOAT fOffsetY, FLOAT fOffsetX2, FLOAT fOffsetY2, INT numQuadsX, INT numQuadsY, FLOAT fAlpha=255.0f, FLOAT fTiled=1.0f )
{
    HRESULT hr = S_OK;
	FLOAT quadPosX;
	FLOAT quadPosY;
	FLOAT tu;
	FLOAT tv;
	FLOAT width = fOffsetX2-fOffsetX;
	FLOAT height = fOffsetY2-fOffsetY;
	FLOAT quadWidth = width / numQuadsX;
	FLOAT quadHeight = height / numQuadsY;

	if ( !pVB )
	{
		MessageBoxOK( _T("SetDetailedVBRect()\nA buffer pointer is NULL!") );
		return E_FAIL;
	}

	TLTQUAD quads[QUADS_Y][QUADS_X];

	for ( INT y=0; y<numQuadsX; y++ )
		for ( INT x=0; x<numQuadsY; x++ )
			for ( INT v=0; v<4; v++ )
			{
				tu = ((v == 0 || v == 3) ? 0.0f : 1.0f);
				tv = ((v == 0 || v == 1) ? 0.0f : 1.0f);
				quadPosX = (x * quadWidth)  + (tu * quadWidth);
				quadPosY = (y * quadHeight) + (tv * quadHeight);

				quads[y][x].vertex[v].x			= quadPosX + fOffsetX;
				quads[y][x].vertex[v].y			= quadPosY + fOffsetY;
				quads[y][x].vertex[v].z			= 0.0f;
				quads[y][x].vertex[v].rhw		= 1.0f;
				quads[y][x].vertex[v].diffuse	= 0xffffffff;
				quads[y][x].vertex[v].tu		= quadPosX / (numQuadsX * quadWidth);
				quads[y][x].vertex[v].tv		= quadPosY / (numQuadsY * quadHeight);
			}

	BYTE* pVertices;
	if ( FAILED(hr = pVB->Lock( 0, NULL, &pVertices, NULL )) )
		return hr;

		memcpy( pVertices, quads, QUADS_Y * QUADS_X * sizeof(TLTQUAD) );

	pVB->Unlock();


	return hr;
}




//-----------------------------------------------------------------------------
// Name: SetRenderTargetToCubemap()
// Desc: Sets the render target to the given cubemap texture at the specified level
//-----------------------------------------------------------------------------

HRESULT SetRenderTargetToCubemap( INT iLevel, LPDIRECT3DCUBETEXTURE8 ptexCube, LPDIRECT3DSURFACE8 psStencil )
{
	HRESULT hr = S_OK;
	LPDIRECT3DSURFACE8 pCubeSurface;
	D3DSURFACE_DESC	desc;

	if ( FAILED(hr = ptexCube->GetCubeMapSurface( (D3DCUBEMAP_FACES)iLevel, 0, &pCubeSurface)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	pCubeSurface->GetDesc( &desc );
	if ( desc.Usage != D3DUSAGE_RENDERTARGET )
	{
		MessageBoxOK( _T("SetRenderTargetToTexture()\nTexture missing D3DUSAGE_RENDERTARGET flag!") );
		return E_FAIL;
	}

	g_pd3dDevice->SetRenderTarget( pCubeSurface, psStencil );
	SAFE_RELEASE( pCubeSurface );

	return hr;
}



//-----------------------------------------------------------------------------
// Name: SetRenderTargetToTexture()
// Desc: Sets the render target to the given texture's toplevel surface.
//-----------------------------------------------------------------------------

HRESULT SetRenderTargetToTexture( LPDIRECT3DTEXTURE8 pTex )
{
	HRESULT hr = S_OK;
	LPDIRECT3DSURFACE8 pSurface;
	D3DSURFACE_DESC	desc;

	pTex->GetSurfaceLevel( 0, &pSurface );
	pTex->GetLevelDesc( 0, &desc );

	if ( desc.Usage != D3DUSAGE_RENDERTARGET )
	{
		MessageBoxOK( _T("SetRenderTargetToTexture()\nTexture missing D3DUSAGE_RENDERTARGET flag!") );
		return E_FAIL;
	}

	if ( FAILED(hr= g_pd3dDevice->SetRenderTarget(pSurface, NULL)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	SAFE_RELEASE( pSurface );

	return hr;
}



//-----------------------------------------------------------------------------
// Name: SetVB3DPlaneRect()
// Desc: Creates a 3D plane and assigns it to the given vertex and index buffers.
//-----------------------------------------------------------------------------

HRESULT SetVB3DPlaneRect( LPDIRECT3DVERTEXBUFFER8 pVB, LPDIRECT3DINDEXBUFFER8 pIB, DWORD dwFVF, D3DXVECTOR3 vTopLeft, D3DXVECTOR3 vBottomRight, INT numVertsX, INT numVertsY, FLOAT fAlpha=255.0f )
{
    HRESULT hr = S_OK;
	FLOAT fWidth = vBottomRight.x - vTopLeft.x;
	FLOAT fHeight = vBottomRight.z - vTopLeft.z;
	FLOAT fQuadWidth = fWidth / (numVertsX-1);
	FLOAT fQuadHeight = fHeight / (numVertsY-1);
	FLOAT fOffsetX = vTopLeft.x;
	FLOAT fOffsetY = vTopLeft.z;
	DWORD dwStride = D3DXGetFVFVertexSize( dwFVF );

	if ( !pVB || !pIB )
	{
		MessageBoxOK( _T("SetVB3DPlaneRect()\nA buffer pointer is NULL!") );
		return E_FAIL;
	}

	ALLVERTEX* pVertex;
	BYTE* pVertices;
	if ( FAILED(hr = pVB->Lock(NULL, NULL, &pVertices, NULL)) )
		return hr;

	WORD* pIndices;
	if ( FAILED(hr = pIB->Lock(NULL, NULL, (BYTE**)&pIndices, NULL)) )
		return hr;

	INT	vertex = 0;
	for ( INT y=0; y<numVertsY; y++ )
		for ( INT x=0; x<numVertsX; x++ )
		{
			pVertex		= (ALLVERTEX*)( pVertices + (y*numVertsX*dwStride + x*dwStride) );

			pVertex->x	= x * fQuadWidth + fOffsetX;
			pVertex->y	= 0.0f;
			pVertex->z	= y * fQuadHeight + fOffsetY;

			if ( D3DFVF_NORMAL & dwFVF )
			{
				pVertex->nx	= 0.0f;
				pVertex->ny	= 1.0f;
				pVertex->nz	= 0.0f;
			}

			if ( D3DFVF_DIFFUSE & dwFVF )
				pVertex->diffuse = 0xffffffff;

			if ( D3DFVF_TEX1 & dwFVF )
			{
				pVertex->tu	= (FLOAT)x / (numVertsX-1);
				pVertex->tv	= (FLOAT)y / (numVertsY-1);
			}

			if ( x<numVertsX-1 && y<numVertsY-1 )
			{
				*(pIndices+(vertex++)) = ((y+0)*numVertsX) + (x+0);
				*(pIndices+(vertex++)) = ((y+0)*numVertsX) + (x+1);
				*(pIndices+(vertex++)) = ((y+1)*numVertsX) + (x+0);
				*(pIndices+(vertex++)) = ((y+1)*numVertsX) + (x+0);
				*(pIndices+(vertex++)) = ((y+0)*numVertsX) + (x+1);
				*(pIndices+(vertex++)) = ((y+1)*numVertsX) + (x+1);
			}
		}

	pVB->Unlock();
	pIB->Unlock();

	nop();

	return hr;
}




//-----------------------------------------------------------------------------
// Name: SetVBRect()
// Desc: Sets a two-triangle vertex buffer to form the specified rectangle
//-----------------------------------------------------------------------------

HRESULT SetVBRect( LPDIRECT3DVERTEXBUFFER8 pVB, RECT rcRect, D3DCOLOR dwColor )
{
	HRESULT hr = S_OK;
    TTVERTEX*	pVertices;

	if ( !pVB )
	{
		MessageBoxOK( _T("SetVBRect()\nA buffer pointer is NULL!") );
		return E_FAIL;
	}


	if ( FAILED(hr = pVB->Lock (0, 0, (BYTE**)&pVertices, NULL)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	(pVertices+0)->x = (FLOAT)rcRect.left;   // topleft
	(pVertices+0)->y = (FLOAT)rcRect.top;

	(pVertices+1)->x = (FLOAT)rcRect.right;  // topright
	(pVertices+1)->y = (FLOAT)rcRect.top;

	(pVertices+2)->x = (FLOAT)rcRect.right;	// bottomright
	(pVertices+2)->y = (FLOAT)rcRect.bottom;

    (pVertices+3)->x = (FLOAT)rcRect.left;   // bottomleft
	(pVertices+3)->y = (FLOAT)rcRect.bottom;

	pVB->Unlock();
	
	return hr;
}


//-----------------------------------------------------------------------------
// Name: ShowBlurTexture()
// Desc: Shows a texture, blurred by drawing several transparent copies with an offset.
//-----------------------------------------------------------------------------

HRESULT ShowBlurTexture( LPDIRECT3DTEXTURE8 pTexture, FLOAT fOffsetX, FLOAT fOffsetY, FLOAT fWidth, FLOAT fHeight, FLOAT fBlurIntensity, FLOAT fBlurSize, FLOAT fAlpha, FLOAT fTileFactor, BOOL bForeground )
{
    HRESULT hr = S_OK;

	ShowTexture( pTexture, fOffsetX, fOffsetY, fWidth, fHeight, fAlpha, fTileFactor, bForeground );

/*	for ( FLOAT x=-fBlurSize; x<fBlurSize; x++ )	// Try 4 layers of transparent textures for blur
		for ( FLOAT y=-fBlurSize; y<fBlurSize; y++ )
		{
			ShowTexture( pTexture, fOffsetX+x,	fOffsetY+y,	fWidth, fHeight, fAlpha*(((1.0f - fabs(x)/fBlurSize)+(1.0f - fabs(y)/fBlurSize)/2.0f)), fTileFactor, bForeground );
		}
*/
	return hr;
}



//-----------------------------------------------------------------------------
// Name: ShowOrigin() NOT WORKING
// Desc: Draws each axis from the point 0,0,0
//-----------------------------------------------------------------------------

HRESULT ShowOrigin()
{
    HRESULT hr = S_OK;
	LPDIRECT3DVERTEXBUFFER8 pVB = NULL;
	
/*	LVERTEX vTable[] = 
	{
		{-50.0f,  0.0f,  0.0f, 0xff000000 },
		{ 50.0f,  0.0f,  0.0f, 0xffffffff },
		{  0.0f,-50.0f,  0.0f, 0xff000000 },
		{  0.0f, 50.0f,  0.0f, 0xffffffff },
		{  0.0f,  0.0f,-50.0f, 0xff000000 },
		{  0.0f,  0.0f, 50.0f, 0xffffffff },
	};

	if ( FAILED(hr = g_pd3dDevice->CreateVertexBuffer(sizeof(vTable), NULL, D3DFVF_LVERTEX, D3DPOOL_MANAGED, &pVB)) )
		return hr;

	LVERTEX* pVertices = NULL;
	if ( FAILED(hr = pVB->Lock(NULL, NULL, (BYTE**)&pVertices, NULL)) )
		return hr;

	memcpy( pVertices, vTable, sizeof(vTable) );
	pVB->Unlock();

	g_pd3dDevice->SetVertexShader( D3DFVF_LVERTEX );
	g_pd3dDevice->SetStreamSource( 0, pVB, sizeof(LVERTEX) );

	g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
	g_pd3dDevice->SetMaterial( NULL );

	if ( FAILED(hr = g_pd3dDevice->DrawPrimitive(D3DPT_LINELIST, 0, 3)) )
		return hr;
*/
	SAFE_RELEASE( pVB );

	return hr;
}




//-----------------------------------------------------------------------------
// Name: ShowTexture()
// Desc: Creates a 2D quad and renders it with texture. Supports tiling.
//-----------------------------------------------------------------------------

HRESULT ShowTexture( LPDIRECT3DTEXTURE8 pTexture, FLOAT fOffsetX, FLOAT fOffsetY, FLOAT fWidth, FLOAT fHeight, FLOAT fAlpha, FLOAT fTileFactor, BOOL bForeground )
{
    HRESULT hr = S_OK;
	D3DSURFACE_DESC sdDesc;
	INT width;
	INT height;
	FLOAT fZdepth;

	if ( fAlpha == ALPHA_NONE )
		return S_OK;

	if ( fWidth == 0.0f && fHeight == 0.0f )
	{
		if ( !pTexture )
		{
			MessageBoxOK( _T("ShowTexure()\nTexture is NULL!") );
			return E_FAIL;
		}
		
		pTexture->GetLevelDesc( 0, &sdDesc );
		width	= (INT)(sdDesc.Width);
		height	= (INT)(sdDesc.Height);

	}
	else
	{
		width	= (INT)fWidth;
		height	= (INT)fHeight;
	}

	if ( bForeground )
		fZdepth = 0.0f;
	else
		fZdepth = 1.0f;

	TTVERTEX vTable[] = 
	{
		{ (FLOAT)fOffsetX,		(FLOAT)fOffsetY,		fZdepth, 1.0f, D3DCOLOR_ARGB((BYTE)fAlpha,255,255,255), 0.0f*fTileFactor, 0.0f*fTileFactor	},
		{ (FLOAT)fOffsetX+width,(FLOAT)fOffsetY,		fZdepth, 1.0f, D3DCOLOR_ARGB((BYTE)fAlpha,255,255,255), 1.0f*fTileFactor, 0.0f*fTileFactor	},
		{ (FLOAT)fOffsetX+width,(FLOAT)fOffsetY+height, fZdepth, 1.0f, D3DCOLOR_ARGB((BYTE)fAlpha,255,255,255), 1.0f*fTileFactor, 1.0f*fTileFactor	},
		{ (FLOAT)fOffsetX,		(FLOAT)fOffsetY+height,	fZdepth, 1.0f, D3DCOLOR_ARGB((BYTE)fAlpha,255,255,255), 0.0f*fTileFactor, 1.0f*fTileFactor	},
	};


	//================  SET VEREX BUFFER FOR TEXTURE  =====================
	
	// Fill vertex buffer with data
	TTVERTEX* pVertices;
	if ( FAILED(hr = g_pvbTexture->Lock(0, sizeof(vTable), (BYTE**)&pVertices, 0)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}
		memcpy( pVertices, vTable, sizeof(vTable) );	// Copy vertextable to vertexbuffer

	g_pvbTexture->Unlock();

	g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, FALSE );

	g_pd3dDevice->SetTexture( 0, pTexture );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,	 D3DTOP_SELECTARG1 );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );

	if ( fAlpha == ALPHA_FULL )
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,	D3DTOP_SELECTARG1 );
	else
	{
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,   D3DTOP_MODULATE );
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE );
	}

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE );

	DWORD dwCullMode;
	g_pd3dDevice->GetRenderState( D3DRS_CULLMODE, &dwCullMode );
	g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );
	g_pd3dDevice->SetStreamSource( 0, g_pvbTexture, sizeof(TTVERTEX) );
	g_pd3dDevice->SetVertexShader( D3DFVF_TTVERTEX );

	if ( FAILED(hr = g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN, 0, 2)) )	// Draw quad
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

    g_pd3dDevice->SetTexture( 0, NULL );
	g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, dwCullMode );

	return hr;
}



//-----------------------------------------------------------------------------
// Name: ShowTextureTile()
// Desc: Creates a 2D quad and renders it with texture. Supports tiling, with
//		 X and Y seperately defined.
//-----------------------------------------------------------------------------

HRESULT ShowTextureTile( LPDIRECT3DTEXTURE8 pTexture, FLOAT fOffsetX, FLOAT fOffsetY, FLOAT fWidth, FLOAT fHeight, FLOAT fAlpha, FLOAT fTileFactorX, FLOAT fTileFactorY, BOOL bForeground )
{
    HRESULT hr = S_OK;
	D3DSURFACE_DESC sdDesc;
	INT width;
	INT height;
	FLOAT fZdepth;

	if ( fAlpha == ALPHA_NONE )
		return S_OK;

	if ( fWidth == 0.0f && fHeight == 0.0f )
	{
		if ( !pTexture )
		{
			MessageBoxOK( _T("ShowTexure()\nTexture is NULL!") );
			return E_FAIL;
		}
		
		pTexture->GetLevelDesc( 0, &sdDesc );
		width	= (INT)(sdDesc.Width);
		height	= (INT)(sdDesc.Height);

	}
	else
	{
		width	= (INT)fWidth;
		height	= (INT)fHeight;
	}

	if ( bForeground )
		fZdepth = 0.0f;
	else
		fZdepth = 1.0f;

	TTVERTEX vTable[] = 
	{
		{ (FLOAT)fOffsetX,		(FLOAT)fOffsetY,		fZdepth, 1.0f, D3DCOLOR_ARGB((BYTE)fAlpha,255,255,255), 0.0f*fTileFactorX, 0.0f*fTileFactorY	},
		{ (FLOAT)fOffsetX+width,(FLOAT)fOffsetY,		fZdepth, 1.0f, D3DCOLOR_ARGB((BYTE)fAlpha,255,255,255), 1.0f*fTileFactorX, 0.0f*fTileFactorY	},
		{ (FLOAT)fOffsetX+width,(FLOAT)fOffsetY+height, fZdepth, 1.0f, D3DCOLOR_ARGB((BYTE)fAlpha,255,255,255), 1.0f*fTileFactorX, 1.0f*fTileFactorY	},
		{ (FLOAT)fOffsetX,		(FLOAT)fOffsetY+height,	fZdepth, 1.0f, D3DCOLOR_ARGB((BYTE)fAlpha,255,255,255), 0.0f*fTileFactorX, 1.0f*fTileFactorY	},
	};


	//================  SET VEREX BUFFER FOR TEXTURE  =====================
	
	// Fill vertex buffer with data
	TTVERTEX* pVertices;
	if ( FAILED(hr = g_pvbTexture->Lock(0, sizeof(vTable), (BYTE**)&pVertices, 0)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}
		memcpy( pVertices, vTable, sizeof(vTable) );	// Copy vertextable to vertexbuffer

	g_pvbTexture->Unlock();

	g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, FALSE );

	g_pd3dDevice->SetTexture( 0, pTexture );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,	 D3DTOP_SELECTARG1 );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );

	if ( fAlpha == ALPHA_FULL )
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,	D3DTOP_SELECTARG1 );
	else
	{
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,   D3DTOP_MODULATE );
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE );
	}

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE );

	DWORD dwCullMode;
	g_pd3dDevice->GetRenderState( D3DRS_CULLMODE, &dwCullMode );
	g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );
	g_pd3dDevice->SetStreamSource( 0, g_pvbTexture, sizeof(TTVERTEX) );
	g_pd3dDevice->SetVertexShader( D3DFVF_TTVERTEX );

	if ( FAILED(hr = g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN, 0, 2)) )	// Draw quad
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

    g_pd3dDevice->SetTexture( 0, NULL );
	g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, dwCullMode );

	return hr;
}




//-----------------------------------------------------------------------------
// Name: ShowTextureEx()
// Desc: Same as ShowTexture(), but this one allows you to define a FRECT for the source
//		 but that disallows tiling.
//-----------------------------------------------------------------------------

HRESULT ShowTextureEx( LPDIRECT3DTEXTURE8 pTexture, FRECT frcSrc, D3DCOLOR vertCol[4], FLOAT fOffsetX, FLOAT fOffsetY, FLOAT fWidth, FLOAT fHeight, FLOAT fAlpha )
{
    HRESULT hr = S_OK;
	D3DSURFACE_DESC sdDesc;
	INT width;
	INT height;
	FLOAT fOffsetTU;
	FLOAT fOffsetTV;
	FLOAT fScaleTU;
	FLOAT fScaleTV;

	if ( fAlpha == ALPHA_NONE )
		return S_OK;

	if ( !pTexture )
	{
		MessageBoxOK( _T("ShowTextureEx()\npTexture is NULL!") );
		return E_FAIL;
	}

	pTexture->GetLevelDesc( 0, &sdDesc );
	width	= (INT)(sdDesc.Width);
	height	= (INT)(sdDesc.Height);

	if ( frcSrc.right && frcSrc.bottom )	// FRECT is a valid parameter, because both width and height have been specified
	{
		fOffsetTU = frcSrc.left   /	(FLOAT)width;
		fOffsetTV = frcSrc.top	  /	(FLOAT)height;
		fScaleTU  = frcSrc.right  /	(FLOAT)width;
		fScaleTV  = frcSrc.bottom / (FLOAT)height;
	}
	else	// width and height are 0, no offset or scaling is used on texture coords
	{
		fOffsetTU = 0.0f;
		fOffsetTV = 0.0f;
		fScaleTU  = 1.0f;
		fScaleTV  = 1.0f;
	}

	if ( fWidth || fHeight )
	{
		width	= (INT)fWidth;
		height	= (INT)fHeight;
	}


	TTVERTEX vTable[] = 
	{
		{ (FLOAT)fOffsetX,		(FLOAT)fOffsetY,		0.1f, 1.0f, vertCol[0], 0.0f*fScaleTU+fOffsetTU, 0.0f*fScaleTV+fOffsetTV },
		{ (FLOAT)fOffsetX+width,(FLOAT)fOffsetY,		0.1f, 1.0f, vertCol[1], 1.0f*fScaleTU+fOffsetTU, 0.0f*fScaleTV+fOffsetTV },
		{ (FLOAT)fOffsetX+width,(FLOAT)fOffsetY+height,	0.1f, 1.0f, vertCol[2], 1.0f*fScaleTU+fOffsetTU, 1.0f*fScaleTV+fOffsetTV },
		{ (FLOAT)fOffsetX,		(FLOAT)fOffsetY+height,	0.1f, 1.0f, vertCol[3], 0.0f*fScaleTU+fOffsetTU, 1.0f*fScaleTV+fOffsetTV },
	};


	//================  SET VEREX BUFFER FOR TEXTURE  =====================
	
	// Fill vertex buffer with data
	TTVERTEX* pVertices;
	if ( FAILED(hr = g_pvbTexture->Lock(0, sizeof(vTable), (BYTE**)&pVertices, 0)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}
		memcpy( pVertices, vTable, sizeof(vTable) );	// Copy vertextable to vertexbuffer

	g_pvbTexture->Unlock();

	g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, FALSE );

	g_pd3dDevice->SetTexture( 0, pTexture );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,	 D3DTOP_MODULATE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE );

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,   D3DTOP_MODULATE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE );

	DWORD dwCullMode;
	g_pd3dDevice->GetRenderState( D3DRS_CULLMODE, &dwCullMode );
	g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );

	g_pd3dDevice->SetStreamSource( 0, g_pvbTexture, sizeof(TTVERTEX) );
	g_pd3dDevice->SetVertexShader( D3DFVF_TTVERTEX );

	if ( FAILED(hr = g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN, 0, 2)) )	// Draw quad
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

    g_pd3dDevice->SetTexture( 0, NULL );
	g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, dwCullMode );

	return hr;
}




//-----------------------------------------------------------------------------
// Name: ShowTextureExTile()
// Desc: Same as ShowTexture(), but with vertex color control and tile parameters
//		 for both tu and tv seperately.
//-----------------------------------------------------------------------------

HRESULT ShowTextureExTile( LPDIRECT3DTEXTURE8 pTexture, D3DCOLOR vertCol[4], FLOAT fOffsetX, FLOAT fOffsetY, FLOAT fWidth, FLOAT fHeight, FLOAT fTileTU, FLOAT fTileTV, FLOAT fOffsetTU, FLOAT fOffsetTV, FLOAT fAlpha )
{
    HRESULT hr = S_OK;
	D3DSURFACE_DESC sdDesc;
	INT width;
	INT height;

	if ( fAlpha == ALPHA_NONE )
		return S_OK;

	if ( !pTexture )
	{
		MessageBoxOK( _T("ShowTextureEx()\npTexture is NULL!") );
		return E_FAIL;
	}

	pTexture->GetLevelDesc( 0, &sdDesc );
	width	= (INT)(sdDesc.Width);
	height	= (INT)(sdDesc.Height);



	if ( fWidth || fHeight )
	{
		width	= (INT)fWidth;
		height	= (INT)fHeight;
	}


	TTVERTEX vTable[] = 
	{
		{ (FLOAT)fOffsetX,		(FLOAT)fOffsetY,		0.1f, 1.0f, vertCol[0], 0.0f*fTileTU+fOffsetTU, 0.0f*fTileTV+fOffsetTV },
		{ (FLOAT)fOffsetX+width,(FLOAT)fOffsetY,		0.1f, 1.0f, vertCol[1], 1.0f*fTileTU+fOffsetTU, 0.0f*fTileTV+fOffsetTV },
		{ (FLOAT)fOffsetX+width,(FLOAT)fOffsetY+height,	0.1f, 1.0f, vertCol[2], 1.0f*fTileTU+fOffsetTU, 1.0f*fTileTV+fOffsetTV },
		{ (FLOAT)fOffsetX,		(FLOAT)fOffsetY+height,	0.1f, 1.0f, vertCol[3], 0.0f*fTileTU+fOffsetTU, 1.0f*fTileTV+fOffsetTV },
	};


	//================  SET VEREX BUFFER FOR TEXTURE  =====================
	
	// Fill vertex buffer with data
	TTVERTEX* pVertices;
	if ( FAILED(hr = g_pvbTexture->Lock(0, sizeof(vTable), (BYTE**)&pVertices, 0)) )
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}
		memcpy( pVertices, vTable, sizeof(vTable) );	// Copy vertextable to vertexbuffer

	g_pvbTexture->Unlock();

	g_pd3dDevice->SetRenderState( D3DRS_FOGENABLE, FALSE );

	g_pd3dDevice->SetTexture( 0, pTexture );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,	 D3DTOP_MODULATE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE );

	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,   D3DTOP_MODULATE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE );

	DWORD dwCullMode;
	g_pd3dDevice->GetRenderState( D3DRS_CULLMODE, &dwCullMode );
	g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );

	g_pd3dDevice->SetStreamSource( 0, g_pvbTexture, sizeof(TTVERTEX) );
	g_pd3dDevice->SetVertexShader( D3DFVF_TTVERTEX );

	if ( FAILED(hr = g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN, 0, 2)) )	// Draw quad
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

    g_pd3dDevice->SetTexture( 0, NULL );
	g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, dwCullMode );

	return hr;
}



//-----------------------------------------------------------------------------
// Name: ShowTextureVB()
// Desc: Same as ShowTexture(), but with multiple quads to create 2D displacement effects.
//-----------------------------------------------------------------------------

HRESULT ShowTextureVB( LPDIRECT3DTEXTURE8 pTexture, LPDIRECT3DVERTEXBUFFER8 pVB, INT numQuadsX, INT numQuadsY, FLOAT fAlpha=255.0f, FLOAT fTileFactor=1.0f )
{
	HRESULT hr = S_OK;

	if ( fAlpha == ALPHA_NONE )
		return S_OK;

	if ( !pTexture )
	{
		MessageBoxOK( _T("ShowTextureVB()\npTexture is NULL!") );
		return E_FAIL;
	}

	if ( !pVB )
	{
		MessageBoxOK( _T("ShowTextureVB()\nA buffer pointer is NULL!") );
		return E_FAIL;
	}

	g_pd3dDevice->SetTexture( 0, pTexture );
	g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE );

	g_pd3dDevice->SetStreamSource( 0, pVB, sizeof(TTVERTEX) );
	g_pd3dDevice->SetVertexShader( D3DFVF_TTVERTEX );
	

	if ( fAlpha == ALPHA_FULL )
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,	D3DTOP_SELECTARG1 );
	else
	{
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,   D3DTOP_MODULATE );
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE );
	}


	for ( INT i=0; i<numQuadsX*numQuadsY; i++ )
	{
		if ( FAILED(hr = g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN, i*4, 2)) )	// Draw quads
		{
			DisplayErrorMsg2( hr, NULL );
			return hr;
		}
	}

    g_pd3dDevice->SetTexture( 0, NULL );

	return hr;
}



//-----------------------------------------------------------------------------
// Name: ShowWaypoints() NOT WORKING
// Desc: Draws a line between the waypoints specified.
//-----------------------------------------------------------------------------

HRESULT ShowWaypoints( WAYPOINT3D* pWaypoint, INT iNumWaypoints, FLOAT fAlpha )
{
	HRESULT hr = S_OK;
	LPDIRECT3DVERTEXBUFFER8 pVB = NULL;

/*	if ( pWaypoint == NULL )
	{
		MessageBoxOK( _T("pWaypoint is false!") );
		return E_FAIL;
	}

	if ( fAlpha == ALPHA_NONE )
		return S_OK;

//NLTVERTEX vTable[TUNNEL_MAX_WAYPOINTS];
//	ZeroMemory( vTable, sizeof(vTable) );

	NLTVERTEX vTable[] = 
	{
		{-50.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0xffffffff, 0.0f, 0.0f },
		{ 50.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0xffffffff, 0.0f, 0.0f },
		{  0.0f,-50.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0xffffffff, 0.0f, 0.0f },
		{  0.0f, 50.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0xffffffff, 0.0f, 0.0f },
		{  0.0f,  0.0f,-50.0f, 0.0f, 0.0f, 0.0f, 0xffffffff, 0.0f, 0.0f },
		{  0.0f,  0.0f, 50.0f, 0.0f, 0.0f, 0.0f, 0xffffffff, 0.0f, 0.0f },
	};
	iNumWaypoints = 6;

	for ( INT i=0; i<iNumWaypoints; i++ )
	{
		vTable[i].x	 = (pWaypoint+i)->v.x;	
		vTable[i].y  = (pWaypoint+i)->v.y;
		vTable[i].z  = (pWaypoint+i)->v.z;
		vTable[i].diffuse = 0xffffffff;		// Ignore normals and tu,tv because we don't need them
	}



	if ( FAILED(hr = g_pd3dDevice->CreateVertexBuffer(iNumWaypoints*sizeof(NLTVERTEX), NULL, D3DFVF_NLTVERTEX, D3DPOOL_MANAGED, &pVB)) )
		return hr;	


	NLTVERTEX* pVertices;
	if ( FAILED(hr = pVB->Lock(0, NULL, (BYTE**)&pVertices, NULL)) )
		return hr;

	memcpy( pVertices, vTable, iNumWaypoints*sizeof(NLTVERTEX) );
	pVB->Unlock();




	if ( fAlpha == ALPHA_FULL )
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,	D3DTOP_SELECTARG1 );
	else
	{
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,   D3DTOP_MODULATE );
		g_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE );
	}

	g_pd3dDevice->SetTexture( 0, NULL );
	g_pd3dDevice->SetStreamSource( 0, pVB, sizeof(NLTVERTEX) );
	g_pd3dDevice->SetVertexShader( D3DFVF_NLTVERTEX );
	g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );

	g_pd3dDevice->SetTransform( D3DTS_WORLD, &g_matIdentity );


	if ( FAILED(hr = g_pd3dDevice->DrawPrimitive(D3DPT_LINESTRIP, 0, iNumWaypoints)) )	// Draw quads
	{
		DisplayErrorMsg2( hr, NULL );
		return hr;
	}

	g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, TRUE );
*/
	SAFE_RELEASE( pVB );

	return hr;
}





//-----------------------------------------------------------------------------
// Name: SizeMesh()
// Desc: Scales a mesh to a given maxradius.
//-----------------------------------------------------------------------------

HRESULT SizeMesh( CD3DMesh* pMesh, LPDIRECT3DVERTEXBUFFER8 pVB, FLOAT fNewRadius )
{
	HRESULT hr = S_OK;

	BYTE* pVertex = NULL;
	BYTE* pVertices = NULL;
	DWORD dwFVF = pMesh->GetSysMemMesh()->GetFVF();
	DWORD dwStride = D3DXGetFVFVertexSize( dwFVF );
	DWORD dwNumVerts = pMesh->GetSysMemMesh()->GetNumVertices();
	D3DXVECTOR3 vCentre;
	FLOAT fRadius;
	

	if ( !pVB )
	{
		MessageBoxOK( _T("SizeMesh()\nA buffer pointer is NULL!") );
		return E_FAIL;
	}

	if ( FAILED(pVB->Lock(0, NULL, &pVertices, NULL)) )
		return E_FAIL;

	D3DXComputeBoundingSphere( pVertices, dwNumVerts, dwFVF, &vCentre, &fRadius );

	INT iVert=0;
	for ( DWORD v=0; v<dwNumVerts; v++ )
	{
		iVert = v*dwStride;
		pVertex = pVertices + iVert;
		((ALLVERTEX*)pVertex)->x = (((ALLVERTEX*)pVertex)->x - vCentre.x) * (fNewRadius / fRadius);
		((ALLVERTEX*)pVertex)->y = (((ALLVERTEX*)pVertex)->y - vCentre.y) * (fNewRadius / fRadius);
		((ALLVERTEX*)pVertex)->z = (((ALLVERTEX*)pVertex)->z - vCentre.z) * (fNewRadius / fRadius);
	}

	pVB->Unlock();	

	return hr;
}



//-----------------------------------------------------------------------------
// Name: SizeMeshFVF()
// Desc: Scales a mesh to a given maxradius.
//-----------------------------------------------------------------------------

HRESULT SizeMeshFVF( LPD3DXMESH pMesh, DWORD dwFVF, FLOAT fNewRadius )
{
	HRESULT hr = S_OK;
	LPDIRECT3DVERTEXBUFFER8 pVB = NULL;
	DWORD dwStride = D3DXGetFVFVertexSize( dwFVF );
	DWORD dwNumVerts = pMesh->GetNumVertices();
	D3DXVECTOR3 vCentre;
	FLOAT fRadius;
	
	pMesh->GetVertexBuffer( &pVB );

	if ( !pVB )
	{
		MessageBoxOK( _T("SizeMesh()\nA buffer pointer is NULL!") );
		return E_FAIL;
	}


	BYTE* pVertex = NULL;
	BYTE* pVertices = NULL;

	if ( FAILED(pVB->Lock(0, NULL, &pVertices, NULL)) )
		return E_FAIL;

	D3DXComputeBoundingSphere( pVertices, dwNumVerts, dwFVF, &vCentre, &fRadius );

	INT iVert=0;
	for ( DWORD v=0; v<dwNumVerts; v++ )
	{
		iVert = v*dwStride;
		pVertex = pVertices + iVert;
		((ALLVERTEX*)pVertex)->x = (((ALLVERTEX*)pVertex)->x - vCentre.x) * (fNewRadius / fRadius);
		((ALLVERTEX*)pVertex)->y = (((ALLVERTEX*)pVertex)->y - vCentre.y) * (fNewRadius / fRadius);
		((ALLVERTEX*)pVertex)->z = (((ALLVERTEX*)pVertex)->z - vCentre.z) * (fNewRadius / fRadius);
	}

	pVB->Unlock();	

	return hr;
}



//-----------------------------------------------------------------------------
// Name: SplashScreen1()
// Desc: Runs the splashscreen scene. Bitmap is currently 1024x318 in original 
//		 dimensions (x256 due to hardware caps).
//-----------------------------------------------------------------------------

HRESULT SplashScreen1( FLOAT fLocalTime )
{
	HRESULT hr = S_OK;
	FLOAT fTexAspect = 1024.0f / 318.0f;

	D3DCOLOR colTable[4] = 
	{
		{ 0xffffffff },
		{ 0xffffffff },
		{ 0xffffffff },
		{ 0xffffffff },
	};

	D3DCOLOR topVertCol[4] = 
	{
		D3DCOLOR_ARGB( 0x8f, 0xff, 0xff, 0xff ),	// top left
		D3DCOLOR_ARGB( 0x8f, 0xff, 0xff, 0xff ),	// top right
		D3DCOLOR_ARGB( 0x10, 0xff, 0xff, 0xff ),	// bottom right
		D3DCOLOR_ARGB( 0x10, 0xff, 0xff, 0xff ),	// bottom left
	};

	D3DCOLOR bleftVertCol[4] = 
	{
		D3DCOLOR_ARGB( 0x10, 0xff, 0xff, 0xff ),
		D3DCOLOR_ARGB( 0x10, 0xff, 0xff, 0xff ),
		D3DCOLOR_ARGB( 0x20, 0xff, 0xff, 0xff ),
		D3DCOLOR_ARGB( 0x8f, 0xff, 0xff, 0xff ),
	};

	D3DCOLOR brightVertCol[4] = 
	{
		D3DCOLOR_ARGB( 0x10, 0xff, 0xff, 0xff ),
		D3DCOLOR_ARGB( 0x10, 0xff, 0xff, 0xff ),
		D3DCOLOR_ARGB( 0x8f, 0xff, 0xff, 0xff ),
		D3DCOLOR_ARGB( 0x20, 0xff, 0xff, 0xff ),
	};


	FRECT frcMain	= { 0.0f,	225.0f,			1024.0f,	318.0f };
	FRECT frcTop	= { 0.0f,	0.0f,			1024.0f,	224.0f };
	FRECT frcBLeft	= { 0.0f,	768.0f-224.0f,	390.0f,		224.0f };
	FRECT frcBRight	= { 390.0f, 768.0f-224.0f,	634.0f,		224.0f };

	FRECT frcTopSrc =	  { 250.0f, 100.0f, fTexAspect*100.0f,  100.0f };
	FRECT frcBLeftSrc =	  { 620.0f,  25.0f, fTexAspect*50.0f,    50.0f };
	FRECT frcBRightSrc =  { 425.0f,  50.0f, fTexAspect*63.0f,    63.0f };


	frcTopSrc.left	  = LinearChange( 250.0f, 450.0f, TIME_SPLASH01, fLocalTime, TIME_SPLASH01 + 25.0f );
	frcTopSrc.top	  = LinearChange( 100.0f, 150.0f, TIME_SPLASH01, fLocalTime, TIME_SPLASH01 + 25.0f );

	frcBLeftSrc.left  = LinearChange( 620.0f, 580.0f, TIME_SPLASH01, fLocalTime, TIME_SPLASH01 + 25.0f );
	frcBLeftSrc.top	  = LinearChange(  25.0f, 150.0f, TIME_SPLASH01, fLocalTime, TIME_SPLASH01 + 25.0f );

	frcBRightSrc.left = LinearChange( 425.0f, 725.0f, TIME_SPLASH01, fLocalTime, TIME_SPLASH01 + 25.0f );
	frcBRightSrc.top  = LinearChange(  50.0f,  30.0f, TIME_SPLASH01, fLocalTime, TIME_SPLASH01 + 25.0f );

	g_pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	g_pd3dDevice->SetRenderState( D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA );	


	ShowTexture( g_ptexSplash1, frcMain.left * g_fScaleX, frcMain.top * g_fScaleY,	frcMain.right * g_fScaleX, frcMain.bottom * g_fScaleY, ALPHA_FULL, 1.0f );

	ShowTextureEx( g_ptexSplash1, frcTopSrc,	 topVertCol,	frcTop.left		* g_fScaleX, frcTop.top	   * g_fScaleY, frcTop.right	* g_fScaleX, frcTop.bottom	  * g_fScaleY, ALPHA_FULL );
	ShowTextureEx( g_ptexSplash1, frcBLeftSrc,	 bleftVertCol,	frcBLeft.left	* g_fScaleX, frcBLeft.top  * g_fScaleY, frcBLeft.right	* g_fScaleX, frcBLeft.bottom  * g_fScaleY, ALPHA_FULL );
	ShowTextureEx( g_ptexSplash1, frcBRightSrc, brightVertCol, frcBRight.left	* g_fScaleX, frcBRight.top * g_fScaleY, frcBRight.right	* g_fScaleX, frcBRight.bottom * g_fScaleY, ALPHA_FULL );

	ShowTextureExTile( g_ptexShadow, colTable, 0.0f, 0.0f, g_fWindowX, 225.0f, 2.0f, 1.0f, -g_fDTime*0.1f, 0.0f, 100.0f );
	ShowTextureExTile( g_ptexShadow, colTable, 0.0f, g_fWindowY-225.0f, g_fWindowX, 225.0f, 2.0f, 1.0f, -g_fDTime*0.2f, 0.0f, 100.0f );

	FLOAT x;
	FLOAT y;
	FLOAT fAlpha;

	// First roll
	FLOAT fTimeStart = TIME_SPLASH01;
	FLOAT fTimeEnd = TIME_SPLASH01+5.0f;
	if ( fLocalTime >= fTimeStart && fLocalTime < fTimeEnd )
	{
		fAlpha = LinearChange(255.0f, 0.0f, fTimeStart, fLocalTime, fTimeEnd );

		x = LinearChange(-100.0f, 850.0f, fTimeStart, fLocalTime, fTimeEnd );
		DrawLine( x, 0.0f, x, g_fWindowY, g_dwColWhite, fAlpha );

		x = LinearChange(0.0f, 750.0f, fTimeStart, fLocalTime, fTimeEnd );
		DrawLine( x, 0.0f, x, g_fWindowY, g_dwColWhite, fAlpha );
	}
 
	fTimeStart = TIME_SPLASH01+0.5f;
	fTimeEnd = TIME_SPLASH01+6.5f;
	if ( fLocalTime >= fTimeStart && fLocalTime < fTimeEnd )
	{
		fAlpha = LinearChange(255.0f, 0.0f, fTimeStart, fLocalTime, fTimeEnd);

		y = LinearChange(0.0f, g_fWindowY, fTimeStart, fLocalTime, fTimeEnd);
		DrawLine( 0.0f, y, g_fWindowX, y, g_dwColWhite, fAlpha );

		y = LinearChange(0.0f, g_fWindowY+50.0f, fTimeStart, fLocalTime, fTimeEnd);
		DrawLine( 0.0f, y, g_fWindowX, y, g_dwColWhite, fAlpha );
	}

	// Second roll
	fTimeStart = TIME_SPLASH01+8.0f;
	fTimeEnd = TIME_SPLASH01+13.0f;
	if ( fLocalTime >= fTimeStart && fLocalTime < fTimeEnd )
	{
		fAlpha = LinearChange(255.0f, 0.0f, fTimeStart, fLocalTime, fTimeEnd );

		x = LinearChange(700.0f, 0.0f, fTimeStart, fLocalTime, fTimeEnd );
		DrawLine( x, 0.0f, x, g_fWindowY, g_dwColWhite, fAlpha );

		x = LinearChange(850.0f, -200.0f, fTimeStart, fLocalTime, fTimeEnd );
		DrawLine( x, 0.0f, x, g_fWindowY, g_dwColWhite, fAlpha );
	}
 
	fTimeStart = TIME_SPLASH01+8.5f;
	fTimeEnd = TIME_SPLASH01+14.5f;
	if ( fLocalTime >= fTimeStart && fLocalTime < fTimeEnd )
	{
		fAlpha = LinearChange(255.0f, 0.0f, fTimeStart, fLocalTime, fTimeEnd);

		y = LinearChange(g_fWindowY, 0.0f, fTimeStart, fLocalTime, fTimeEnd);
		DrawLine( 0.0f, y, g_fWindowX, y, g_dwColWhite, fAlpha );

		y = LinearChange(g_fWindowY+50.0f, 0.0f, fTimeStart, fLocalTime, fTimeEnd);
		DrawLine( 0.0f, y, g_fWindowX, y, g_dwColWhite, fAlpha );
	}

	// Third roll
	fTimeStart = TIME_SPLASH01+16.0f;
	fTimeEnd = TIME_SPLASH01+20.0f;
	if ( fLocalTime >= fTimeStart && fLocalTime < fTimeEnd )
	{
		fAlpha = LinearChange(255.0f, 0.0f, fTimeStart, fLocalTime, fTimeEnd);

		y = LinearChange(-100.0f, 512.0f, fTimeStart, fLocalTime, fTimeEnd);
		DrawLine( 0.0f, y, g_fWindowX, y, g_dwColWhite, fAlpha );

		y = LinearChange(0.0f, 400.0f, fTimeStart, fLocalTime, fTimeEnd);
		DrawLine( 0.0f, y, g_fWindowX, y, g_dwColWhite, fAlpha );
	}


	// Logo fading
	fTimeStart = TIME_SPLASH01+7.0f;
	fTimeEnd = TIME_SPLASH01+19.2f;
	if ( fLocalTime >= fTimeStart && fLocalTime < fTimeEnd )
	{
		ShowTexture( g_ptexLogo, 100.0f, 75.0f, g_fWindowX-200.0f, g_fWindowY-100.0f, 
			LinearChange( 0.0f, 255.0f, fTimeStart, fLocalTime, fTimeStart+2.0f) );
	}

	fTimeStart = TIME_SPLASH01+19.2f;
	fTimeEnd = TIME_SPLASH01+21.0f;
	if ( fLocalTime >= fTimeStart && fLocalTime < fTimeEnd )
	{
		ShowTexture( g_ptexLogo, 100.0f, 75.0f, g_fWindowX-200.0f, g_fWindowY-100.0f, 
			LinearChange( 255.0f, 0.0f, fTimeStart, fLocalTime, fTimeStart+2.0f) );
	}


	Fade( D3DCOLOR_ARGB(0x00,0x00,0x00,0x00), D3DCOLOR_ARGB(0xa0,0x00,0x00,0x00), TIME_SCENE02-0.5f, g_fDTime, TIME_SCENE02-0.10f );
	Fade( D3DCOLOR_ARGB(0x00,0xff,0xff,0xff), D3DCOLOR_ARGB(0xff,0xff,0xff,0xff), TIME_SCENE02-0.10f, g_fDTime, TIME_SCENE02 );

	return hr;
}



//-----------------------------------------------------------------------------
// Name: SplashScreen2()
// Desc: Runs the splashscreen scene. 
//-----------------------------------------------------------------------------

HRESULT SplashScreen2( FLOAT fLocalTime )
{
	HRESULT hr = S_OK;

	FLOAT width = 2223.0f;	// Bitmap is currently 2223x428 in original 
	FLOAT height = 428.0f;	// dimensions (though really 2048x512 due to hardware caps).

#ifdef PLAY_SCENE06

	FRECT frcMain	= { 0.0f, 170.0f, width, height };

	frcMain.left = LinearChange( 0.0f, (1024-width), 0.0f, fLocalTime, TIME_SCENE07-TIME_SCENE06 );

	ShowTexture( g_ptexSplash2, frcMain.left * g_fScaleX, frcMain.top * g_fScaleY,	frcMain.right * g_fScaleX, frcMain.bottom * g_fScaleY, ALPHA_FULL, 1.0f );

	D3DCOLOR colTable[4] = 
	{
		{ 0x40ffffff },
		{ 0x40ffffff },
		{ 0x40ffffff },
		{ 0x40ffffff },
	};

	D3DCOLOR colTable2[4] = 
	{
		{ 0xffffffff },
		{ 0xffffffff },
		{ 0xffffffff },
		{ 0xffffffff },
	};
	
	// Scrolling symbols
	ShowTextureExTile( g_ptexSymbol1, colTable,  0.0f, 10.0f,				g_fWindowX, 64.0f, 3.0f, 1.0f, -g_fDTime * 0.1f, 0.0f );
	ShowTextureExTile( g_ptexSymbol2, colTable,  0.0f, 40.0f,				g_fWindowX, 64.0f, 3.0f, 1.0f,  g_fDTime * 0.3f, 0.0f );
	ShowTextureExTile( g_ptexSymbol4, colTable,  0.0f, 20.0f,				g_fWindowX, 64.0f, 3.0f, 1.0f, -g_fDTime * 0.2f, 0.0f );
	ShowTextureExTile( g_ptexSymbol3, colTable,  0.0f, g_fWindowY-100.0f,	g_fWindowX, 64.0f, 3.0f, 1.0f, -g_fDTime * 0.2f, 0.0f );
	ShowTextureExTile( g_ptexSymbol4, colTable,  0.0f, g_fWindowY-80.0f,	g_fWindowX, 64.0f, 3.0f, 1.0f, -g_fDTime * 0.1f, 0.0f );
	
	// Shadow
	ShowTextureExTile( g_ptexShadow, colTable2, 0.0f, 0.0f, g_fWindowX, 225.0f, 2.0f, 1.0f, -g_fDTime*0.1f, 0.0f, 200.0f );
	ShowTextureExTile( g_ptexShadow, colTable2, 0.0f, g_fWindowY-225.0f, g_fWindowX, 225.0f, 2.0f, 1.0f, -g_fDTime*0.2f, 0.0f, 200.0f );

#endif
	return hr;
}




//-----------------------------------------------------------------------------
// Name: WinMain()
// Desc: Entry point to the program. Initializes everything, and goes into a
//       message-processing loop. Idle time is used to render the scene.
//-----------------------------------------------------------------------------
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR, INT )
{
	HRESULT hr = S_OK;
	HACCEL	hAccel = LoadAccelerators( NULL, MAKEINTRESOURCE(IDR_MAIN_ACCEL) );

	g_hInst = hInst;
	CoInitialize( NULL );

	INITCOMMONCONTROLSEX icc;	// Initialize DLLs for listview window class (used in dialogboxes)
	icc.dwSize	= sizeof(INITCOMMONCONTROLSEX);		
	icc.dwICC	= ICC_BAR_CLASSES;
	InitCommonControlsEx( &icc );	

    // Register the window class
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, 
                      GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
                      DEF_APPNAME, NULL };
    RegisterClassEx( &wc );

    // Create the application's window
    g_hWnd = CreateWindow( DEF_APPNAME, DEF_APPNAME, 
                              WS_OVERLAPPEDWINDOW, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
                              GetDesktopWindow(), NULL, wc.hInstance, NULL );

	InitApp();

    // Initialize Direct3D
    if( FAILED( InitD3D(g_hWnd)) )
		goto Cleanup;


	// Show the window
    ShowWindow( g_hWnd, SW_SHOWDEFAULT );
    UpdateWindow( g_hWnd );

	if ( FAILED(InitDeviceObjects()) )
		goto Cleanup;

	
    // Enter the message loop
    MSG msg; 
    ZeroMemory( &msg, sizeof(msg) );

	
    while( msg.message!=WM_QUIT )
    {
        if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
        {
			if ( 0 == TranslateAccelerator(g_hWnd, hAccel, &msg) )
			{
				TranslateMessage( &msg );
				DispatchMessage( &msg );
			}
        }
        else
		{
            if ( FAILED(Render()) )
				break;
		}
    }

    // Clean up everything and exit the app
Cleanup:
	InvalidateDeviceObjects();
    FinalCleanup();
	CoUninitialize();
	UnregisterClass( DEF_APPNAME, wc.hInstance );

	return hr;
}















//////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Computes a screen quad aligned with a world segment.
 * \param  inverseview  [in] inverse view matrix
 * \param  view   [in] view matrix
 * \param  proj   [in] projection matrix
 * \param  verts   [out] 4 quad vertices in world space (forming a tri-strip)
 * \param  uvs    [out] 4 quad uvs
 * \param  stride   [in] size of vertex (FVF stride)
 * \param  p0    [in] segment's first point in world space
 * \param  p1    [in] segment's second point in world space
 * \param  size   [in] size of segment/quad
 * \param  constantsize [in] true to keep the quad's screen size constant (e.g. needed to emulate glLineWidth)
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID ComputeScreenQuad( const D3DXMATRIX& inverseview, const D3DXMATRIX& view, const D3DXMATRIX& proj,
						BYTE* verts, BYTE* uvs, DWORD stride, const D3DXVECTOR3& p0, const D3DXVECTOR3& p1, FLOAT size, BOOL constantsize )
{
	 // Compute delta in camera space
	 D3DXVECTOR3 Delta; 
	 TransformPoint3x3(Delta, p1-p0, view);

	 // Compute size factors
	 FLOAT SizeP0 = size;
	 FLOAT SizeP1 = size;
	 if(constantsize)
	 {
		  // Compute scales so that screen-size is constant
		  SizeP0 *= ComputeConstantScale(p0, view, proj);
		  SizeP1 *= ComputeConstantScale(p1, view, proj);
	 }

	 // Compute quad vertices
	 FLOAT Theta0 = atan2f(-Delta.x, -Delta.y);
	 FLOAT c0 = SizeP0 * cosf(Theta0);
	 FLOAT s0 = SizeP0 * sinf(Theta0);
	 ComputePoint(*((D3DXVECTOR3*)verts),  c0, -s0, inverseview, p0); verts+=stride;
	 ComputePoint(*((D3DXVECTOR3*)verts),  -c0, s0, inverseview, p0); verts+=stride;

	 FLOAT Theta1 = atan2f(Delta.x, Delta.y);
	 FLOAT c1 = SizeP1 * cosf(Theta1);
	 FLOAT s1 = SizeP1 * sinf(Theta1);
	 ComputePoint(*((D3DXVECTOR3*)verts),  -c1, s1, inverseview, p1); verts+=stride;
	 ComputePoint(*((D3DXVECTOR3*)verts),  c1, -s1, inverseview, p1); verts+=stride;

	 // Output uvs if needed
	 if(uvs)
	 {
		  *((FLOAT*)uvs) = 0.0f; *((FLOAT*)(uvs+4)) = 1.0f; uvs+=stride;
		  *((FLOAT*)uvs) = 0.0f; *((FLOAT*)(uvs+4)) = 0.0f; uvs+=stride;
		  *((FLOAT*)uvs) = 1.0f; *((FLOAT*)(uvs+4)) = 1.0f; uvs+=stride;
		  *((FLOAT*)uvs) = 1.0f; *((FLOAT*)(uvs+4)) = 0.0f; uvs+=stride;
	 }
}

inline VOID ComputePoint( D3DXVECTOR3& dest, FLOAT x, FLOAT y, const D3DXMATRIX& rot, const D3DXVECTOR3& trans )
{
	dest.x = trans.x + x * rot._11 + y * rot._21;
	dest.y = trans.y + x * rot._12 + y * rot._22;
	dest.z = trans.z + x * rot._13 + y * rot._23;
}


//And extra used functions:
// Quickly rotates a vector, using the 3x3 part of a 4x4 matrix
inline VOID TransformPoint3x3(D3DXVECTOR3& dest, const D3DXVECTOR3& source, const D3DXMATRIX& rot)
{
	dest.x = source.x * rot._11 + source.y * rot._21 + source.z * rot._31;
	dest.y = source.x * rot._12 + source.y * rot._22 + source.z * rot._32;
	dest.z = source.x * rot._13 + source.y * rot._23 + source.z * rot._33;
}

FLOAT ComputeConstantScale(const D3DXVECTOR3& pos, const D3DXMATRIX& view, const D3DXMATRIX& proj)
{
	D3DXVECTOR3 ppcam0; 
	D3DXVec3TransformCoord( &ppcam0, &pos, &view );
	
	D3DXVECTOR3 ppcam1 = ppcam0;
	ppcam1.x += 1.0f;

	FLOAT l1 = 1.0f / (ppcam0.x*proj._14	+ ppcam0.y*proj._24 + ppcam0.z*proj._34 + proj._44);
	FLOAT c1 =		  (ppcam0.x*proj._11	+ ppcam0.y*proj._21 + ppcam0.z*proj._31 + proj._41) * l1;
	FLOAT l2 = 1.0f / (ppcam1.x*proj._14	+ ppcam1.y*proj._24 + ppcam1.z*proj._34 + proj._44);
	FLOAT c2 =		  (ppcam1.x*proj._11	+ ppcam1.y*proj._21 + ppcam1.z*proj._31 + proj._41) * l2;
	FLOAT CorrectScale = 1.0f/(c2 - c1);

	return CorrectScale / FLOAT(WINDOW_WIDTH);
}

