/*
 * Stellarium
 * Copyright (C) 2002 Fabien Ch�reau
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include "grid.h"
#include "s_utility.h"
#include "draw.h"

void moy(vec3_t * p, int a, int b, int c)
{
	p[c] = p[a] + p[b];
	p[c].normalize();
}

Grid::Grid()
{   
	
	NbPoints = 162;
	Angle = PI/10;
/*
float tempTab[92][3] ={
{0.0000,0.0000,1.0000    },
{0.8944,0.0000,0.4472    },
{0.2764,0.8507,0.4472    },
{-0.7236,0.5257,0.4472   },
{-0.7236,-0.5257,0.4472  },
{0.2764,-0.8507,0.4472   },
{0.7236,0.5257,-0.4472   },
{-0.2764,0.8507,-0.4472  },
{-0.8944,-0.0000,-0.4472 },
{-0.2764,-0.8507,-0.4472 },
{0.7236,-0.5257,-0.4472  },
{0.0000,0.0000,-1.0000   },
{0.3607,0.0000,0.9327    },
{0.6729,0.0000,0.7397    },
{0.1115,0.3431,0.9327    },
{0.2079,0.6399,0.7397    },
{-0.2918,0.2120,0.9327   },
{-0.5444,0.3955,0.7397   },
{-0.2918,-0.2120,0.9327  },
{-0.5444,-0.3955,0.7397  },
{0.1115,-0.3431,0.9327   },
{0.2079,-0.6399,0.7397   },
{0.7844,0.3431,0.5168    },
{0.5687,0.6399,0.5168    },
{-0.0839,0.8520,0.5168   },
{-0.4329,0.7386,0.5168   },
{-0.8362,0.1835,0.5168   },
{-0.8362,-0.1835,0.5168  },
{-0.4329,-0.7386,0.5168  },
{-0.0839,-0.8520,0.5168  },
{0.5687,-0.6399,0.5168   },
{0.7844,-0.3431,0.5168   },
{0.9647,0.2120,0.1561    },
{0.9051,0.3955,-0.1561   },
{0.0965,0.9830,0.1561    },
{-0.0965,0.9830,-0.1561  },
{-0.9051,0.3955,0.1561   },
{-0.9647,0.2120,-0.1561  },
{-0.6558,-0.7386,0.1561  },
{-0.4998,-0.8520,-0.1561 },
{0.4998,-0.8520,0.1561   },
{0.6558,-0.7386,-0.1561  },
{0.9647,-0.2120,0.1561   },
{0.9051,-0.3955,-0.1561  },
{0.4998,0.8520,0.1561    },
{0.6558,0.7386,-0.1561   },
{-0.6558,0.7386,0.1561   },
{-0.4998,0.8520,-0.1561  },
{-0.9051,-0.3955,0.1561  },
{-0.9647,-0.2120,-0.1561 },
{0.0965,-0.9830,0.1561   },
{-0.0965,-0.9830,-0.1561 },
{0.4329,0.7386,-0.5168   },
{0.0839,0.8520,-0.5168   },
{-0.5687,0.6399,-0.5168  },
{-0.7844,0.3431,-0.5168  },
{-0.7844,-0.3431,-0.5168 },
{-0.5687,-0.6399,-0.5168 },
{0.0839,-0.8520,-0.5168  },
{0.4329,-0.7386,-0.5168  },
{0.8362,-0.1835,-0.5168  },
{0.8362,0.1835,-0.5168   },
{0.2918,0.2120,-0.9327   },
{0.5444,0.3955,-0.7397   },
{-0.1115,0.3431,-0.9327  },
{-0.2079,0.6399,-0.7397  },
{-0.3607,-0.0000,-0.9327 },
{-0.6729,-0.0000,-0.7397 },
{-0.1115,-0.3431,-0.9327 },
{-0.2079,-0.6399,-0.7397 },
{0.2918,-0.2120,-0.9327  },
{0.5444,-0.3955,-0.7397  },
{0.4795,0.3484,0.8054    },
{-0.1832,0.5637,0.8054   },
{-0.5927,-0.0000,0.8054  },
{-0.1832,-0.5637,0.8054  },
{0.4795,-0.3484,0.8054   },
{0.9855,0.0000,-0.1699   },
{0.3045,0.9372,-0.1699   },
{-0.7973,0.5792,-0.1699  },
{-0.7973,-0.5792,-0.1699 },
{0.3045,-0.9372,-0.1699  },
{0.7973,0.5792,0.1699    },
{-0.3045,0.9372,0.1699   },
{-0.9855,-0.0000,0.1699  },
{-0.3045,-0.9372,0.1699  },
{0.7973,-0.5792,0.1699   },
{0.1832,0.5637,-0.8054   },
{-0.4795,0.3484,-0.8054  },
{-0.4795,-0.3484,-0.8054 },
{0.1832,-0.5637,-0.8054  },
{0.5927,0.0000,-0.8054   }};
*/
/*
float tempTab[42][3] ={
{0.0000,0.0000,1.0000   },
{0.8944,0.0000,0.4472   },
{0.2764,0.8507,0.4472   },
{-0.7236,0.5257,0.4472  },
{-0.7236,-0.5257,0.4472 },
{0.2764,-0.8507,0.4472  },
{0.7236,0.5257,-0.4472  },
{-0.2764,0.8507,-0.4472 },
{-0.8944,-0.0000,-0.4472},
{-0.2764,-0.8507,-0.4472},
{0.7236,-0.5257,-0.4472 },
{0.0000,0.0000,-1.0000  },
{0.5257,0.0000,0.8507   },
{0.1625,0.5000,0.8507   },
{-0.4253,0.3090,0.8507  },
{-0.4253,-0.3090,0.8507 },
{0.1625,-0.5000,0.8507  },
{0.6882,0.5000,0.5257   },
{-0.2629,0.8090,0.5257  },
{-0.8507,-0.0000,0.5257 },
{-0.2629,-0.8090,0.5257 },
{0.6882,-0.5000,0.5257  },
{0.9511,0.3090,0.0000   },
{-0.0000,1.0000,0.0000  },
{-0.9511,0.3090,0.0000  },
{-0.5878,-0.8090,0.0000 },
{0.5878,-0.8090,0.0000  },
{0.9511,-0.3090,0.0000  },
{0.5878,0.8090,0.0000   },
{-0.5878,0.8090,0.0000  },
{-0.9511,-0.3090,0.0000 },
{0.0000,-1.0000,0.0000  },
{0.2629,0.8090,-0.5257  },
{-0.6882,0.5000,-0.5257 },
{-0.6882,-0.5000,-0.5257},
{0.2629,-0.8090,-0.5257 },
{0.8507,0.0000,-0.5257  },
{0.4253,0.3090,-0.8507  },
{-0.1625,0.5000,-0.8507 },
{-0.5257,-0.0000,-0.8507},
{-0.1625,-0.5000,-0.8507},
{0.4253,-0.3090,-0.8507 }};
*/
/*
	float tempTab[492][3] ={
{0.0000,0.0000,1.0000   },
{0.8944,0.0000,0.4472   },
{0.2764,0.8507,0.4472   },
{-0.7236,0.5257,0.4472  },
{-0.7236,-0.5257,0.4472 },
{0.2764,-0.8507,0.4472  },
{0.7236,0.5257,-0.4472  },
{-0.2764,0.8507,-0.4472 },
{-0.8944,-0.0000,-0.4472},
{-0.2764,-0.8507,-0.4472},
{0.7236,-0.5257,-0.4472 },
{0.0000,0.0000,-1.0000  },
{0.1575,0.0000,0.9875   },
{0.3111,0.0000,0.9504   },
{0.4569,0.0000,0.8895   },
{0.5913,0.0000,0.8065   },
{0.7109,0.0000,0.7033   },
{0.8128,0.0000,0.5825   },
{0.0487,0.1498,0.9875   },
{0.0961,0.2959,0.9504   },
{0.1412,0.4345,0.8895   },
{0.1827,0.5623,0.8065   },
{0.2197,0.6761,0.7033   },
{0.2512,0.7730,0.5825   },
{-0.1274,0.0926,0.9875  },
{-0.2517,0.1828,0.9504  },
{-0.3696,0.2686,0.8895  },
{-0.4784,0.3476,0.8065  },
{-0.5752,0.4179,0.7033  },
{-0.6576,0.4778,0.5825  },
{-0.1274,-0.0926,0.9875 },
{-0.2517,-0.1828,0.9504 },
{-0.3696,-0.2686,0.8895 },
{-0.4784,-0.3476,0.8065 },
{-0.5752,-0.4179,0.7033 },
{-0.6576,-0.4778,0.5825 },
{0.0487,-0.1498,0.9875  },
{0.0961,-0.2959,0.9504  },
{0.1412,-0.4345,0.8895  },
{0.1827,-0.5623,0.8065  },
{0.2197,-0.6761,0.7033  },
{0.2512,-0.7730,0.5825  },
{0.8615,0.1498,0.4852   },
{0.8071,0.2959,0.5110   },
{0.7325,0.4345,0.5241   },
{0.6396,0.5623,0.5241   },
{0.5308,0.6761,0.5110   },
{0.4087,0.7730,0.4852   },
{0.1238,0.8656,0.4852   },
{-0.0320,0.8590,0.5110  },
{-0.1869,0.8309,0.5241  },
{-0.3372,0.7821,0.5241  },
{-0.4790,0.7137,0.5110  },
{-0.6089,0.6276,0.4852  },
{-0.7850,0.3852,0.4852  },
{-0.8268,0.2350,0.5110  },
{-0.8480,0.0790,0.5241  },
{-0.8480,-0.0790,0.5241 },
{-0.8268,-0.2350,0.5110 },
{-0.7850,-0.3852,0.4852 },
{-0.6089,-0.6276,0.4852 },
{-0.4790,-0.7137,0.5110 },
{-0.3372,-0.7821,0.5241 },
{-0.1869,-0.8309,0.5241 },
{-0.0320,-0.8590,0.5110 },
{0.1238,-0.8656,0.4852  },
{0.4087,-0.7730,0.4852  },
{0.5308,-0.6761,0.5110  },
{0.6396,-0.5623,0.5241  },
{0.7325,-0.4345,0.5241  },
{0.8071,-0.2959,0.5110  },
{0.8615,-0.1498,0.4852  },
{0.9402,0.0926,0.3277   },
{0.9626,0.1828,0.1999   },
{0.9609,0.2686,0.0672   },
{0.9352,0.3476,-0.0672  },
{0.8862,0.4179,-0.1999  },
{0.8151,0.4778,-0.3277  },
{0.2025,0.9228,0.3277   },
{0.1236,0.9720,0.1999   },
{0.0415,0.9969,0.0672   },
{-0.0415,0.9969,-0.0672 },
{-0.1236,0.9720,-0.1999 },
{-0.2025,0.9228,-0.3277 },
{-0.8151,0.4778,0.3277  },
{-0.8862,0.4179,0.1999  },
{-0.9352,0.3476,0.0672  },
{-0.9609,0.2686,-0.0672 },
{-0.9626,0.1828,-0.1999 },
{-0.9402,0.0926,-0.3277 },
{-0.7063,-0.6276,0.3277 },
{-0.6713,-0.7137,0.1999 },
{-0.6195,-0.7821,0.0672 },
{-0.5523,-0.8309,-0.0672},
{-0.4714,-0.8590,-0.1999},
{-0.3786,-0.8656,-0.3277},
{0.3786,-0.8656,0.3277  },
{0.4714,-0.8590,0.1999  },
{0.5523,-0.8309,0.0672  },
{0.6195,-0.7821,-0.0672 },
{0.6713,-0.7137,-0.1999 },
{0.7063,-0.6276,-0.3277 },
{0.9402,-0.0926,0.3277  },
{0.9626,-0.1828,0.1999  },
{0.9609,-0.2686,0.0672  },
{0.9352,-0.3476,-0.0672 },
{0.8862,-0.4179,-0.1999 },
{0.8151,-0.4778,-0.3277 },
{0.3786,0.8656,0.3277   },
{0.4714,0.8590,0.1999   },
{0.5523,0.8309,0.0672   },
{0.6195,0.7821,-0.0672  },
{0.6713,0.7137,-0.1999  },
{0.7063,0.6276,-0.3277  },
{-0.7063,0.6276,0.3277  },
{-0.6713,0.7137,0.1999  },
{-0.6195,0.7821,0.0672  },
{-0.5523,0.8309,-0.0672 },
{-0.4714,0.8590,-0.1999 },
{-0.3786,0.8656,-0.3277 },
{-0.8151,-0.4778,0.3277 },
{-0.8862,-0.4179,0.1999 },
{-0.9352,-0.3476,0.0672 },
{-0.9609,-0.2686,-0.0672},
{-0.9626,-0.1828,-0.1999},
{-0.9402,-0.0926,-0.3277},
{0.2025,-0.9228,0.3277  },
{0.1236,-0.9720,0.1999  },
{0.0415,-0.9969,0.0672  },
{-0.0415,-0.9969,-0.0672},
{-0.1236,-0.9720,-0.1999},
{-0.2025,-0.9228,-0.3277},
{0.6089,0.6276,-0.4852  },
{0.4790,0.7137,-0.5110  },
{0.3372,0.7821,-0.5241  },
{0.1869,0.8309,-0.5241  },
{0.0320,0.8590,-0.5110  },
{-0.1238,0.8656,-0.4852 },
{-0.4087,0.7730,-0.4852 },
{-0.5308,0.6761,-0.5110 },
{-0.6396,0.5623,-0.5241 },
{-0.7325,0.4345,-0.5241 },
{-0.8071,0.2959,-0.5110 },
{-0.8615,0.1498,-0.4852 },
{-0.8615,-0.1498,-0.4852},
{-0.8071,-0.2959,-0.5110},
{-0.7325,-0.4345,-0.5241},
{-0.6396,-0.5623,-0.5241},
{-0.5308,-0.6761,-0.5110},
{-0.4087,-0.7730,-0.4852},
{-0.1238,-0.8656,-0.4852},
{0.0320,-0.8590,-0.5110 },
{0.1869,-0.8309,-0.5241 },
{0.3372,-0.7821,-0.5241 },
{0.4790,-0.7137,-0.5110 },
{0.6089,-0.6276,-0.4852 },
{0.7850,-0.3852,-0.4852 },
{0.8268,-0.2350,-0.5110 },
{0.8480,-0.0790,-0.5241 },
{0.8480,0.0790,-0.5241  },
{0.8268,0.2350,-0.5110  },
{0.7850,0.3852,-0.4852  },
{0.1274,0.0926,-0.9875  },
{0.2517,0.1828,-0.9504  },
{0.3696,0.2686,-0.8895  },
{0.4784,0.3476,-0.8065  },
{0.5752,0.4179,-0.7033  },
{0.6576,0.4778,-0.5825  },
{-0.0487,0.1498,-0.9875 },
{-0.0961,0.2959,-0.9504 },
{-0.1412,0.4345,-0.8895 },
{-0.1827,0.5623,-0.8065 },
{-0.2197,0.6761,-0.7033 },
{-0.2512,0.7730,-0.5825 },
{-0.1575,-0.0000,-0.9875},
{-0.3111,-0.0000,-0.9504},
{-0.4569,-0.0000,-0.8895},
{-0.5913,-0.0000,-0.8065},
{-0.7109,-0.0000,-0.7033},
{-0.8128,-0.0000,-0.5825},
{-0.0487,-0.1498,-0.9875},
{-0.0961,-0.2959,-0.9504},
{-0.1412,-0.4345,-0.8895},
{-0.1827,-0.5623,-0.8065},
{-0.2197,-0.6761,-0.7033},
{-0.2512,-0.7730,-0.5825},
{0.1274,-0.0926,-0.9875 },
{0.2517,-0.1828,-0.9504 },
{0.3696,-0.2686,-0.8895 },
{0.4784,-0.3476,-0.8065 },
{0.5752,-0.4179,-0.7033 },
{0.6576,-0.4778,-0.5825 },
{0.2071,0.1505,0.9667   },
{0.3624,0.1514,0.9197   },
{0.2560,0.2978,0.9197   },
{0.5100,0.1523,0.8466   },
{0.4127,0.2999,0.8601   },
{0.3025,0.4380,0.8466   },
{0.6455,0.1528,0.7483   },
{0.5609,0.3011,0.7712   },
{0.4597,0.4404,0.7712   },
{0.3448,0.5667,0.7483   },
{0.7641,0.1522,0.6269   },
{0.6944,0.3002,0.6540   },
{0.6056,0.4400,0.6631   },
{0.5001,0.5676,0.6540   },
{0.3809,0.6797,0.6269   },
{-0.0791,0.2435,0.9667  },
{-0.0320,0.3914,0.9197  },
{-0.2042,0.3355,0.9197  },
{0.0127,0.5321,0.8466   },
{-0.1577,0.4852,0.8601  },
{-0.3231,0.4230,0.8466  },
{0.0541,0.6611,0.7483   },
{-0.1130,0.6265,0.7712  },
{-0.2768,0.5732,0.7712  },
{-0.4324,0.5030,0.7483  },
{0.0914,0.7738,0.6269   },
{-0.0709,0.7532,0.6540  },
{-0.2313,0.7119,0.6631  },
{-0.3853,0.6510,0.6540  },
{-0.5287,0.5723,0.6269  },
{-0.2560,-0.0000,0.9667 },
{-0.3822,0.0905,0.9197  },
{-0.3822,-0.0905,0.9197 },
{-0.5022,0.1765,0.8466  },
{-0.5102,-0.0000,0.8601 },
{-0.5022,-0.1765,0.8466 },
{-0.6120,0.2558,0.7483  },
{-0.6307,0.0861,0.7712  },
{-0.6307,-0.0861,0.7712 },
{-0.6120,-0.2558,0.7483 },
{-0.7077,0.3260,0.6269  },
{-0.7383,0.1653,0.6540  },
{-0.7485,-0.0000,0.6631 },
{-0.7383,-0.1653,0.6540 },
{-0.7077,-0.3260,0.6269 },
{-0.0791,-0.2435,0.9667 },
{-0.2042,-0.3355,0.9197 },
{-0.0320,-0.3914,0.9197 },
{-0.3231,-0.4230,0.8466 },
{-0.1576,-0.4852,0.8601 },
{0.0127,-0.5321,0.8466  },
{-0.4324,-0.5030,0.7483 },
{-0.2768,-0.5732,0.7712 },
{-0.1130,-0.6265,0.7712 },
{0.0541,-0.6611,0.7483  },
{-0.5287,-0.5723,0.6269 },
{-0.3853,-0.6510,0.6540 },
{-0.2313,-0.7119,0.6631 },
{-0.0709,-0.7532,0.6540 },
{0.0914,-0.7738,0.6269  },
{0.2071,-0.1505,0.9667  },
{0.2560,-0.2978,0.9197  },
{0.3624,-0.1514,0.9197  },
{0.3025,-0.4380,0.8466  },
{0.4127,-0.2999,0.8601  },
{0.5100,-0.1523,0.8466  },
{0.3448,-0.5667,0.7483  },
{0.4597,-0.4404,0.7712  },
{0.5609,-0.3011,0.7712  },
{0.6455,-0.1528,0.7483  },
{0.3809,-0.6797,0.6269  },
{0.5001,-0.5676,0.6540  },
{0.6056,-0.4400,0.6631  },
{0.6944,-0.3002,0.6540  },
{0.7641,-0.1522,0.6269  },
{0.9791,0.0000,0.2034   },
{0.9935,-0.0905,0.0695  },
{0.9935,0.0905,0.0695   },
{0.9818,-0.1765,-0.0705 },
{0.9974,0.0000,-0.0717  },
{0.9818,0.1765,-0.0705  },
{0.9430,-0.2558,-0.2127 },
{0.9719,-0.0861,-0.2192 },
{0.9719,0.0861,-0.2192  },
{0.9430,0.2558,-0.2127  },
{0.8771,-0.3260,-0.3526 },
{0.9151,-0.1653,-0.3679 },
{0.9278,0.0000,-0.3730  },
{0.9151,0.1653,-0.3679  },
{0.8771,0.3260,-0.3526  },
{0.3026,0.9312,0.2034   },
{0.3931,0.9169,0.0695   },
{0.2209,0.9728,0.0695   },
{0.4713,0.8792,-0.0705  },
{0.3082,0.9486,-0.0717  },
{0.1355,0.9883,-0.0705  },
{0.5347,0.8178,-0.2127  },
{0.3822,0.8977,-0.2192  },
{0.2184,0.9509,-0.2192  },
{0.0481,0.9759,-0.2127  },
{0.5811,0.7335,-0.3526  },
{0.4400,0.8192,-0.3679  },
{0.2867,0.8824,-0.3730  },
{0.1256,0.9214,-0.3679  },
{-0.0390,0.9350,-0.3526 },
{-0.7921,0.5755,0.2034  },
{-0.7505,0.6572,0.0695  },
{-0.8569,0.5107,0.0695  },
{-0.6905,0.7199,-0.0705 },
{-0.8069,0.5863,-0.0717 },
{-0.8980,0.4342,-0.0705 },
{-0.6126,0.7612,-0.2127 },
{-0.7356,0.6409,-0.2192 },
{-0.8369,0.5016,-0.2192 },
{-0.9133,0.3474,-0.2127 },
{-0.5180,0.7793,-0.3526 },
{-0.6432,0.6716,-0.3679 },
{-0.7506,0.5454,-0.3730 },
{-0.8375,0.4042,-0.3679 },
{-0.9012,0.2518,-0.3526 },
{-0.7921,-0.5755,0.2034 },
{-0.8569,-0.5107,0.0695 },
{-0.7505,-0.6572,0.0695 },
{-0.8980,-0.4342,-0.0705},
{-0.8069,-0.5863,-0.0717},
{-0.6905,-0.7199,-0.0705},
{-0.9133,-0.3474,-0.2127},
{-0.8369,-0.5016,-0.2192},
{-0.7356,-0.6409,-0.2192},
{-0.6126,-0.7612,-0.2127},
{-0.9012,-0.2518,-0.3526},
{-0.8375,-0.4042,-0.3679},
{-0.7506,-0.5454,-0.3730},
{-0.6432,-0.6716,-0.3679},
{-0.5180,-0.7793,-0.3526},
{0.3026,-0.9312,0.2034  },
{0.2209,-0.9728,0.0695  },
{0.3931,-0.9169,0.0695  },
{0.1355,-0.9883,-0.0705 },
{0.3082,-0.9486,-0.0717 },
{0.4713,-0.8792,-0.0705 },
{0.0481,-0.9759,-0.2127 },
{0.2184,-0.9509,-0.2192 },
{0.3822,-0.8977,-0.2192 },
{0.5347,-0.8178,-0.2127 },
{-0.0390,-0.9350,-0.3526},
{0.1256,-0.9214,-0.3679 },
{0.2867,-0.8824,-0.3730 },
{0.4400,-0.8192,-0.3679 },
{0.5811,-0.7335,-0.3526 },
{0.7921,0.5755,-0.2034  },
{0.7505,0.6572,-0.0695  },
{0.8569,0.5107,-0.0695  },
{0.6905,0.7199,0.0705   },
{0.8069,0.5863,0.0717   },
{0.8980,0.4342,0.0705   },
{0.6126,0.7612,0.2127   },
{0.7356,0.6409,0.2192   },
{0.8369,0.5016,0.2192   },
{0.9133,0.3474,0.2127   },
{0.5180,0.7793,0.3526   },
{0.6432,0.6716,0.3679   },
{0.7506,0.5454,0.3730   },
{0.8375,0.4042,0.3679   },
{0.9012,0.2518,0.3526   },
{-0.3026,0.9312,-0.2034 },
{-0.3931,0.9169,-0.0695 },
{-0.2209,0.9728,-0.0695 },
{-0.4713,0.8792,0.0705  },
{-0.3082,0.9486,0.0717  },
{-0.1355,0.9883,0.0705  },
{-0.5347,0.8178,0.2127  },
{-0.3822,0.8977,0.2192  },
{-0.2184,0.9509,0.2192  },
{-0.0481,0.9759,0.2127  },
{-0.5811,0.7335,0.3526  },
{-0.4400,0.8192,0.3679  },
{-0.2867,0.8824,0.3730  },
{-0.1256,0.9214,0.3679  },
{0.0390,0.9350,0.3526   },
{-0.9791,-0.0000,-0.2034},
{-0.9935,-0.0905,-0.0695},
{-0.9935,0.0905,-0.0695 },
{-0.9818,-0.1765,0.0705 },
{-0.9974,-0.0000,0.0717 },
{-0.9818,0.1765,0.0705  },
{-0.9430,-0.2558,0.2127 },
{-0.9719,-0.0861,0.2192 },
{-0.9719,0.0861,0.2192  },
{-0.9430,0.2558,0.2127  },
{-0.8771,-0.3260,0.3526 },
{-0.9151,-0.1653,0.3679 },
{-0.9278,-0.0000,0.3730 },
{-0.9151,0.1653,0.3679  },
{-0.8771,0.3260,0.3526  },
{-0.3026,-0.9312,-0.2034},
{-0.2209,-0.9728,-0.0695},
{-0.3931,-0.9169,-0.0695},
{-0.1355,-0.9883,0.0705 },
{-0.3082,-0.9486,0.0717 },
{-0.4713,-0.8792,0.0705 },
{-0.0481,-0.9759,0.2127 },
{-0.2184,-0.9509,0.2192 },
{-0.3822,-0.8977,0.2192 },
{-0.5347,-0.8178,0.2127 },
{0.0390,-0.9350,0.3526  },
{-0.1256,-0.9214,0.3679 },
{-0.2867,-0.8824,0.3730 },
{-0.4400,-0.8192,0.3679 },
{-0.5811,-0.7335,0.3526 },
{0.7921,-0.5755,-0.2034 },
{0.8569,-0.5107,-0.0695 },
{0.7505,-0.6572,-0.0695 },
{0.8980,-0.4342,0.0705  },
{0.8069,-0.5863,0.0717  },
{0.6905,-0.7199,0.0705  },
{0.9133,-0.3474,0.2127  },
{0.8369,-0.5016,0.2192  },
{0.7356,-0.6409,0.2192  },
{0.6126,-0.7612,0.2127  },
{0.9012,-0.2518,0.3526  },
{0.8375,-0.4042,0.3679  },
{0.7506,-0.5454,0.3730  },
{0.6432,-0.6716,0.3679  },
{0.5180,-0.7793,0.3526  },
{0.0791,0.2435,-0.9667  },
{0.0320,0.3914,-0.9197  },
{0.2042,0.3355,-0.9197  },
{-0.0127,0.5321,-0.8466 },
{0.1577,0.4852,-0.8601  },
{0.3231,0.4230,-0.8466  },
{-0.0541,0.6611,-0.7483 },
{0.1130,0.6265,-0.7712  },
{0.2768,0.5732,-0.7712  },
{0.4324,0.5030,-0.7483  },
{-0.0914,0.7738,-0.6269 },
{0.0709,0.7532,-0.6540  },
{0.2313,0.7119,-0.6631  },
{0.3853,0.6510,-0.6540  },
{0.5287,0.5723,-0.6269  },
{-0.2071,0.1505,-0.9667 },
{-0.3624,0.1514,-0.9197 },
{-0.2560,0.2978,-0.9197 },
{-0.5100,0.1523,-0.8466 },
{-0.4127,0.2999,-0.8601 },
{-0.3025,0.4380,-0.8466 },
{-0.6455,0.1528,-0.7483 },
{-0.5609,0.3011,-0.7712 },
{-0.4597,0.4404,-0.7712 },
{-0.3448,0.5667,-0.7483 },
{-0.7641,0.1522,-0.6269 },
{-0.6944,0.3002,-0.6540 },
{-0.6056,0.4400,-0.6631 },
{-0.5001,0.5676,-0.6540 },
{-0.3809,0.6797,-0.6269 },
{-0.2071,-0.1505,-0.9667},
{-0.2560,-0.2978,-0.9197},
{-0.3624,-0.1514,-0.9197},
{-0.3025,-0.4380,-0.8466},
{-0.4127,-0.2999,-0.8601},
{-0.5100,-0.1523,-0.8466},
{-0.3448,-0.5667,-0.7483},
{-0.4597,-0.4404,-0.7712},
{-0.5609,-0.3011,-0.7712},
{-0.6455,-0.1528,-0.7483},
{-0.3809,-0.6797,-0.6269},
{-0.5001,-0.5676,-0.6540},
{-0.6056,-0.4400,-0.6631},
{-0.6944,-0.3002,-0.6540},
{-0.7641,-0.1522,-0.6269},
{0.0791,-0.2435,-0.9667 },
{0.2042,-0.3355,-0.9197 },
{0.0320,-0.3914,-0.9197 },
{0.3231,-0.4230,-0.8466 },
{0.1577,-0.4852,-0.8601 },
{-0.0127,-0.5321,-0.8466},
{0.4324,-0.5030,-0.7483 },
{0.2768,-0.5732,-0.7712 },
{0.1130,-0.6265,-0.7712 },
{-0.0541,-0.6611,-0.7483},
{0.5287,-0.5723,-0.6269 },
{0.3853,-0.6510,-0.6540 },
{0.2313,-0.7119,-0.6631 },
{0.0709,-0.7532,-0.6540 },
{-0.0914,-0.7738,-0.6269},
{0.2560,0.0000,-0.9667  },
{0.3822,0.0905,-0.9197  },
{0.3822,-0.0905,-0.9197 },
{0.5022,0.1765,-0.8466  },
{0.5102,0.0000,-0.8601  },
{0.5022,-0.1765,-0.8466 },
{0.6120,0.2558,-0.7483  },
{0.6307,0.0861,-0.7712  },
{0.6307,-0.0861,-0.7712 },
{0.6120,-0.2558,-0.7483 },
{0.7077,0.3260,-0.6269  },
{0.7383,0.1653,-0.6540  },
{0.7485,0.0000,-0.6631  },
{0.7383,-0.1653,-0.6540 },
{0.7077,-0.3260,-0.6269 }};
*/

	float tempTab[162][3] ={
{0.0000,0.0000,1.0000  },
{0.8944,0.0000,0.4472  },
{0.2764,0.8507,0.4472  },
{-0.7236,0.5257,0.4472 },
{-0.7236,-0.5257,0.4472},
{0.2764,-0.8507,0.4472 },
{0.7236,0.5257,-0.447  },
{-0.2764,0.8507,-0.447 },
{-0.8944,-0.0000,-0.447},
{-0.2764,-0.8507,-0.447},
{0.7236,-0.5257,-0.447 },
{0.0000,0.0000,-1.000  },
{0.2733,0.0000,0.9619  },
{0.5257,0.0000,0.8507  },
{0.7382,0.0000,0.6746  },
{0.0844,0.2599,0.9619  },
{0.1625,0.5000,0.8507  },
{0.2281,0.7020,0.6746  },
{-0.2211,0.1606,0.9619 },
{-0.4253,0.3090,0.8507 },
{-0.5972,0.4339,0.6746 },
{-0.2211,-0.1606,0.9619},
{-0.4253,-0.3090,0.8507},
{-0.5972,-0.4339,0.6746},
{0.0844,-0.2599,0.9619 },
{0.1625,-0.5000,0.8507 },
{0.2281,-0.7020,0.6746 },
{0.8226,0.2599,0.5057  },
{0.6882,0.5000,0.5257  },
{0.5014,0.7020,0.5057  },
{0.0070,0.8627,0.5057  },
{-0.2629,0.8090,0.5257 },
{-0.5128,0.6938,0.5057 },
{-0.8183,0.2733,0.5057 },
{-0.8507,-0.0000,0.5257},
{-0.8183,-0.2733,0.5057},
{-0.5128,-0.6938,0.5057},
{-0.2629,-0.8090,0.5257},
{0.0070,-0.8627,0.5057 },
{0.5014,-0.7020,0.5057 },
{0.6882,-0.5000,0.5257 },
{0.8226,-0.2599,0.5057 },
{0.9593,0.1606,0.2325  },
{0.9511,0.3090,0.0000  },
{0.8705,0.4339,-0.232  },
{0.1437,0.9619,0.2325  },
{-0.0000,1.0000,0.0000 },
{-0.1437,0.9619,-0.232 },
{-0.8705,0.4339,0.2325 },
{-0.9511,0.3090,0.0000 },
{-0.9593,0.1606,-0.232 },
{-0.6816,-0.6938,0.2325},
{-0.5878,-0.8090,0.0000},
{-0.4492,-0.8627,-0.232},
{0.4492,-0.8627,0.2325 },
{0.5878,-0.8090,0.0000 },
{0.6816,-0.6938,-0.232 },
{0.9593,-0.1606,0.2325 },
{0.9511,-0.3090,0.0000 },
{0.8705,-0.4339,-0.232 },
{0.4492,0.8627,0.2325  },
{0.5878,0.8090,0.0000  },
{0.6816,0.6938,-0.232  },
{-0.6816,0.6938,0.2325 },
{-0.5878,0.8090,0.0000 },
{-0.4492,0.8627,-0.232 },
{-0.8705,-0.4339,0.2325},
{-0.9511,-0.3090,0.0000},
{-0.9593,-0.1606,-0.232},
{0.1437,-0.9619,0.2325 },
{0.0000,-1.0000,0.0000 },
{-0.1437,-0.9619,-0.232},
{0.5128,0.6938,-0.505  },
{0.2629,0.8090,-0.525  },
{-0.0070,0.8627,-0.505 },
{-0.5014,0.7020,-0.505 },
{-0.6882,0.5000,-0.525 },
{-0.8226,0.2599,-0.505 },
{-0.8226,-0.2599,-0.505},
{-0.6882,-0.5000,-0.525},
{-0.5014,-0.7020,-0.505},
{-0.0070,-0.8627,-0.505},
{0.2629,-0.8090,-0.525 },
{0.5128,-0.6938,-0.505 },
{0.8183,-0.2733,-0.505 },
{0.8507,0.0000,-0.525  },
{0.8183,0.2733,-0.505  },
{0.2211,0.1606,-0.961  },
{0.4253,0.3090,-0.850  },
{0.5972,0.4339,-0.674  },
{-0.0844,0.2599,-0.961 },
{-0.1625,0.5000,-0.850 },
{-0.2281,0.7020,-0.674 },
{-0.2733,-0.0000,-0.961},
{-0.5257,-0.0000,-0.850},
{-0.7382,-0.0000,-0.674},
{-0.0844,-0.2599,-0.961},
{-0.1625,-0.5000,-0.850},
{-0.2281,-0.7020,-0.674},
{0.2211,-0.1606,-0.961 },
{0.4253,-0.3090,-0.850 },
{0.5972,-0.4339,-0.674 },
{0.3618,0.2629,0.8944  },
{0.6179,0.2647,0.7404  },
{0.4427,0.5058,0.7404  },
{-0.1382,0.4253,0.8944 },
{-0.0608,0.6694,0.7404 },
{-0.3443,0.5773,0.7404 },
{-0.4472,-0.0000,0.8944},
{-0.6554,0.1490,0.7404 },
{-0.6554,-0.1490,0.7404},
{-0.1382,-0.4253,0.8944},
{-0.3443,-0.5773,0.7404},
{-0.0608,-0.6694,0.7404},
{0.3618,-0.2629,0.8944 },
{0.4427,-0.5058,0.7404 },
{0.6179,-0.2647,0.7404 },
{1.0000,0.0000,0.0000  },
{0.9554,-0.1490,-0.255 },
{0.9554,0.1490,-0.255  },
{0.3090,0.9511,0.0000  },
{0.4370,0.8625,-0.255  },
{0.1535,0.9547,-0.255  },
{-0.8090,0.5878,0.0000 },
{-0.6853,0.6821,-0.255 },
{-0.8605,0.4410,-0.255 },
{-0.8090,-0.5878,0.0000},
{-0.8605,-0.4410,-0.255},
{-0.6853,-0.6821,-0.255},
{0.3090,-0.9511,0.0000 },
{0.1535,-0.9547,-0.255 },
{0.4370,-0.8625,-0.255 },
{0.8090,0.5878,0.0000  },
{0.6853,0.6821,0.2551  },
{0.8605,0.4410,0.2551  },
{-0.3090,0.9511,0.0000 },
{-0.4370,0.8625,0.2551 },
{-0.1535,0.9547,0.2551 },
{-1.0000,-0.0000,0.0000},
{-0.9554,-0.1490,0.2551},
{-0.9554,0.1490,0.2551 },
{-0.3090,-0.9511,0.0000},
{-0.1535,-0.9547,0.2551},
{-0.4370,-0.8625,0.2551},
{0.8090,-0.5878,0.0000 },
{0.8605,-0.4410,0.2551 },
{0.6853,-0.6821,0.2551 },
{0.1382,0.4253,-0.894  },
{0.0608,0.6694,-0.740  },
{0.3443,0.5773,-0.740  },
{-0.3618,0.2629,-0.894 },
{-0.6179,0.2647,-0.740 },
{-0.4427,0.5058,-0.740 },
{-0.3618,-0.2629,-0.894},
{-0.4427,-0.5058,-0.740},
{-0.6179,-0.2647,-0.740},
{0.1382,-0.4253,-0.894 },
{0.3443,-0.5773,-0.740 },
{0.0608,-0.6694,-0.740 },
{0.4472,0.0000,-0.894  },
{0.6554,0.1490,-0.740  },
{0.6554,-0.1490,-0.740 }};

	Points = new vec3_t[NbPoints];
	for (int i=0;i<NbPoints;i++)
	{
		Points[i]=tempTab[i];
	}
}

Grid::~Grid()
{
    delete Points;
}

int Grid::GetNearest(vec3_t v)
{
    int bestI = -1;
    float bestDot = -2.;

	vec3_t v2(v);
	v2.normalize();
    for(int i=0;i<NbPoints;i++)
    {
        if (v2.dot(Points[i])>bestDot)
        {
            bestI = i;
            bestDot = v2.dot(Points[i]);
        }
    }
    return bestI;
}

void Grid::Draw(void)
{
	for(int i=0;i<NbPoints;i++)
    {
    	DrawPoint(Points[i][0],Points[i][1],Points[i][2]);
	}
}

// Return an array with the number of the zones in the field of view
int Grid::Intersect(vec3_t pos, float fieldAngle, int * &result)
{
	if (result==NULL) result = new int[NbPoints];

	pos.normalize();
	float max = cos(fieldAngle/2+Angle/2);

	int nbResult=0;
	for(int i=0;i<NbPoints;i++)
	{
		if(pos.dot(Points[i]) > max)
		{
			result[nbResult]=i;
			nbResult++;
		}
	}
	return nbResult;
}
