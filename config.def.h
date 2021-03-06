/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const Gap default_gap        = {.isgap = 1, .realgap = 10, .gappx = 10};
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh_percent    = 0;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh_percent * screen_height / 100 as bar height */
static const int user_bh            = 50;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const int user_lrpad         = 30;
static const int vertpad            = 0;       /* vertical padding of bar */
static const int sidepad            = 0;       /* horizontal padding of bar */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *alttrayname      = "tray";    /* Polybar tray instance name */
static const char *altbarcmd        = "\0"; /* Alternate bar launch command */
static const char *fonts[]          = { "MesloLGS NF:bold:size=18" };
static const char dmenufont[]       = "MesloLGS NF:bold:size=18";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#bbbbbb";
static const char col_cyan[]        = "#2865AC";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "﬙", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class        instance    title            tags mask     iscentered   isfloating  isterminal  noswallow    monitor    scratch key  isfixedontop*/
	{ "Gimp",       NULL,       NULL,            1 << 8,       0,           1,          0,          0,           -1,        0,           0   },
	{ "Inkscape",   NULL,       NULL,            1 << 8,       0,           1,          0,          0,           -1,        0,           0   },
	{ "Firefox",    NULL,       NULL,            1 << 1,       0,           0,          0,          1,           -1,        0,           0   },
	{ "Alacritty",  NULL,       NULL,            0,            0,           0,          1,          0,           -1,        0,           0   },
	{ NULL,         NULL,      "scratchpad",     0,            1,           1,          0,          1,           -1,       's',          0   },
	{ NULL,         NULL,      "Event Tester",   0,            0,           0,          0,          1,           -1,        0,           0   }, /* xev */
	{ "Element-Nightly", NULL, NULL,             1 << 2,       0,           0,          0,          0,           -1,        0,           0   },
	{ "Mail",      NULL,       NULL,             1 << 2,       0,           0,          0,          0,           -1,        0,           0   },
	{ "Thunderbird", NULL,     NULL,             1 << 2,       0,           0,          0,          0,           -1,        0,           0   },
	{ NULL,        NULL,       "MailTerm",       1 << 2,       0,           0,          0,          0,           -1,        0,           0   },
	{ "Brave-browser", NULL,   NULL,             1 << 1,       0,           0,          0,          0,           -1,        0,           0   },
	{ "Zathura",   NULL,       NULL,             1 << 3,       0,           0,          0,          0,           -1,        0,           0   },
	{ "okular",    NULL,       NULL,             1 << 3,       0,           0,          0,          0,           -1,        0,           0   },
	{ NULL,        NULL,       "EditTerm",       1 << 4,       0,           0,          0,          0,           -1,        0,           0   },
	{ "DesktopEditors", NULL,  NULL,             1 << 4,       0,           0,          0,          0,           -1,        0,           0   },
	{ "code-oss",  NULL,       NULL,             1 << 5,       0,           0,          0,          0,           -1,        0,           0   },
	{ "Code",      NULL,       NULL,             1 << 5,       0,           0,          0,          0,           -1,        0,           0   },
	{ "GDBTerm",   NULL,       NULL,             1 << 5,       0,           0,          0,          0,           -1,        0,           0   },
	{ "DevTerm",   NULL,       NULL,             1 << 5,       0,           0,          0,          0,           -1,        0,           0,  },
	{ NULL,        NULL,       "SSHTerm",        1 << 6,       0,           0,          0,          0,           -1,        0,           0   },
	{ "kicad",     NULL,       NULL,             1 << 7,       0,           0,          0,          0,           -1,        0,           0   },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int decorhints  = 1;    /* 1 means respect decoration hints */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "[@]",      spiral },
	{ "[\\]",      dwindle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *launchercmd[] = { "sh", "-c", "~/.local/share/dwm/launcher", NULL };

/*First arg only serves to match against key in rules*/
static const char *scratchpadcmd[] = {"s", "sh", "-c", "~/.local/bin/scratchpad-launcher", NULL };

/*Command to toggle polybar (instead of calling togglebar) */
//static const char *togglepolybarcmd[] = {"polybar-msg", "cmd", "toggle", NULL};

static const char *dunstclosenotif[] = {"dunstctl", "close", NULL };
static const char *dunstcloseallnotifs[] = {"dunstctl", "close-all", NULL };
static const char *dunsthistory[] = {"dunstctl", "history-pop", NULL };
static const char *dunstcontextmenu[] = {"dunstctl", "context", NULL };

static const char *launchmuttterm[] = {"sh", "-c", "~/.local/bin/mutt-launcher", NULL };
static const char *launchnvimterm[] = {"alacritty", "-t", "EditTerm", "-e", "tmux", NULL };
static const char *launchdevwksp[] = {"sh", "-c", "~/.local/bin/devwksp-launcher", NULL };

static const char *cmdlockscreen[] = {"multilockscreen", "--lock", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = launchercmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_n,      togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_b,      togglefixedontop, {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_s,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY|ShiftMask,             XK_x,      togglesticky,   {0} },
	{ MODKEY,                       0xe0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             0xe0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_z,      focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_e,      focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_z,      tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_e,      tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_plus,   setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = GAP_TOGGLE} },
	{ ControlMask|ShiftMask,        XK_c,      spawn,          {.v = dunstclosenotif} },
	{ ControlMask|ShiftMask,        XK_space,  spawn,          {.v = dunstcloseallnotifs} },
	{ ControlMask|ShiftMask,        XK_h,      spawn,          {.v = dunsthistory} },
	{ ControlMask|ShiftMask,        XK_m,      spawn,          {.v = dunstcontextmenu} },
	TAGKEYS(                        0x26,                      0)
	TAGKEYS(                        0xe9,                      1)
	TAGKEYS(                        0x22,                      2)
	TAGKEYS(                        0x27,                      3)
	TAGKEYS(                        0x28,                      4)
	TAGKEYS(                        0x2d,                      5)
	TAGKEYS(                        0xe8,                      6)
	TAGKEYS(                        0x5f,                      7)
	TAGKEYS(                        0xe7,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          {.v = launchmuttterm} },
	{ MODKEY|ShiftMask,             XK_v,      spawn,          {.v = launchnvimterm} },
	{ MODKEY,                       XK_x,      spawn,          {.v = cmdlockscreen} },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = launchdevwksp} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};

/* quitting */
static const int EMPTY_WINDOW_COUNT = 2;
