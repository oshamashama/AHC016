#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;
const double time_limit = 4.8 / 10.0;
// while (clock() < int(double(time_limit) * double(CLOCKS_PER_SEC)))
// {
// }
vector<vector<int>> node = {{},
                            {},
                            {},
                            {0, 1, 3, 7},
                            {0, 1, 3, 7, 11, 12, 13, 15, 30, 31, 63},
                            {0, 1, 3, 7, 15, 19, 20, 21, 23, 28, 29, 31, 54, 55, 58, 59, 62, 63, 126, 127, 183, 187, 191, 207, 220, 223, 254, 255, 495, 511, 1023},
                            {0, 1, 3, 7, 15, 31, 35, 36, 37, 39, 44, 45, 47, 60, 61, 63, 102, 103, 106, 107, 110, 111, 120, 121, 122, 123, 126, 127, 238, 239, 246, 247, 254, 255, 510, 511, 615, 619, 623, 632, 635, 639, 655, 656, 671, 684, 687, 691, 700, 703, 750, 751, 758, 759, 762, 763, 766, 767, 926, 927, 956, 958, 959, 1022, 1023, 1743, 1759, 1775, 1783, 1788, 1789, 1791, 1880, 1887, 1915, 1916, 1919, 2014, 2015, 2046, 2047, 4060, 4061, 4063, 4095, 5871, 5879, 5887, 6007, 6015, 6142, 6143, 6655, 7071, 7166, 7167, 8159, 8191, 15870, 15871, 16383, 32767},
                            {0, 1, 3, 7, 15, 31, 63, 67, 68, 69, 71, 76, 77, 79, 92, 93, 95, 124, 125, 127, 198, 199, 202, 203, 206, 207, 216, 217, 218, 219, 222, 223, 248, 249, 250, 251, 254, 255, 462, 463, 470, 471, 478, 479, 498, 499, 502, 503, 510, 511, 990, 991, 1006, 1007, 1022, 1023, 2046, 2047, 2247, 2251, 2255, 2264, 2267, 2271, 2296, 2299, 2303, 2319, 2320, 2335, 2352, 2367, 2380, 2383, 2387, 2396, 2399, 2416, 2419, 2428, 2431, 2510, 2511, 2518, 2519, 2522, 2523, 2526, 2527, 2546, 2547, 2550, 2551, 2552, 2554, 2555, 2558, 2559, 2846, 2847, 2878, 2879, 2908, 2910, 2911, 2940, 2942, 2943, 3038, 3039, 3054, 3055, 3066, 3067, 3070, 3071, 3902, 3903, 3964, 3966, 3967, 4094, 4095, 6543, 6559, 6576, 6591, 6607, 6615, 6620, 6621, 6623, 6643, 6644, 6647, 6652, 6653, 6655, 6808, 6815, 6840, 6847, 6875, 6876, 6879, 6887, 6904, 6907, 6908, 6911, 7070, 7071, 7102, 7103, 7134, 7135, 7150, 7151, 7158, 7159, 7164, 7165, 7166, 7167, 7740, 7743, 7804, 7807, 7864, 7870, 7871, 7930, 7931, 7932, 7934, 7935, 8126, 8127, 8190, 8191, 15260, 15261, 15263, 15276, 15292, 15293, 15295, 15327, 15343, 15356, 15357, 15359, 15796, 15804, 15807, 15863, 15868, 15871, 16316, 16317, 16318, 16319, 16382, 16383, 32700, 32701, 32703, 32767, 39375, 39383, 39391, 39415, 39423, 39639, 39647, 39655, 39671, 39679, 39902, 39903, 39918, 39919, 39926, 39927, 39934, 39935, 40496, 40511, 40694, 40695, 40702, 40703, 40958, 40959, 41951, 41983, 42047, 43007, 43807, 43839, 43998, 43999, 44030, 44031, 44287, 44862, 44863, 45054, 45055, 48031, 48063, 48095, 48111, 48119, 48124, 48125, 48127, 48575, 48631, 48636, 48639, 48824, 48831, 48892, 48895, 49086, 49087, 49150, 49151, 59326, 59327, 59391, 61244, 61247, 61374, 61375, 61438, 61439, 65468, 65469, 65471, 65535, 111582, 111583, 111614, 111615, 112638, 112639, 113631, 113647, 113659, 113663, 114159, 114167, 114175, 114495, 114556, 114559, 114686, 114687, 120383, 120831, 122623, 122687, 122878, 122879, 128958, 128959, 129022, 129023, 131007, 131071, 259903, 259964, 259965, 259967, 260094, 260095, 262143, 375775, 375791, 375807, 376303, 376319, 376830, 376831, 384511, 385022, 385023, 393151, 393215, 425983, 452607, 458687, 458751, 522238, 522239, 524287, 1015743, 1015807, 1048575, 2097151},
                            {0, 1, 3, 7, 15, 31, 63, 127, 131, 132, 133, 135, 140, 141, 143, 156, 157, 159, 188, 189, 191, 252, 253, 255, 390, 391, 394, 395, 398, 399, 408, 409, 410, 411, 414, 415, 440, 441, 442, 443, 446, 447, 504, 505, 506, 507, 510, 511, 910, 911, 918, 919, 926, 927, 946, 947, 950, 951, 958, 959, 1008, 1009, 1010, 1011, 1014, 1015, 1022, 1023, 1950, 1951, 1966, 1967, 1982, 1983, 2022, 2023, 2030, 2031, 2046, 2047, 4030, 4031, 4062, 4063, 4094, 4095, 8190, 8191, 8583, 8587, 8591, 8600, 8603, 8607, 8632, 8635, 8639, 8696, 8699, 8703, 8719, 8720, 8735, 8752, 8767, 8816, 8831, 8844, 8847, 8851, 8860, 8863, 8880, 8883, 8892, 8895, 8944, 8947, 8956, 8959, 9102, 9103, 9110, 9111, 9114, 9115, 9118, 9119, 9138, 9139, 9142, 9143, 9144, 9146, 9147, 9150, 9151, 9200, 9202, 9203, 9206, 9207, 9208, 9210, 9211, 9214, 9215, 9758, 9759, 9790, 9791, 9824, 9854, 9855, 9884, 9886, 9887, 9916, 9918, 9919, 9954, 9955, 9980, 9982, 9983, 10142, 10143, 10158, 10159, 10170, 10171, 10174, 10175, 10214, 10215, 10218, 10219, 10222, 10223, 10232, 10234, 10235, 10238, 10239, 11838, 11839, 11902, 11903, 11964, 11966, 11967, 12028, 12030, 12031, 12222, 12223, 12254, 12255, 12282, 12283, 12286, 12287, 15998, 15999, 16124, 16126, 16127, 16382, 16383, 25359, 25375, 25392, 25407, 25456, 25471, 25487, 25495, 25500, 25501, 25503, 25523, 25524, 25527, 25532, 25533, 25535, 25584, 25587, 25588, 25591, 25596, 25597, 25599, 25880, 25887, 25912, 25919, 25952, 25976, 25983, 26011, 26012, 26015, 26023, 26040, 26043, 26044, 26047, 26083, 26084, 26087, 26104, 26107, 26108, 26111, 26398, 26399, 26430, 26431, 26480, 26494, 26495, 26526, 26527, 26542, 26543, 26550, 26551, 26556, 26557, 26558, 26559, 26598, 26599, 26604, 26605, 26606, 26607, 26610, 26611, 26612, 26614, 26615, 26620, 26621, 26622, 26623, 27708, 27711, 27772, 27775, 27836, 27839, 27900, 27903, 27960, 27966, 27967, 28024, 28030, 28031, 28090, 28091, 28092, 28094, 28095, 28152, 28154, 28155, 28156, 28158, 28159, 28478, 28479, 28542, 28543, 28606, 28607, 28638, 28639, 28662, 28663, 28668, 28669, 28670, 28671, 31868, 31870, 31871, 31996, 31998, 31999, 32120, 32126, 32127, 32250, 32251, 32252, 32254, 32255, 32638, 32639, 32766, 32767, 59164, 59165, 59167, 59180, 59196, 59197, 59199, 59236, 59244, 59260, 59261, 59263, 59295, 59311, 59324, 59325, 59327, 59367, 59372, 59375, 59388, 59389, 59391, 60212, 60220, 60223, 60236, 60272, 60276, 60284, 60287, 60343, 60348, 60351, 60367, 60403, 60404, 60407, 60412, 60415, 61244, 61245, 61246, 61247, 61276, 61277, 61292, 61308, 61309, 61310, 61311, 61374, 61375, 61406, 61407, 61422, 61423, 61436, 61437, 61438, 61439, 63864, 63868, 63871, 63992, 63995, 63996, 63999, 64372, 64380, 64382, 64383, 64502, 64503, 64508, 64510, 64511, 65404, 65405, 65406, 65407, 65534, 65535, 126780, 126781, 126783, 126812, 126844, 126845, 126847, 126911, 126943, 126972, 126973, 126975, 128876, 128892, 128895, 129007, 129020, 129023, 130940, 130941, 130942, 130943, 131070, 131071, 262012, 262013, 262015, 262143, 287631, 287639, 287647, 287671, 287679, 287735, 287743, 288151, 288159, 288167, 288183, 288191, 288231, 288247, 288255, 288670, 288671, 288686, 288687, 288694, 288695, 288702, 288703, 288742, 288743, 288750, 288751, 288758, 288759, 288766, 288767, 289840, 289855, 289872, 289904, 289919, 290230, 290231, 290238, 290239, 290262, 290263, 290294, 290295, 290302, 290303, 290750, 290751, 290782, 290783, 290806, 290807, 290814, 290815, 294000, 294014, 294015, 294390, 294391, 294398, 294399, 294910, 294911, 296863, 296895, 296959, 297023, 297024, 297087, 298943, 298975, 299007, 301182, 301183, 303103, 304671, 304703, 304767, 305054, 305055, 305086, 305087, 305150, 305151, 305599, 305607, 305663, 306750, 306751, 306814, 306815, 307134, 307135, 307166, 307167, 307198, 307199, 309368, 309375, 309758, 309759, 310910, 310911, 311294, 311295, 321311, 321343, 321392, 321407, 321439, 321455, 321463, 321468, 321469, 321471, 321511, 321516, 321519, 321524, 321527, 321532, 321533, 321535, 322367, 322416, 322431, 322487, 322492, 322495, 322511, 322548, 322551, 322556, 322559, 322872, 322879, 322936, 322943, 323004, 323007, 323047, 323068, 323071, 323390, 323391, 323454, 323455, 323518, 323519, 323550, 323551, 323566, 323567, 323574, 323575, 323580, 323581, 323582, 323583, 326000, 326008, 326015, 326132, 326135, 326140, 326143, 326526, 326527, 326646, 326647, 326652, 326654, 326655, 326780, 326783, 327032, 327038, 327039, 327164, 327166, 327167, 327550, 327551, 327678, 327679, 364350, 364351, 364414, 364415, 364479, 364540, 364541, 364543, 368510, 368511, 368639, 372284, 372287, 372348, 372351, 372542, 372543, 372600, 372606, 372607, 372670, 372671, 372732, 372733, 372734, 372735, 376444, 376446, 376447, 376702, 376703, 376830, 376831, 388924, 388925, 388927, 388956, 388980, 388988, 388989, 388991, 389055, 389087, 389111, 389116, 389117, 389119, 391020, 391028, 391036, 391039, 391151, 391159, 391164, 391167, 392568, 392572, 392575, 392700, 392703, 393084, 393085, 393086, 393087, 393214, 393215, 499580, 499581, 499582, 499583, 499711, 507516, 507519, 507772, 507773, 507774, 507775, 507902, 507903, 524156, 524157, 524159, 524287, 837534, 837535, 837566, 837567, 837630, 837631, 839614, 839615, 839646, 839647, 839678, 839679, 841824, 841855, 843774, 843775, 845727, 845743, 845755, 845759, 845799, 845807, 845816, 845819, 845823, 846767, 846775, 846783, 846799, 846823, 846831, 846839, 846847, 847423, 847487, 847548, 847551, 847612, 847615, 847806, 847807, 847838, 847839, 847854, 847855, 847866, 847867, 847870, 847871, 850407, 850415, 850431, 850544, 850559, 850926, 850927, 850934, 850935, 850942, 850943, 851582, 851583, 851708, 851710, 851711, 851966, 851967, 871487, 871551, 872383, 872447, 875646, 875647, 876543, 880063, 880127, 880191, 880240, 880255, 880574, 880575, 880630, 880631, 880638, 880639, 881663, 883832, 883839, 884222, 884223, 884350, 884351, 884734, 884735, 905022, 905023, 905086, 905087, 905150, 905151, 905212, 905213, 905214, 905215, 909182, 909183, 909310, 909311, 913215, 913272, 913279, 913343, 913375, 913391, 913403, 913404, 913405, 913407, 915320, 915327, 915439, 915451, 915452, 915455, 916344, 916351, 916471, 916476, 916479, 917116, 917119, 917244, 917247, 917374, 917375, 917502, 917503, 990846, 990847, 991231, 999032, 999038, 999039, 999422, 999423, 1006716, 1006719, 1007486, 1007487, 1007615, 1015160, 1015167, 1015292, 1015295, 1015420, 1015423, 1015678, 1015679, 1015806, 1015807, 1040252, 1040253, 1040254, 1040255, 1040382, 1040383, 1048444, 1048445, 1048447, 1048575, 1953343, 1953407, 1953468, 1953469, 1953471, 1953532, 1953533, 1953535, 1953726, 1953727, 1953786, 1953787, 1953790, 1953791, 1955455, 1957502, 1957503, 1957628, 1957629, 1957630, 1957631, 1957886, 1957887, 1961919, 1961951, 1961979, 1961983, 1963999, 1964015, 1964031, 1965688, 1965695, 1965819, 1965820, 1965823, 1966078, 1966079, 2022000, 2022015, 2023038, 2023039, 2023423, 2030583, 2030591, 2031224, 2031231, 2031614, 2031615, 2088572, 2088573, 2088575, 2088700, 2088701, 2088703, 2088830, 2088831, 2088958, 2088959, 2097023, 2097151, 4185720, 4185721, 4185723, 4185727, 4185851, 4185852, 4185853, 4185855, 4186110, 4186111, 4194303, 5040031, 5040047, 5040063, 5040111, 5040127, 5041071, 5041087, 5041103, 5041135, 5041151, 5042110, 5042111, 5042142, 5042143, 5042158, 5042159, 5042174, 5042175, 5045230, 5045231, 5045246, 5045247, 5046270, 5046271, 5073855, 5073871, 5073919, 5074878, 5074879, 5074926, 5074927, 5074942, 5074943, 5075951, 5075967, 5078014, 5078015, 5079038, 5079039, 5107519, 5107583, 5107647, 5107679, 5107695, 5107708, 5107709, 5107711, 5109631, 5109743, 5109756, 5109759, 5110655, 5110767, 5110780, 5110783, 5111678, 5111679, 5111806, 5111807, 5183615, 5185535, 5208959, 5209084, 5209085, 5209087, 5209982, 5209983, 5210110, 5210111, 5242748, 5242749, 5242751, 5242879, 5369791, 5369855, 5373951, 5382143, 5505023, 5607359, 5607423, 5611519, 5631807, 5631871, 5631935, 5631996, 5631997, 5631999, 5635966, 5635967, 5636094, 5636095, 5668863, 5742463, 5742591, 5767036, 5767037, 5767039, 5767167, 6148030, 6148031, 6148094, 6148095, 6152190, 6152191, 6156223, 6156255, 6156271, 6156283, 6156287, 6158303, 6158319, 6158335, 6159359, 6159999, 6160124, 6160127, 6160382, 6160383, 6217727, 6224879, 6224895, 6225535, 6225918, 6225919, 6249599, 6250495, 6258303, 6258686, 6258687, 6283134, 6283135, 6283262, 6283263, 6291327, 6291455, 7593853, 7593855, 7593983, 7602175, 7839358, 7839359, 7839743, 7855998, 7855999, 7856126, 7856127, 7864191, 7864319, 8380031, 8380156, 8380157, 8380159, 8380414, 8380415, 8388607, 14282559, 14282623, 14282687, 14282748, 14282749, 14282751, 14286718, 14286719, 14286846, 14286847, 14417788, 14417789, 14417791, 14417919, 14544831, 14544863, 14544887, 14544895, 14546911, 14546927, 14546943, 14548479, 14548990, 14548991, 14612463, 14612479, 14613503, 14614526, 14614527, 14655487, 14663295, 14663678, 14663679, 14679935, 14680063, 15409151, 15466495, 15695870, 15695871, 15704063, 15728511, 15728639, 16506750, 16506751, 16506878, 16506879, 16514943, 16515071, 16769022, 16769023, 16777215, 33267710, 33267711, 33275519, 33275644, 33275647, 33275902, 33275903, 33292159, 33292287, 33554431, 48099263, 48099295, 48099327, 48101343, 48101375, 48103422, 48103423, 48166879, 48166911, 48168958, 48168959, 48234367, 48234495, 49217534, 49217535, 49282943, 49283071, 50323454, 50323455, 50331647, 54525951, 57933823, 58712062, 58712063, 58720255, 66846591, 66846719, 67108863, 130015230, 130015231, 130023423, 134217727, 268435455}};

int main(int argc, char const *argv[])
{
  random_device rd;
  mt19937 eng(137);
  uniform_int_distribution<int> d500(0, 1000000000);

  long long M;
  double e;
  cin >> M >> e;
  long long N = 6;
  for (int i = 0; i < 10; i++)
  {
    if (node.at(i).size() >= M)
    {
      N = i;
      break;
    }
  }
  long long NN2 = N * (N - 1) / 2;

  vector<pair<int, int>> vs(NN2);
  vector<vector<int>> edge_count(NN2 + 1);
  map<vector<int>, int> sorted_list_2_num;

  long long counter = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (i < j)
      {
        vs.at(counter) = make_pair(i, j);
        counter++;
      }
    }
  }

  cout << N << endl;
  for (int i = 0; i < M; i++)
  {
    long long edge_counter = 0;
    vector<int> v(N, 0);
    for (int j = 0; j < NN2; j++)
    {
      if ((node.at(N).at(i) >> j) & 1)
      {
        cout << 1;
        edge_counter++;
        v.at(vs.at(j).first)++;
        v.at(vs.at(j).second)++;
      }
      else
      {
        cout << 0;
      }
    }
    cout << endl;
    edge_count.at(edge_counter).push_back(i);
    sort(v.begin(), v.end());
    sorted_list_2_num[v] = i;
    // cout << i << '\t';
    // for (int j = 0; j < N; j++)
    //   cout << v.at(j) << (j == N - 1 ? '\n' : ' ');
  }
  for (int i = 0; i < 100; i++)
  {
    string S;
    cin >> S;
    long long ans = 0;
    vector<int> v(N);
    // cout << S << endl;
    long long edge_counter = 0;
    for (int j = 0; j < NN2; j++)
    {
      if (S.at(j) == '1')
      {
        edge_counter++;
        v.at(vs.at(j).first)++;
        v.at(vs.at(j).second)++;
      }
    }
    sort(v.begin(), v.end());
    // for (int j = 0; j < N; j++)
    //   cout << v.at(j) << (j == N - 1 ? '\n' : ' ');
    if (sorted_list_2_num.count(v) == true)
    {
      // cout << "memo" << endl;
      // cout << ans << endl;
      ans = sorted_list_2_num.at(v);
      // cout << "memo" << endl;
    }
    else
    {
      if ((0 <= (edge_counter - 1)) &&
          ((edge_counter - 1 < edge_count.size())) &&
          (edge_count.at(edge_counter - 1).size() != 0))
        ans = edge_count.at(edge_counter - 1).at(0);
      if ((0 <= (edge_counter + 1)) &&
          ((edge_counter + 1 < edge_count.size())) &&
          (edge_count.at(edge_counter + 1).size() != 0))
        ans = edge_count.at(edge_counter + 1).at(0);
    }
    cout << min(ans, M - 1) << endl;
    // cerr << i << endl;
  }
  return 0;
}
