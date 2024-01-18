
#include <IRremote.h>
IRsend irsend;

//Padrao sinal RAW Ligar Ar Condicionado SAMSUNG
unsigned int S_pwr[3339]={3088, 1612, 472, 1112, 476, 1108, 500, 320, 476, 344, 472, 348, 472, 1112, 472, 348, 496, 232, 564, 1112, 468, 1116, 472, 348, 472, 1112, 496, 236, 560, 344, 476, 1112, 472, 1112, 472, 348, 496, 1088, 472, 1112, 476, 292, 524, 348, 472, 1112, 472, 296, 524, 348, 472, 344, 476, 1112, 472, 348, 472, 348, 472, 296, 524, 288, 532, 344, 476, 284, 532, 348, 472, 348, 472, 348, 472, 344, 476, 296, 524, 292, 528, 348, 468, 348, 476, 344, 476, 344, 472, 348, 472, 324, 496, 328, 492, 324, 496, 1092, 496, 320, 500, 320, 508, 308, 500, 324, 500, 320, 520, 292, 504, 320, 504, 1084, 500, 1088, 496, 1088, 496, 1088, 500, 320, 500, 320, 496, 324, 496, 324, 496, 320, 500, 320, 500, 1088, 496, 1088, 500, 320, 500, 320, 500, 316, 500, 320, 500, 320, 500, 1088, 496, 324, 496, 320, 500, 324, 496, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 496, 324, 496, 324, 496, 324, 500, 320, 496, 324, 496, 324, 496, 324, 496, 324, 520, 296, 524, 296, 500, 324, 520, 296, 500, 324, 496, 324, 496, 324, 496, 324, 496, 324, 496, 324, 496, 324, 492, 328, 492, 328, 496, 1088, 496, 1092, 496, 324, 492, 1092, 496, 344, 472, 1092, 496, 328, 492, 1092, 492, 12876, 3084, 1592, 496, 1092, 492, 1092, 492, 328, 492, 328, 492, 328, 492, 1092, 492, 328, 492, 324, 492, 1092, 496, 1092, 492, 328, 492, 1092, 492, 328, 492, 348, 468, 1096, 492, 1092, 492, 348, 472, 1096, 488, 1116, 468, 352, 468, 348, 472, 1116, 468, 348, 472, 348, 472, 1116, 468, 352, 468, 348, 472, 348, 472, 348, 472, 348, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 348, 472, 352, 468, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 468, 1120, 468, 352, 468, 352, 468, 1116, 468, 1120, 468, 348, 472, 348, 472, 348, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 1116, 468, 1120, 468, 352, 468, 348, 472, 348, 472, 348, 468, 1120, 468, 352, 468, 1116, 468, 352, 468, 352, 468, 352, 468, 352, 464, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 464, 356, 468, 352, 468, 352, 464, 356, 468, 352, 464, 360, 460, 356, 464, 356, 464, 356, 464, 356, 460, 360, 460, 360, 460, 360, 460, 360, 460, 360, 460, 360, 460, 1128, 460, 1124, 464, 356, 464, 356, 460, 1124, 464, 360, 456, 360, 464, 1124, 460, 1124, 460, 31480, 3116, 1588, 476, 1112, 496, 1088, 476, 344, 496, 240, 580, 232, 588, 1092, 472, 288, 532, 288, 532, 1112, 476, 1112, 472, 288, 556, 1088, 476, 344, 472, 292, 532, 1112, 488, 1096, 480, 284, 532, 1112, 472, 1116, 472, 288, 532, 292, 528, 1112, 476, 292, 528, 344, 476, 288, 532, 1088, 520, 192, 604, 232, 588, 240, 580, 320, 504, 320, 500, 316, 500, 324, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 504, 316, 500, 320, 504, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 1092, 496, 320, 504, 320, 496, 324, 500, 320, 500, 320, 500, 320, 500, 320, 500, 1092, 496, 1088, 520, 1068, 496, 1088, 500, 324, 496, 320, 500, 320, 500, 324, 492, 328, 496, 324, 492, 1092, 496, 1092, 496, 324, 496, 324, 496, 324, 496, 324, 496, 324, 496, 1092, 496, 328, 492, 328, 492, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 476, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 356, 464, 352, 472, 348, 472, 348, 472, 352, 468, 352, 468, 352, 468, 352, 468, 356, 464, 356, 468, 352, 468, 352, 468, 356, 464, 356, 464, 356, 464, 356, 464, 1124, 464, 1124, 460, 360, 460, 1128, 460, 360, 460, 1128, 460, 360, 460, 1128, 460, 6580, 3060, 1620, 468, 1120, 468, 1116, 468, 352, 468, 352, 468, 352, 468, 1120, 468, 348, 472, 352, 468, 1116, 468, 1120, 468, 352, 468, 1120, 464, 352, 472, 348, 472, 1116, 468, 1120, 468, 352, 468, 1120, 464, 1120, 468, 352, 468, 352, 468, 1120, 468, 352, 468, 352, 468, 1116, 468, 356, 464, 352, 468, 352, 468, 352, 468, 356, 464, 356, 468, 352, 464, 356, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 356, 464, 356, 468, 352, 468, 352, 468, 1120, 468, 352, 468, 352, 468, 1120, 468, 352, 468, 352, 468, 1120, 468, 1120, 464, 356, 464, 356, 464, 356, 464, 356, 464, 356, 464, 356, 468, 352, 62460, 65272, 1000, 64536, 0, 0, 197, 65535, 65532, 1, 1, 4, 65339, 2559, 61457, 65511, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8192, 3120, 240, 65296, 3056, 273, 62209, 238, 1043, 65279, 61434, 5126, 3076, 1540, 59893, 4353, 776, 63483, 2288, 793, 64256, 60659, 5121, 262, 63232, 2797, 2537, 277, 63746, 233, 2578, 62725, 18153, 13533, 4066, 60736, 34944, 16400, 2324, 933, 916, 19875, 44104, 44821, 34291, 51535, 29035, 21222, 41816, 32631, 15009, 17719, 58025, 13343, 1120, 24120, 40998, 44955, 16808, 19962, 37794, 11165, 57455, 34324, 12863, 26053, 27175, 63173, 25166, 4561, 46451, 31034, 26484, 17236, 4584, 46032, 31088, 36331, 49317, 7240, 41343, 46459, 43461, 4305, 33808, 62976, 6288, 50948, 8172, 8048, 59110, 24391, 48891, 25492, 28588, 7296, 21557, 48891, 51965, 26512, 52168, 57867, 64560, 7632, 1648, 58952, 55197, 63321, 41022, 22310, 53410, 17091, 20767, 51449, 58153, 33280, 48760, 1373, 65254, 1488, 4572, 59578, 63504, 65489, 8955, 56739, 47454, 14087, 0, 65280, 6905, 51463, 7168, 63992, 19970, 51454, 37890, 38861, 25135, 4031, 25041, 55368, 57900, 45310, 64775, 43271, 2547, 55032, 64256, 41763, 24029, 65465, 65348, 107, 385, 511, 64770, 788, 64671, 59671, 65379, 5888, 0, 35328, 24577, 11519, 56065, 22016, 56832, 5120, 54016, 62217, 2294, 7428, 55036, 10255, 55281, 65336, 3088, 1612, 472, 1112, 476, 1108, 500, 320, 476, 344, 472, 348, 472, 1112, 472, 348, 496, 232, 564, 1112, 468, 1116, 472, 348, 472, 1112, 496, 236, 560, 344, 476, 1112, 472, 1112, 472, 348, 496, 1088, 472, 1112, 476, 292, 524, 348, 472, 1112, 472, 296, 524, 348, 472, 344, 476, 1112, 472, 348, 472, 348, 472, 296, 524, 288, 532, 344, 476, 284, 532, 348, 472, 348, 472, 348, 472, 344, 476, 296, 524, 292, 528, 348, 468, 348, 476, 344, 476, 344, 472, 348, 472, 324, 496, 328, 492, 324, 496, 1092, 496, 320, 500, 320, 508, 308, 500, 324, 500, 320, 520, 292, 504, 320, 504, 1084, 500, 1088, 496, 1088, 496, 1088, 500, 320, 500, 320, 496, 324, 496, 324, 496, 320, 500, 320, 500, 1088, 496, 1088, 500, 320, 500, 320, 500, 316, 500, 320, 500, 320, 500, 1088, 496, 324, 496, 320, 500, 324, 496, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 496, 324, 496, 324, 496, 324, 500, 320, 496, 324, 496, 324, 496, 324, 496, 324, 520, 296, 524, 296, 500, 324, 520, 296, 500, 324, 496, 324, 496, 324, 496, 324, 496, 324, 496, 324, 496, 324, 492, 328, 492, 328, 496, 1088, 496, 1092, 496, 324, 492, 1092, 496, 344, 472, 1092, 496, 328, 492, 1092, 492, 12876, 3084, 1592, 496, 1092, 492, 1092, 492, 328, 492, 328, 492, 328, 492, 1092, 492, 328, 492, 324, 492, 1092, 496, 1092, 492, 328, 492, 1092, 492, 328, 492, 348, 468, 1096, 492, 1092, 492, 348, 472, 1096, 488, 1116, 468, 352, 468, 348, 472, 1116, 468, 348, 472, 348, 472, 1116, 468, 352, 468, 348, 472, 348, 472, 348, 472, 348, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 348, 472, 352, 468, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 468, 1120, 468, 352, 468, 352, 468, 1116, 468, 1120, 468, 348, 472, 348, 472, 348, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 1116, 468, 1120, 468, 352, 468, 348, 472, 348, 472, 348, 468, 1120, 468, 352, 468, 1116, 468, 352, 468, 352, 468, 352, 468, 352, 464, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 464, 356, 468, 352, 468, 352, 464, 356, 468, 352, 464, 360, 460, 356, 464, 356, 464, 356, 464, 356, 460, 360, 460, 360, 460, 360, 460, 360, 460, 360, 460, 360, 460, 1128, 460, 1124, 464, 356, 464, 356, 460, 1124, 464, 360, 456, 360, 464, 1124, 460, 1124, 460, 31480, 3116, 1588, 476, 1112, 496, 1088, 476, 344, 496, 240, 580, 232, 588, 1092, 472, 288, 532, 288, 532, 1112, 476, 1112, 472, 288, 556, 1088, 476, 344, 472, 292, 532, 1112, 488, 1096, 480, 284, 532, 1112, 472, 1116, 472, 288, 532, 292, 528, 1112, 476, 292, 528, 344, 476, 288, 532, 1088, 520, 192, 604, 232, 588, 240, 580, 320, 504, 320, 500, 316, 500, 324, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 504, 316, 500, 320, 504, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 1092, 496, 320, 504, 320, 496, 324, 500, 320, 500, 320, 500, 320, 500, 320, 500, 1092, 496, 1088, 520, 1068, 496, 1088, 500, 324, 496, 320, 500, 320, 500, 324, 492, 328, 496, 324, 492, 1092, 496, 1092, 496, 324, 496, 324, 496, 324, 496, 324, 496, 324, 496, 1092, 496, 328, 492, 328, 492, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 476, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 356, 464, 352, 472, 348, 472, 348, 472, 352, 468, 352, 468, 352, 468, 352, 468, 356, 464, 356, 468, 352, 468, 352, 468, 356, 464, 356, 464, 356, 464, 356, 464, 1124, 464, 1124, 460, 360, 460, 1128, 460, 360, 460, 1128, 460, 360, 460, 1128, 460, 6580, 3060, 1620, 468, 1120, 468, 1116, 468, 352, 468, 352, 468, 352, 468, 1120, 468, 348, 472, 352, 468, 1116, 468, 1120, 468, 352, 468, 1120, 464, 352, 472, 348, 472, 1116, 468, 1120, 468, 352, 468, 1120, 464, 1120, 468, 352, 468, 352, 468, 1120, 468, 352, 468, 352, 468, 1116, 468, 356, 464, 352, 468, 352, 468, 352, 468, 356, 464, 356, 468, 352, 464, 356, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 356, 464, 356, 468, 352, 468, 352, 468, 1120, 468, 352, 468, 352, 468, 1120, 468, 352, 468, 352, 468, 1120, 468, 1120, 464, 356, 464, 356, 464, 356, 464, 356, 464, 356, 464, 356, 468, 352, 62460, 65272, 1000, 64536, 0, 0, 197, 65535, 65532, 1, 1, 4, 65339, 5887, 58142, 65498, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12288, 61484, 4097, 61439, 3076, 240, 65296, 1008, 61452, 60919, 5633, 771, 1, 59131, 5641, 64766, 60665, 5889, 64010, 61173, 3077, 239, 3093, 60659, 5633, 3, 773, 59127, 5641, 64766, 60665, 33537, 24531, 8448, 29849, 26471, 0, 14080, 45570, 5886, 0, 256, 64768, 63752, 65447, 5639, 40960, 39689, 168, 61, 15843, 49632, 253, 65281, 47288, 0, 0, 0, 65503, 57345, 45489, 0, 0, 0, 1023, 65281, 57347, 29437, 184, 0, 0, 4280, 61184, 1, 0, 0, 47288, 0, 2301, 63364, 65407, 184, 37159, 28600, 256, 65279, 256, 65280, 47288, 0, 0, 184, 34425, 30976, 184, 255, 65283, 13237, 42641, 37120, 0, 0, 47288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 183, 23208, 2044, 184, 184, 65018, 519, 65281, 696, 1202, 2560, 61440, 47288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12544, 65352, 5888, 0, 35328, 24577, 11519, 56065, 22016, 56832, 5120, 54016, 62217, 15094, 60650, 54550, 10730, 54806, 65336, 3088, 1612, 472, 1112, 476, 1108, 500, 320, 476, 344, 472, 348, 472, 1112, 472, 348, 496, 232, 564, 1112, 468, 1116, 472, 348, 472, 1112, 496, 236, 560, 344, 476, 1112, 472, 1112, 472, 348, 496, 1088, 472, 1112, 476, 292, 524, 348, 472, 1112, 472, 296, 524, 348, 472, 344, 476, 1112, 472, 348, 472, 348, 472, 296, 524, 288, 532, 344, 476, 284, 532, 348, 472, 348, 472, 348, 472, 344, 476, 296, 524, 292, 528, 348, 468, 348, 476, 344, 476, 344, 472, 348, 472, 324, 496, 328, 492, 324, 496, 1092, 496, 320, 500, 320, 508, 308, 500, 324, 500, 320, 520, 292, 504, 320, 504, 1084, 500, 1088, 496, 1088, 496, 1088, 500, 320, 500, 320, 496, 324, 496, 324, 496, 320, 500, 320, 500, 1088, 496, 1088, 500, 320, 500, 320, 500, 316, 500, 320, 500, 320, 500, 1088, 496, 324, 496, 320, 500, 324, 496, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 496, 324, 496, 324, 496, 324, 500, 320, 496, 324, 496, 324, 496, 324, 496, 324, 520, 296, 524, 296, 500, 324, 520, 296, 500, 324, 496, 324, 496, 324, 496, 324, 496, 324, 496, 324, 496, 324, 492, 328, 492, 328, 496, 1088, 496, 1092, 496, 324, 492, 1092, 496, 344, 472, 1092, 496, 328, 492, 1092, 492, 12876, 3084, 1592, 496, 1092, 492, 1092, 492, 328, 492, 328, 492, 328, 492, 1092, 492, 328, 492, 324, 492, 1092, 496, 1092, 492, 328, 492, 1092, 492, 328, 492, 348, 468, 1096, 492, 1092, 492, 348, 472, 1096, 488, 1116, 468, 352, 468, 348, 472, 1116, 468, 348, 472, 348, 472, 1116, 468, 352, 468, 348, 472, 348, 472, 348, 472, 348, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 348, 472, 352, 468, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 468, 1120, 468, 352, 468, 352, 468, 1116, 468, 1120, 468, 348, 472, 348, 472, 348, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 1116, 468, 1120, 468, 352, 468, 348, 472, 348, 472, 348, 468, 1120, 468, 352, 468, 1116, 468, 352, 468, 352, 468, 352, 468, 352, 464, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 464, 356, 468, 352, 468, 352, 464, 356, 468, 352, 464, 360, 460, 356, 464, 356, 464, 356, 464, 356, 460, 360, 460, 360, 460, 360, 460, 360, 460, 360, 460, 360, 460, 1128, 460, 1124, 464, 356, 464, 356, 460, 1124, 464, 360, 456, 360, 464, 1124, 460, 1124, 460, 31480, 3116, 1588, 476, 1112, 496, 1088, 476, 344, 496, 240, 580, 232, 588, 1092, 472, 288, 532, 288, 532, 1112, 476, 1112, 472, 288, 556, 1088, 476, 344, 472, 292, 532, 1112, 488, 1096, 480, 284, 532, 1112, 472, 1116, 472, 288, 532, 292, 528, 1112, 476, 292, 528, 344, 476, 288, 532, 1088, 520, 192, 604, 232, 588, 240, 580, 320, 504, 320, 500, 316, 500, 324, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 504, 316, 500, 320, 504, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 1092, 496, 320, 504, 320, 496, 324, 500, 320, 500, 320, 500, 320, 500, 320, 500, 1092, 496, 1088, 520, 1068, 496, 1088, 500, 324, 496, 320, 500, 320, 500, 324, 492, 328, 496, 324, 492, 1092, 496, 1092, 496, 324, 496, 324, 496, 324, 496, 324, 496, 324, 496, 1092, 496, 328, 492, 328, 492, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 476, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 348, 472, 356, 464, 352, 472, 348, 472, 348, 472, 352, 468, 352, 468, 352, 468, 352, 468, 356, 464, 356, 468, 352, 468, 352, 468, 356, 464, 356, 464, 356, 464, 356, 464, 1124, 464, 1124, 460, 360, 460, 1128, 460, 360, 460, 1128, 460, 360, 460, 1128, 460, 6580, 3060, 1620, 468, 1120, 468, 1116, 468, 352, 468, 352, 468, 352, 468, 1120, 468, 348, 472, 352, 468, 1116, 468, 1120, 468, 352, 468, 1120, 464, 352, 472, 348, 472, 1116, 468, 1120, 468, 352, 468, 1120, 464, 1120, 468, 352, 468, 352, 468, 1120, 468, 352, 468, 352, 468, 1116, 468, 356, 464, 352, 468, 352, 468, 352, 468, 356, 464, 356, 468, 352, 464, 356, 468, 352, 468, 352, 468, 352, 468, 352, 468, 352, 468, 356, 464, 356, 468, 352, 468, 352, 468, 1120, 468, 352, 468, 352, 468, 1120, 468, 352, 468, 352, 468, 1120, 468, 1120, 464, 356, 464, 356, 464, 356, 464, 356, 464, 356, 464, 356, 468, 352, 62460, 65272, 1000, 64536, 0, 0, 197, 65535, 65532, 1, 1, 4, 65339, 12287, 51512, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8192, 3120, 240, 65296, 1008, 59388, 5377, 65036, 1279, 59380, 4873, 1026, 59637, 5633, 64008, 1534, 59897, 4612, 64252, 2542, 64532, 1, 60919, 4609, 520, 63485, 2542, 65300, 64767, 60921, 4353, 1, 16895, 13521, 4066, 60736, 34944, 16400, 2324, 933, 916, 19875, 44104, 44821, 34291, 51535, 29035, 21222, 41816, 32631, 15009, 17719, 58025, 13343, 1120, 24120, 40998, 44955, 16808, 19962, 37794, 11165, 57455, 34324, 12863, 26053, 27175, 63173, 25166, 4561, 46451, 31034, 26484, 17236, 4584, 46032, 31088, 36331, 49317, 7240, 41343, 46459, 43461, 4305, 33808, 62976, 6288, 50948, 8172, 8048, 59110, 24391, 48891, 25492, 28588, 7296, 21557, 48891, 51965, 26512, 52168, 57867, 64560, 7632, 1648, 58952, 55197, 63321, 41022, 22310, 53410, 17091, 20767, 51449, 58153, 33280, 48760, 1373, 65254, 1488, 14300, 417, 63530, 65493, 8955, 56739, 47454, 14087, 0, 65280, 6905, 51463, 7168, 63992, 19970, 51454, 37890, 38861, 25135, 4031, 25041, 55368, 57900, 45310, 64775, 52780, 58574, 55288, 64256, 41763, 24029, 65468, 65351, 107, 385, 2559, 62722, 788, 64671, 59671, 65379, 5888, 0, 35328, 24577, 11519, 56065, 22016, 56832, 5120, 54016, 62217, 11254, 64997, 54042, 11225, 54310, 65336, 3088, 1612, 472, 1112, 476, 1108, 500, 320, 476, 344, 472, 348, 472, 1112, 472, 348, 496, 232, 564, 1112, 468, 1116, 472, 348, 472, 1112, 496, 236, 560, 344, 476, 1112, 472, 1112, 472, 348, 496, 1088, 472, 1112, 476, 292, 524, 348, 472, 1112, 472, 296, 524, 348, 472, 344, 476, 1112, 472, 348, 472, 348, 472, 296, 524, 288, 532, 344, 476, 284, 532, 348, 472, 348, 472, 348, 472, 344, 476, 296, 524, 292, 528, 348, 468, 348, 476, 344, 476, 344, 472, 348, 472, 324, 496, 328, 492, 324, 496, 1092, 496, 320, 500, 320, 508, 308, 500, 324, 500, 320, 520, 292, 504, 320, 504, 1084, 500, 1088, 496, 1088, 496, 1088, 500, 320, 500, 320, 496, 324, 496, 324, 496, 320, 500, 320, 500, 1088, 496, 1088, 500, 320, 500, 320, 500, 316, 500, 320, 500, 320, 500, 1088, 496, 324, 496, 320, 500, 324, 496, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 500, 320, 496, 324, 496, 324, 496, 324, 500, 320, 496, 324, 496, 324, 496, 324, 496, 324, 520, 296, 524, 296, 500, 324, 520, 296, 500, 324, 496, 324, 496, 324, 496, 324, 496, 324, 496, 324, 496, 324, 492, 328, 492, 328, 496, 1088, 496, 1092, 496, 324, 492, 1092, 496, 344, 472, 1092, 496, 328, 492, 1092, 492, 12876, 3084, 1592, 496, 1092, 492, 1092, 492, 328, 492, 328, 492, 328, 492, 1092, 492, 328, 492, 324, 492, 1092, 496, 1092, 492, 328, 492, 1092, 492, 328, 492, 348, 468, 1096, 492, 1092, 492, 348, 472, 1096, 488};



//#######################IMPORTANTE#######################
//Porta de envio padrao de sinal: PWM 9(MEGA) e 3(PROMINI)

void setup(){
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop() {
    Serial.println("Ligando...");
    irsend.sendRaw(S_pwr, 3339, 38);
    Serial.println("Executando a 38 Hz");
    delay(2000);
    

}
