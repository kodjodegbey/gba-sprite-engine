
//{{BLOCK(spelerSpel)

//======================================================================
//
//	spelerSpel, 16x192@8, 
//	+ palette 256 entries, not compressed
//	+ 48 tiles not compressed
//	Total size: 512 + 3072 = 3584
//
//	Time-stamp: 2020-07-13, 19:18:32
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================
#ifndef GBA_SPRITE_ENGINE_PROJECT_FF_H
#define GBA_SPRITE_ENGINE_PROJECT_FF_H


//const unsigned int spelerSpelTiles[768] __attribute__((aligned(4)))=
//{
//	0x00000000,0x6FF36800,0x00000000,0xE8CB08F8,0xDF000000,0xE1E17269,0x53000000,0xE1E1E17E,
//	0x84F26400,0xE1E1E1AC,0x436EEC00,0xE1E1B362,0xD8A85F00,0x72723F43,0x9E760000,0xAC3F6221,
//	0x008F9F9F,0x00000000,0xA3DD34E8,0x00000000,0x6FCB4992,0x00000000,0xF33D72E1,0x0000001E,
//	0x9B387EE1,0x000000C8,0x0F62ACE1,0x0000637A,0xAD994311,0x00003BA8,0x4A897FB8,0x000000FA,
//	0x88F40000,0xB8B843D5,0x6A000000,0x6238F81F,0x236A0000,0x626D38DE,0xBB250000,0x01C512CD,
//	0x87140000,0x4E7E22E5,0x5B830000,0x4EF57B78,0x4B000000,0x1B078B91,0x00000000,0x00008300,
//	0x47ADF899,0x00000000,0x97DB01BF,0x00000000,0xDBA14384,0x000000E4,0xA2A512C0,0x00000080,
//	0x52E97222,0x00000052,0x833EC0B7,0x00000000,0x00413E8B,0x00000000,0x00005959,0x00000000,
//
//	0x00000000,0x205E7641,0x04000000,0xDADA4EC1,0x7F000000,0xE1E1E105,0x53526400,0xE1E1B33F,
//	0x437A7700,0xB3AC38B8,0x4345A800,0x622E0162,0x4A688C00,0x7FC1FCFC,0x4A470000,0x9AFC6D9E,
//	0x00903120,0x00000000,0xA3FEA9DA,0x00000000,0x8EDC79E1,0x0000001E,0x5DB872E1,0x000000C8,
//	0xFB01B372,0x0000EFF2,0x9B7F623F,0x000028A8,0xC9D5FC43,0x00000068,0x88AD7F84,0x0000001C,
//	0x21000000,0xABDCF647,0x56838000,0x3CE20A42,0xB56E8000,0xB8B8B8C0,0xF8BC1400,0xFFFFFFAC,
//	0xB4A70000,0xE1E1E175,0x91830000,0x4848485B,0x4B000000,0x00008383,0x00000000,0x00000000,
//	0x972147CA,0x00000000,0x6A23846D,0x00000051,0xC62A84B8,0x000000BB,0x9B53B0FF,0x000000BC,
//	0x2B7F11E1,0x00000000,0x839119E3,0x00000000,0xA7918BEB,0x00000000,0xA6A78300,0x00000000,
//
//	0x00000000,0x5E760400,0x00000000,0xDA7EC104,0x00000000,0xE1E10553,0xB9640000,0xE1723F84,
//	0x7A770000,0x7E3F3843,0x45A80000,0xB86201FC,0x688C0000,0x0A489AF4,0x47000000,0x486D9E4A,
//	0xA3305E20,0x00000000,0x9FF6DADA,0x0000001E,0x5D72E1E1,0x0000A36B,0xB8B3E1E1,0x0000C816,
//	0x6D3FB372,0x00EFF27A,0x0143623F,0x0028A845,0x477FB8B8,0x000068C9,0x899C990A,0x00004B47,
//	0x00000000,0xE2F68821,0x00000000,0xABC07859,0xDF000000,0x62C5237D,0x74000000,0xFF841425,
//	0x52000000,0xE13F9C74,0x00000000,0x487FB4E4,0x00000000,0x00000000,0x00000000,0x00000000,
//	0xF7F89AF8,0x00000000,0x2ACE7F2F,0x00000000,0x0FAF99B8,0x00000000,0x53ACFFFF,0x00000004,
//	0x7F6969AC,0x00000004,0x786E6EE0,0x0000004B,0x91B67800,0x0000004B,0x00A70000,0x00000000,
//
//	0x8E6B6B00,0x65E17E4A,0x34CBDD90,0xE1E1E161,0x31C4702D,0xE1E10C61,0xC3304663,0xE1E16061,
//	0xF9148300,0x11B034AE,0x86375100,0x42C966C6,0x67D35200,0x25AD8F25,0x25749700,0x30BE4F6E,
//	0x00A57EB0,0x00000000,0xB2B892E1,0x00000017,0x62B3E1E1,0x0000170A,0xB8ACB372,0x00D10AB8,
//	0xB8B8B8AC,0x00B4B8B8,0xF89AFC42,0xF8BF999A,0xF8B484F9,0x48C14883,0x000008B9,0xE4DFDF00,
//	0x52E40000,0x9CA09B95,0x6DB60000,0x38F1B862,0xAB0B1C00,0xBF2356B2,0x36CD0400,0x99A156B0,
//	0xD0F80000,0x75250FE5,0x8B4B0000,0x91EC7485,0x914B0000,0x41FD8341,0x00000000,0xE4838383,
//	0x0000209B,0x00000000,0x0000A77F,0x00000000,0x00002BBF,0x00000000,0x00007F62,0x00000000,
//	0x0000F82E,0x00000000,0x00000083,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
//
//	0x6B000000,0xE1ACD96B,0xDD6F0000,0xE179D6C4,0xE8DD8C00,0xE160CBC4,0xFE2DEF00,0x79348F30,
//	0xB98C0000,0x54E8FB7A,0xE0000000,0xF3A04481,0xC7000000,0xDD9F353A,0x37000000,0x9330A2BB,
//	0x1AEECF72,0x00000000,0x8265E1E1,0x00000017,0x11E1E1E1,0x00001743,0x7E72E1E1,0x00007C62,
//	0xB8621111,0x007C0AB8,0x6238DB1F,0xA6176262,0x01A525F9,0xDF014348,0x0808AD45,0x00014883,
//	0x00000000,0x4F18C7E0,0xF4005B00,0x293862C0,0x083E5B00,0x2962B8CA,0x2157EB00,0x394712E2,
//	0x8B8B4B00,0x537EB3BF,0x3E590000,0x8353BF3E,0x83000000,0x83DFDF83,0x00000000,0x00000000,
//	0xCA8D7608,0x00B48300,0x002BD823,0x00000000,0x00F89CA1,0x00000000,0x83BFC725,0x00000000,
//	0x536DC7F9,0x00000000,0x83E43E83,0x00000000,0xDFDF4183,0x00000000,0x00DF8300,0x00000000,
//
//	0x00000000,0xF54A90F3,0x5C000000,0x54E8588E,0x90000000,0xD631A070,0x6B000000,0x346B9F5E,
//	0x30000000,0x40BB1802,0x00000000,0xBA0381E0,0x00000000,0x18ED9614,0x00000000,0x95A21821,
//	0x65ACE1E1,0x00000043,0xB3E1E192,0x00007C0A,0xE1E1E179,0x009443AC,0x72E1E10C,0xA6E9993F,
//	0x3F11B0EA,0xDF4862B8,0xEEEE168E,0x00486262,0x33251858,0x00043817,0xB6306BCC,0x00049A9C,
//	0x00000000,0x9574DB52,0x00835B00,0x62B82687,0x91855B00,0xB2F6F504,0x64A4F000,0xBD0CACD3,
//	0x578B4B00,0x7E53371E,0x854B0000,0xB4F89185,0x83000000,0x00000083,0x00000000,0x00000000,
//	0x8A7F4F89,0x0000F815,0xB4B682C5,0x000000A7,0x01AFA1B9,0x0000913E,0x7425CED8,0x004B8B57,
//	0x5195844E,0x004B57F0,0x838383B4,0x004BF0FD,0x00000000,0x00004141,0x00000000,0x00000000,
//
//	0x00000000,0x723FF800,0x00000000,0x27273F7F,0x1C000000,0x3470B7BF,0xF2770000,0x34A03188,
//	0xF95F0000,0x34A01D30,0x5F2C0000,0x66C49F4F,0x1C000000,0xAD30F3CA,0x97000000,0x1373039F,
//	0xF87572E1,0x00000000,0x75272727,0x0000007F,0xB7703434,0x00001C84,0xCCCCC434,0x00771888,
//	0x618AC370,0x005FF9C3,0x90F9F930,0x002C5F66,0xF3A8BBF9,0x00001CCA,0x747313A2,0x0000979F,
//	0x00000000,0x3513371C,0x00000000,0x3388B5DB,0x74000000,0x62B27DC6,0x39000000,0x4A6C0A44,
//	0x00000000,0xBD110100,0x00000000,0x697857F0,0x00000000,0xDFF00DEB,0x00000000,0x004B4B00,
//	0xE01335A2,0x0000001C,0xB5883333,0x000000DB,0x7DB26275,0x000074C6,0x0A6C4A34,0x000014F9,
//	0x4811BDA9,0x00000000,0x57786969,0x000000EB,0x0DF04100,0x000000EB,0x4B4B0000,0x00000000,
//
//	0x00000000,0x38F80400,0x00000000,0x7E4E6D04,0x00000000,0xE1E14EF8,0x2B000000,0x6060B743,
//	0xE38AA300,0x34341DCD,0x95184D00,0x34A0E88E,0x45A80000,0x3431CB4F,0x8E1C0000,0x5E906F2D,
//	0x00A77F62,0x00000000,0x7F754E7E,0x00000000,0x8472E1E1,0x00000004,0x05E26060,0x00000004,
//	0x66E83434,0x00774553,0xCA31FE34,0x00327A45,0xFEF9F2E8,0x0063A895,0x2DC7189E,0x0000D531,
//	0xAD1C0000,0xF34CE68F,0x1C000000,0x35D77A21,0x00000000,0xF9186883,0x00000000,0x7BD8236A,
//	0x39000000,0x8DD5A10F,0x74000000,0x3638396E,0x00000000,0x059A5900,0x00000000,0x2B040000,
//	0x305A0E7A,0x0000F76F,0x21B15AA2,0x000000DF,0x56F3BBF9,0x0000219B,0x52C5B206,0x00005218,
//	0x53113D34,0x00000097,0x53729249,0x000000DF,0x3E83D005,0x0000004B,0x59832B2B,0x00000000,
//
//	0x00000000,0xB34E6904,0x04000000,0xE1E1B3BF,0x5B000000,0xEAEAEA9D,0xC9F27700,0x3434D670,
//	0x4FFB5C00,0xC43461A0,0xF2A86300,0x90C4D6D9,0x0B970000,0x186B9F9D,0x981C0000,0xBB0E5A30,
//	0x000105B3,0x00000000,0x7F05E1E1,0x00000000,0x697BEAEA,0x0000002B,0x5DD67061,0x00A3F2D5,
//	0x2DCC8A55,0x004D777A,0xFEFBA2F9,0x00005CFB,0xCA9BFB6E,0x00000008,0x8FE64CBB,0x00000076,
//	0x5B000000,0xA25AE651,0x7A740000,0xBBFB6856,0xBB740000,0xB862E387,0x00000000,0x204712B4,
//	0x00000000,0xEAB04E69,0x00000000,0x24CF1941,0x4B000000,0xDFFA57F0,0x4B000000,0x008B0D0D,
//	0xF718D735,0x00000097,0x8368F2F9,0x00000000,0x6A56B66D,0x000000A7,0x0FCE19AB,0x00000039,
//	0xBB39B854,0x00000051,0x00596D24,0x00000041,0x000004DF,0x00000000,0x00000000,0x00000000,
//
//	0x00000000,0x00000000,0xA5000000,0xB3727E82,0x62FC0000,0xE1E17211,0x6299FC00,0xE1E1E17E,
//	0xB8B862D1,0x724EACB8,0x6D996253,0x99999999,0xB4489AFC,0x7A444301,0x00002B2B,0xF9452BDF,
//	0x00000000,0x00000000,0x8DDCB3E1,0x00009031,0x615879E1,0x008E20D6,0x46340CE1,0x712D5846,
//	0x95583492,0x00FDD914,0xFB5070CD,0x0000A7B9,0x5A256B02,0x00005209,0x67258D45,0x00005109,
//	0x00000000,0xC99B9E00,0x00000000,0x84F8E400,0x00000000,0x387FA700,0x00000000,0xC06DF800,
//	0x00000000,0xD0997F00,0x00000000,0x53010000,0x00000000,0x91830000,0x00000000,0x83000000,
//	0x7ABBD993,0x00000037,0x7F43846B,0x0000001C,0x3D62DE7D,0x0000004A,0x0B4756A1,0x0000A70B,
//	0x274EB5A1,0x00000069,0x7F690FBB,0x000000A7,0x0DFD1B1B,0x0000004B,0x4B838391,0x00000000,
//
//	0x00000000,0x00000000,0x00000000,0xE1728200,0xC2000000,0xE1727ED2,0x3FFC0000,0xE1E1E172,
//	0x4E997C00,0x92E1E1E1,0x3FB8436A,0x49729211,0xB8B8627C,0x3C990A62,0x43BF6201,0x6F9544DB,
//	0x00000000,0x00000000,0x00A3023F,0x00000000,0x30318DBD,0x00000000,0xCCD65E49,0x0000008E,
//	0xA06BCC34,0x00008C4F,0x30958A34,0x0000009F,0xF718F9D6,0x00000000,0x8096356B,0x00000000,
//	0x2B83C101,0x58BB9591,0x9E008348,0x5898B69E,0xE4000000,0x16DB2EE4,0x00000000,0x29A1BF2B,
//	0x2B000000,0x29A12653,0x7F000000,0x76257A99,0x7F000000,0xF852377F,0xA7000000,0x8383FD5B,
//	0xC2D73598,0x00000000,0xE4C7F9F2,0x00000000,0x00F82E43,0x00000000,0x08ABB862,0x0000DF4B,
//	0xD5CA12B2,0x0000850D,0x8575653D,0x00005B57,0xF0783F3F,0x0000003E,0x595904DF,0x00000000,
//
//	0xA6000000,0x008383DF,0x00000000,0xE1E1AC2C,0x0A170000,0x92E17292,0xACD8AA00,0xDAE1E1E1,
//	0xAC99E7A6,0x0CE1E1E1,0xB8620141,0xEA656511,0xB862012B,0x1D9D62B8,0x17620400,0x31ECA2F9,
//	0x00000000,0x00000000,0x001E19E5,0x00000000,0x9F313454,0x00000000,0xCCD6C4C4,0x00000090,
//	0x616F6B34,0x00000090,0x9FF27A40,0x000000A3,0xFA148050,0x00000000,0xB93AED7A,0x00000000,
//	0x10430400,0xCA558A78,0x15A70000,0x891DF88A,0x1C000000,0x9C98C083,0x91830000,0x7623A501,
//	0x578B4B00,0x2FB52514,0x8B574B00,0x7E2F0F52,0xFDF04B00,0x04A7A7A7,0x3E854B00,0x00000083,
//	0x2109357A,0x00000000,0x87A518FB,0x00000000,0x14CE2E0A,0x00000000,0x0411CAB8,0x005B3E4B,
//	0x0311A93D,0x00EBA4D4,0xC7B90A7E,0x004B0DA4,0xFD1B0404,0x00004BFD,0x83000000,0x00000083,
//};

const unsigned int spelerSpelTiles[64] __attribute__((aligned(4)))=
        {
                0x12121212,0xB4729C12,0x12121212,0x9B6E70D2,0x12121212,0xB7B7BC72,0x7C121212,0xCF5D98A8,
                0x909E8312,0xC3C39F94,0x5E87AB12,0xC3C8BF84,0xAE5C1212,0x69B68BC2,0x53601212,0x5FA6688E,
                0x128C79A2,0x12121212,0x7982BC9B,0x12121212,0xCE65B7B7,0x12121276,0x8695CFCF,0x121212B2,
                0x6A9169C3,0x12ACAEC4,0x7BAF7E69,0x126FC066,0x936B5791,0x127DB8CD,0xCC73B54E,0x121288CA,
                0x4F601212,0xC655759A,0xB1121212,0xAA56A364,0x12121212,0xCBBD63C5,0x12121212,0x77A58F6C,
                0x71121212,0x8AC97485,0x8D121212,0x5BB48197,0x12121212,0x524DB912,0x12121212,0x7CB21212,
                0xB09654A3,0x12125ABA,0xB3616D7A,0x121212A9,0x50A099CB,0x1212C7A4,0x59BE6758,0x1212AD87,
                0x80A78969,0x12121292,0xA1659D78,0x121212BB,0x7FC162D1,0x12121251,0xD0C17C7C,0x12121212,
        };

const unsigned int lopen_jongenTiles[128] __attribute__((aligned(4)))=
        {
                0x1C1C1C1C,0x1D1D1D1C,0x1C1C1C1C,0x2724201D,0x1D1C1C1C,0x27272A24,0x241D1C1C,0x242A2721,
                0x271D1C1C,0x29202120,0x1D1C1C1C,0x21212024,0x1D1D1D1C,0x1F1E1F1E,0x2929211D,0x261E261E,
                0x1C1D1D1D,0x1C1C1C1C,0x1D242A27,0x1C1C1C1D,0x272A2727,0x1C1D1D24,0x1F272724,0x1D242724,
                0x271F2026,0x1C1D1D24,0x20202121,0x1C1D2427,0x1E1F1E22,0x1C1D1E1E,0x1E261E26,0x1D1F2523,
                0x2B211D1C,0x2A261E25,0x211D1C1C,0x1F1E211E,0x1E1D1C1C,0x1E29251F,0x261E1D1C,0x2B231E22,
                0x1E251D1C,0x201F1E1E,0x2323251D,0x25291F1E,0x1E23291D,0x2121231D,0x1D1D1D1C,0x25291D1C,
                0x251E2628,0x1C1D1F2B,0x1E211E1F,0x1C1C1D1F,0x1E25291E,0x1C1D1F22,0x1F1E2329,0x1C1D262A,
                0x1E1E1E20,0x1D1E2626,0x1D1F1F1E,0x1D251E1E,0x1D1D251E,0x1D29231D,0x1C1D1D1D,0x1C1D1D1C,

                0x1C1C1C1C,0x1D1D1D1C,0x1C1C1C1C,0x2724201D,0x1D1C1C1C,0x27272A27,0x201D1C1C,0x242A2A21,
                0x241D1C1C,0x29202120,0x1D1C1C1C,0x21212024,0x1D1D1D1C,0x1F1E1F1E,0x2929211D,0x261E261E,
                0x1C1D1D1D,0x1C1C1C1C,0x1D242A27,0x1C1C1D1D,0x2A2A2727,0x1C1D2427,0x1F272724,0x1C1D1D24,
                0x241F2026,0x1C1D2427,0x20202121,0x1C1C1D24,0x1E1F1E22,0x1C1D1D1E,0x1E261E26,0x1D212523,
                0x2B211D1C,0x2A261E25,0x211D1C1C,0x1F1E211E,0x221F1D1C,0x1E29251E,0x2A261D1C,0x2B231E1F,
                0x26261E1D,0x201E1E1E,0x1E1E251D,0x1E1F211D,0x1D23291D,0x1E251D1D,0x1C1D1D1C,0x1D1D1D1C,
                0x251E2628,0x1C1D212B,0x1E211E1F,0x1C1C1D1F,0x1F25291E,0x1C1C1D1E,0x221E2329,0x1C1D1E26,
                0x1E1E1F20,0x1C1D251E,0x1E212925,0x1D252323,0x1D232121,0x1D29231E,0x1C1D2925,0x1C1D1D1D,
        };

//const unsigned short sharedPal[256] __attribute__((aligned(4)))=
//        {
//                0x0000,0x1143,0x154F,0x3E11,0x1003,0x0B03,0x1ACF,0x100D,
//                0x0D4A,0x5233,0x1225,0x0E52,0x03D1,0x1094,0x454E,0x4AF9,
//                0x10C2,0x0F06,0x11EB,0x5AD8,0x29AF,0x037B,0x2232,0x11C0,
//                0x3A76,0x10CC,0x5018,0x0C27,0x0C00,0x1319,0x2573,0x220A,
//                0x0F7B,0x14E7,0x0785,0x4B95,0x0EC0,0x575D,0x21AA,0x07C0,
//                0x2812,0x3AD1,0x3690,0x0C43,0x280F,0x1655,0x11A4,0x1187,
//                0x21D3,0x22DA,0x1D52,0x3EB7,0x03DE,0x679E,0x0B6B,0x212B,
//                0x1247,0x2DCF,0x760F,0x100E,0x12F5,0x126B,0x106A,0x12A7,
//
//                0x1F7C,0x1065,0x264C,0x1604,0x4F1A,0x29F3,0x2678,0x0D8C,
//                0x1123,0x07CD,0x11F0,0x1080,0x656C,0x2533,0x0B83,0x1296,
//                0x437D,0x18E8,0x258D,0x1145,0x0F96,0x2E57,0x4333,0x1097,
//                0x1F1A,0x1082,0x6F3A,0x1086,0x2110,0x1A70,0x1B1B,0x2151,
//                0x03D9,0x139D,0x1267,0x1CAF,0x3177,0x0F65,0x1AD8,0x779C,
//                0x150E,0x0DC3,0x2148,0x2256,0x0AC9,0x1206,0x533C,0x1DF4,
//                0x0BBD,0x741F,0x07C2,0x7A73,0x31F1,0x1285,0x156C,0x2DF5,
//                0x10E9,0x07C7,0x46D9,0x16AE,0x1DC5,0x326E,0x0B84,0x1104,
//
//                0x3A33,0x352D,0x1E2A,0x1084,0x1185,0x106B,0x39AE,0x214B,
//                0x11AD,0x11B0,0x3697,0x1070,0x30D5,0x0F3A,0x1E35,0x1EB8,
//                0x21F5,0x1068,0x07C3,0x2B5B,0x2D2A,0x3E97,0x6DEE,0x0800,
//                0x19D1,0x1246,0x11C2,0x29F1,0x10E5,0x1A53,0x0EF7,0x1DB2,
//                0x177D,0x4FD7,0x5B7E,0x2995,0x14BA,0x29ED,0x1847,0x0C63,
//                0x25B2,0x07D7,0x400F,0x0EB2,0x12C7,0x1990,0x36DA,0x25CC,
//                0x0F07,0x5B3B,0x1629,0x07A3,0x10A4,0x4755,0x112B,0x130D,
//                0x1668,0x1D6D,0x379D,0x4AFA,0x3633,0x0B68,0x3AD9,0x11C6,
//
//                0x1149,0x1183,0x3190,0x2A36,0x1F1C,0x1126,0x537B,0x3E55,
//                0x31D6,0x114E,0x079C,0x1B5C,0x135B,0x122B,0x3EF3,0x16A9,
//                0x0EA3,0x1405,0x1AE9,0x5675,0x1CF5,0x110A,0x0FBE,0x6E74,
//                0x15E7,0x19F3,0x07C9,0x2A0C,0x0B37,0x1A76,0x2EAD,0x1064,
//                0x1D0A,0x03E2,0x12F2,0x1107,0x1085,0x0B42,0x62F8,0x1D86,
//                0x07DE,0x1966,0x03DB,0x108C,0x3213,0x7BDE,0x268C,0x2C73,
//                0x106E,0x198B,0x3656,0x1991,0x0DCE,0x0B88,0x07BC,0x10A6,
//                0x10C4,0x4F1B,0x10AA,0x42B8,0x15E2,0x104C,0x22B9,0x0EAB,
//        };
#endif //GBA_SPRITE_ENGINE_PROJECT_FF_H
