#include <stdlib.h>
#include <stdio.h>

#include "rift.h"

static rift_led hmd_leds[] = {
  { .pos = {{63321.000000,-31734.000000,67534.000000}}, .dir={{0.181956,-0.102972,0.977900}}, .pattern=0x1 },
  { .pos = {{77003.000000,1460.000000,65643.000000}}, .dir={{0.299055,0.001984,0.954234}}, .pattern=0x6 },
  { .pos = {{29006.000000,-19167.000000,73205.000000}}, .dir={{0.082983,-0.096960,0.991823}}, .pattern=0x1a },
  { .pos = {{-92.000000,-33409.000000,72387.000000}}, .dir={{0.000000,-0.188028,0.982164}}, .pattern=0x1d },
  { .pos = {{-29277.000000,-19280.000000,73313.000000}}, .dir={{-0.082983,-0.096960,0.991823}}, .pattern=0x28 },
  { .pos = {{-63317.000000,-32109.000000,67604.000000}}, .dir={{-0.181956,-0.102972,0.977900}}, .pattern=0x2f },
  { .pos = {{-77328.000000,974.000000,65640.000000}}, .dir={{-0.299055,0.001984,0.954234}}, .pattern=0x33 },
  { .pos = {{-54084.000000,34504.000000,68768.000000}}, .dir={{-0.140969,0.134957,0.980772}}, .pattern=0x4b },
  { .pos = {{-20154.000000,17780.000000,74139.000000}}, .dir={{-0.056979,0.095951,0.993754}}, .pattern=0x4c },
  { .pos = {{53480.000000,34724.000000,68953.000000}}, .dir={{0.140969,0.134957,0.980772}}, .pattern=0x57 },
  { .pos = {{19668.000000,17820.000000,74205.000000}}, .dir={{0.056979,0.095951,0.993754}}, .pattern=0x62 },
  { .pos = {{-78986.000000,-12270.000000,28013.000000}}, .dir={{-0.993057,-0.099980,-0.061984}}, .pattern=0x65 },
  { .pos = {{-77680.000000,-12236.000000,-8572.000000}}, .dir={{-0.981566,-0.188915,-0.028963}}, .pattern=0x79 },
  { .pos = {{-70629.000000,-31636.000000,9905.000000}}, .dir={{-0.734056,-0.668042,-0.121987}}, .pattern=0x7e },
  { .pos = {{-58930.000000,-40868.000000,36014.000000}}, .dir={{-0.153997,-0.983099,-0.099003}}, .pattern=0x90 },
  { .pos = {{59269.000000,-40973.000000,36524.000000}}, .dir={{0.153997,-0.983099,-0.099003}}, .pattern=0xa4 },
  { .pos = {{28475.000000,-43555.000000,61577.000000}}, .dir={{-0.004975,-0.998636,-0.051974}}, .pattern=0x114 },
  { .pos = {{-80405.000000,-24558.000000,53251.000000}}, .dir={{-0.947594,-0.225904,-0.225904}}, .pattern=0x151 },
  { .pos = {{-27802.000000,-43408.000000,61279.000000}}, .dir={{0.004975,-0.998636,-0.051974}}, .pattern=0x183 },
  { .pos = {{70969.000000,-31734.000000,10382.000000}}, .dir={{0.734056,-0.668042,-0.121987}}, .pattern=0x18c },
  { .pos = {{77642.000000,-12844.000000,-8764.000000}}, .dir={{0.981566,-0.188915,-0.028963}}, .pattern=0x199 },
  { .pos = {{79166.000000,-12197.000000,28124.000000}}, .dir={{0.993057,-0.099980,-0.061984}}, .pattern=0x1aa },
  { .pos = {{80537.000000,-24730.000000,53440.000000}}, .dir={{0.947594,-0.225904,-0.225904}}, .pattern=0x1b5 },
  { .pos = {{-28909.000000,43724.000000,57823.000000}}, .dir={{-0.004975,0.999980,0.003998}}, .pattern=0x1c0 },
  { .pos = {{-78119.000000,29616.000000,53275.000000}}, .dir={{-0.871752,0.428856,-0.236921}}, .pattern=0x1cf },
  { .pos = {{72085.000000,30581.000000,46.000000}}, .dir={{0.816019,0.577024,-0.033998}}, .pattern=0x1d6 },
  { .pos = {{66860.000000,37604.000000,29608.000000}}, .dir={{0.526908,0.847875,-0.058962}}, .pattern=0x1e9 },
  { .pos = {{78145.000000,29213.000000,52728.000000}}, .dir={{0.871752,0.428856,-0.236921}}, .pattern=0x1f3 },
  { .pos = {{29098.000000,43572.000000,57637.000000}}, .dir={{0.004975,0.999980,0.003998}}, .pattern=0x1fc },
  { .pos = {{-66825.000000,37894.000000,30136.000000}}, .dir={{-0.526908,0.847875,-0.058962}}, .pattern=0x230 },
  { .pos = {{-72217.000000,30765.000000,462.000000}}, .dir={{-0.816019,0.577024,-0.033998}}, .pattern=0x252 },
  { .pos = {{-41038.000000,43365.000000,23723.000000}}, .dir={{-0.041995,0.999110,-0.003998}}, .pattern=0x282 },
  { .pos = {{3.000000,43958.000000,33539.000000}}, .dir={{0.005982,0.999932,0.009980}}, .pattern=0x285 },
  { .pos = {{41065.000000,43154.000000,23442.000000}}, .dir={{0.041995,0.999110,-0.003998}}, .pattern=0x29b },
  { .pos = {{-11850.000000,25964.000000,-164021.000000}}, .dir={{-0.208077,0.144049,-0.967447}}, .pattern=0x29c },
  { .pos = {{-24139.000000,7160.000000,-160920.000000}}, .dir={{-0.421008,-0.007996,-0.907022}}, .pattern=0x2ae },
  { .pos = {{-32821.000000,-11851.000000,-153895.000000}}, .dir={{-0.493130,-0.214031,-0.843216}}, .pattern=0x2b7 },
  { .pos = {{-40456.000000,-31212.000000,-140108.000000}}, .dir={{-0.505856,-0.473871,-0.720802}}, .pattern=0x2c8 },
  { .pos = {{-15097.000000,-42169.000000,-142923.000000}}, .dir={{-0.147928,-0.689771,-0.708754}}, .pattern=0x2d1 },
  { .pos = {{14884.000000,-42172.000000,-142921.000000}}, .dir={{0.147928,-0.689771,-0.708754}}, .pattern=0x2e3 },
  { .pos = {{40417.000000,-31186.000000,-139999.000000}}, .dir={{0.505856,-0.473871,-0.720802}}, .pattern=0x2ed },
  { .pos = {{33046.000000,-11639.000000,-153922.000000}}, .dir={{0.493130,-0.214031,-0.843216}}, .pattern=0x2fa },
  { .pos = {{24183.000000,7138.000000,-161111.000000}}, .dir={{0.421008,-0.007996,-0.907022}}, .pattern=0x307 },
  { .pos = {{11832.000000,25969.000000,-164177.000000}}, .dir={{0.208077,0.144049,-0.967447}}, .pattern=0x309 },
};

static rift_led right_control_leds[] = {
{ .pos = {{0.029946,-0.008461,-0.011452 }}, .dir={{0.884067,0.388313,-0.260075 }}, .pattern=0x0 },
{ .pos = {{0.035536,-0.033164,-0.010440 }}, .dir={{0.967153,-0.024843,-0.252978 }}, .pattern=0x00 },
{ .pos = {{0.029571,-0.055917,-0.011534 }}, .dir={{0.844946,-0.443012,-0.299679 }}, .pattern=0x00 },
{ .pos = {{0.011121,-0.075512,-0.014582 }}, .dir={{0.492185,-0.802377,-0.337558 }}, .pattern=0x00 },
{ .pos = {{-0.010409,-0.082352,-0.018546 }}, .dir={{0.115115,-0.904317,-0.411046 }}, .pattern=0x00 },
{ .pos = {{-0.036538,-0.077271,-0.023069 }}, .dir={{-0.360823,-0.803908,-0.472798 }}, .pattern=0x00 },
{ .pos = {{-0.054721,-0.061603,-0.026314 }}, .dir={{-0.680250,-0.518209,-0.518381 }}, .pattern=0x00 },
{ .pos = {{-0.063736,-0.038431,-0.027881 }}, .dir={{-0.803271,-0.104034,-0.586457 }}, .pattern=0x00 },
{ .pos = {{-0.061211,-0.014784,-0.027409 }}, .dir={{-0.749591,0.330238,-0.573634 }}, .pattern=0x00 },
{ .pos = {{-0.048096,0.005200,-0.025099 }}, .dir={{-0.502059,0.647611,-0.573181 }}, .pattern=0x00 },
{ .pos = {{0.030635,-0.009328,0.005465 }}, .dir={{0.909815,0.346749,0.228037 }}, .pattern=0x00 },
{ .pos = {{0.035466,-0.033344,0.006530 }}, .dir={{0.965727,-0.047940,0.255094 }}, .pattern=0x00 },
{ .pos = {{0.029774,-0.056286,0.005371 }}, .dir={{0.852034,-0.457544,0.254345 }}, .pattern=0x00 },
{ .pos = {{0.015816,-0.073661,0.002961 }}, .dir={{0.579396,-0.790628,0.198007 }}, .pattern=0x00 },
{ .pos = {{-0.004190,-0.083799,-0.000457 }}, .dir={{0.210284,-0.970564,0.117414 }}, .pattern=0x00 },
{ .pos = {{-0.026027,-0.084654,-0.004290 }}, .dir={{-0.215699,-0.973665,0.073824 }}, .pattern=0x00 },
{ .pos = {{-0.047724,-0.075500,-0.008175 }}, .dir={{-0.612699,-0.790017,0.021760 }}, .pattern=0x00 },
{ .pos = {{-0.062251,-0.059548,-0.010892 }}, .dir={{-0.873529,-0.486161,-0.024384 }}, .pattern=0x00 },
{ .pos = {{-0.069615,-0.036909,-0.012056 }}, .dir={{-0.995685,-0.061201,-0.069748 }}, .pattern=0x00 },
{ .pos = {{-0.066493,-0.013106,-0.011501 }}, .dir={{-0.926055,0.370909,-0.069637 }}, .pattern=0x00 },
{ .pos = {{-0.055226,0.005148,-0.009622 }}, .dir={{-0.696882,0.698339,-0.163337 }}, .pattern=0x00 },
{ .pos = {{-0.039776,0.011819,-0.013788 }}, .dir={{0.284579,0.944923,0.161664 }}, .pattern=0x00 },
{ .pos = {{-0.005263,0.001549,-0.029259 }}, .dir={{0.008358,0.796987,-0.603938 }}, .pattern=0x00 },
{ .pos = {{0.017511,-0.001385,-0.023864 }}, .dir={{0.563180,0.669812,-0.483922 }}, .pattern=0x00 },
};

static rift_led left_control_leds[] = {
{ .pos = {{ -0.029829,-0.008241,-0.011167 }}, .dir ={{-0.868435,0.426789,-0.252331 }}, .pattern=0x00 },
{ .pos = {{ -0.035554,-0.031966,-0.010456 }}, .dir ={{-0.974995,-0.004233,-0.222187 }}, .pattern=0x00 },
{ .pos = {{ -0.029983,-0.055260,-0.011469 }}, .dir ={{-0.872345,-0.433877,-0.225311 }}, .pattern=0x00 },
{ .pos = {{ -0.012350,-0.074774,-0.014405 }}, .dir ={{-0.550523,-0.783165,-0.289098 }}, .pattern=0x00 },
{ .pos = {{ 0.010986,-0.082438,-0.018573 }}, .dir ={{-0.113685,-0.920719,-0.373300 }}, .pattern=0x00 },
{ .pos = {{ 0.035463,-0.077780,-0.022766 }}, .dir ={{0.321003,-0.822476,-0.469565 }}, .pattern=0x00 },
{ .pos = {{ 0.055485,-0.060507,-0.026353 }}, .dir ={{0.671715,-0.512871,-0.534567 }}, .pattern=0x00 },
{ .pos = {{ 0.063864,-0.036292,-0.027787 }}, .dir ={{0.830456,-0.074589,-0.552069 }}, .pattern=0x00 },
{ .pos = {{ 0.060949,-0.014478,-0.027331 }}, .dir ={{0.771918,0.326510,-0.545466 }}, .pattern=0x00 },
{ .pos = {{ 0.048540,0.004624,-0.025087 }}, .dir ={{0.539162,0.671628,-0.508154 }}, .pattern=0x00 },
{ .pos = {{ -0.030811,-0.009584,0.005300 }}, .dir ={{-0.876521,0.425520,0.225041 }}, .pattern=0x00 },
{ .pos = {{ -0.035589,-0.032112,0.006395 }}, .dir ={{-0.968514,-0.012193,0.248660 }}, .pattern=0x00 },
{ .pos = {{ -0.030432,-0.055102,0.005463 }}, .dir ={{-0.870318,-0.441839,0.217545 }}, .pattern=0x00 },
{ .pos = {{ -0.015977,-0.073655,0.002923 }}, .dir ={{-0.599825,-0.781416,0.172044 }}, .pattern=0x00 },
{ .pos = {{ 0.004668,-0.083978,-0.000647 }}, .dir ={{-0.218195,-0.969594,0.110808 }}, .pattern=0x00 },
{ .pos = {{ 0.027130,-0.084546,-0.004713 }}, .dir ={{0.196325,-0.980135,0.028128 }}, .pattern=0x00 },
{ .pos = {{ 0.047978,-0.075373,-0.008092 }}, .dir ={{0.589146,-0.807459,-0.030300 }}, .pattern=0x00 },
{ .pos = {{ 0.062869,-0.058568,-0.010919 }}, .dir ={{0.860962,-0.500010,-0.093454 }}, .pattern=0x00 },
{ .pos = {{ 0.069687,-0.035195,-0.012318 }}, .dir ={{0.994294,-0.054871,-0.091480 }}, .pattern=0x00 },
{ .pos = {{ 0.066363,-0.013170,-0.011726 }}, .dir ={{0.927925,0.362530,-0.086761 }}, .pattern=0x00 },
{ .pos = {{ 0.054643,0.005475,-0.009469 }}, .dir ={{0.696018,0.715006,-0.065769 }}, .pattern=0x00 },
{ .pos = {{ 0.040035,0.011924,-0.013663 }}, .dir ={{-0.199193,0.957329,0.209387 }}, .pattern=0x00 },
{ .pos = {{ 0.005085,0.001334,-0.029218 }}, .dir ={{0.033090,0.844565,-0.534430 }}, .pattern=0x00 },
{ .pos = {{ -0.017722,-0.001743,-0.023817 }}, .dir ={{-0.465796,0.777332,-0.422836 }}, .pattern=0x00 },
};

struct {
    rift_led *points;
    int num_points;
} all_test_leds[3] =
{ 
    { hmd_leds, sizeof(hmd_leds) / sizeof(hmd_leds[0]) },
    { right_control_leds, sizeof(right_control_leds) / sizeof(right_control_leds[0]) },
    { left_control_leds, sizeof(left_control_leds) / sizeof(left_control_leds[0]) },
};

void
rift_leds_init (rift_leds *leds, uint8_t id)
{
        leds->points = all_test_leds[id].points;
        leds->num_points = all_test_leds[id].num_points;

        if (id == 0) {
            /* Convert HMD to metres */
            for (int i = 0; i < leds->num_points; i++) {
                ovec3f_multiply_scalar (&leds->points[i].pos, 1.0/1000000.0, &leds->points[i].pos);
            }
        };
}

static rift_led test_leds_dk2[] = {
  { .pos = {{-0.027187,-0.048203,-0.022977}}, .dir={{-0.045047,-0.998533,0.030031}}, .pattern=0x1 },
  { .pos = {{-0.055767,-0.046276,-0.015323}}, .dir={{-0.070019,-0.996931,0.035009}}, .pattern=0x6 },
  { .pos = {{-0.038214,-0.041901,0.011830}}, .dir={{-0.026287,-0.741042,0.670944}}, .pattern=0x1a },
  { .pos = {{-0.057028,-0.019778,0.016765}}, .dir={{0.000000,0.000000,1.000000}}, .pattern=0x1d },
  { .pos = {{-0.078813,-0.035872,0.010891}}, .dir={{-0.606068,-0.577267,0.547214}}, .pattern=0x28 },
  { .pos = {{-0.087806,-0.027853,-0.015035}}, .dir={{-0.995792,-0.085175,0.033819}}, .pattern=0x2f },
  { .pos = {{-0.075552,-0.045359,-0.044113}}, .dir={{-0.224293,-0.974317,0.020001}}, .pattern=0x33 },
  { .pos = {{-0.089385,-0.021788,-0.049170}}, .dir={{-0.998275,-0.058554,0.004284}}, .pattern=0x4b },
  { .pos = {{-0.088956,-0.000023,-0.016018}}, .dir={{-0.999525,0.000000,0.030819}}, .pattern=0x4c },
  { .pos = {{-0.089010,0.025243,-0.049260}}, .dir={{-0.995917,0.090196,0.003758}}, .pattern=0x57 },
  { .pos = {{-0.075656,0.046310,-0.043698}}, .dir={{-0.273024,0.961847,0.017534}}, .pattern=0x62 },
  { .pos = {{-0.087626,0.027535,-0.015134}}, .dir={{-0.995556,0.088383,0.032518}}, .pattern=0x65 },
  { .pos = {{-0.084472,0.000287,0.010791}}, .dir={{-0.823092,0.000000,0.567908}}, .pattern=0x79 },
  { .pos = {{-0.078499,0.037428,0.010719}}, .dir={{-0.605237,0.576476,0.548965}}, .pattern=0x7e },
  { .pos = {{-0.056654,0.020098,0.015680}}, .dir={{0.000000,0.011828,0.999930}}, .pattern=0x90 },
  { .pos = {{-0.055997,0.047439,-0.014143}}, .dir={{-0.070008,0.996777,0.039171}}, .pattern=0xa4 },
  { .pos = {{-0.028992,0.049460,-0.022809}}, .dir={{-0.037150,0.998769,0.032864}}, .pattern=0x114 },
  { .pos = {{-0.028722,0.043657,0.011137}}, .dir={{-0.011263,0.802196,0.596954}}, .pattern=0x151 },
  { .pos = {{-0.031257,0.000151,0.018179}}, .dir={{0.000000,0.000000,1.000000}}, .pattern=0x183 },
  { .pos = {{-0.000010,-0.042336,0.012723}}, .dir={{0.000000,-0.740053,0.672548}}, .pattern=0x18c },
  { .pos = {{0.000101,-0.009701,0.018278}}, .dir={{0.000000,0.000000,1.000000}}, .pattern=0x199 },
  { .pos = {{0.031497,-0.000029,0.017955}}, .dir={{0.000000,0.000000,1.000000}}, .pattern=0x1aa },
  { .pos = {{0.028893,0.043349,0.011158}}, .dir={{0.009994,0.794531,0.607141}}, .pattern=0x1b5 },
  { .pos = {{0.028483,0.049347,-0.022692}}, .dir={{0.037150,0.998769,0.032864}}, .pattern=0x1c0 },
  { .pos = {{0.055788,0.047092,-0.014844}}, .dir={{0.070008,0.996777,0.039171}}, .pattern=0x1cf },
  { .pos = {{0.056839,0.019906,0.015700}}, .dir={{0.000000,0.011828,0.999930}}, .pattern=0x1d6 },
  { .pos = {{0.078775,0.036897,0.010736}}, .dir={{0.605237,0.576476,0.548965}}, .pattern=0x1e9 },
  { .pos = {{0.084522,-0.000018,0.010783}}, .dir={{0.822702,0.000000,0.568473}}, .pattern=0x1f3 },
  { .pos = {{0.087795,0.027701,-0.014959}}, .dir={{0.995556,0.088383,0.032518}}, .pattern=0x1fc },
  { .pos = {{0.075479,0.046068,-0.043964}}, .dir={{0.273024,0.961847,0.017534}}, .pattern=0x230 },
  { .pos = {{0.088957,0.025337,-0.049102}}, .dir={{0.995917,0.090196,0.003758}}, .pattern=0x252 },
  { .pos = {{0.088915,0.000236,-0.015902}}, .dir={{0.999525,0.000000,0.030819}}, .pattern=0x282 },
  { .pos = {{0.089037,-0.021693,-0.049226}}, .dir={{0.998275,-0.058554,0.004284}}, .pattern=0x285 },
  { .pos = {{0.075746,-0.045355,-0.043364}}, .dir={{0.224293,-0.974317,0.020001}}, .pattern=0x29b },
  { .pos = {{0.087541,-0.027466,-0.015040}}, .dir={{0.995792,-0.085175,0.033819}}, .pattern=0x29c },
  { .pos = {{0.079032,-0.036072,0.010773}}, .dir={{0.671714,-0.425942,0.606113}}, .pattern=0x2ae },
  { .pos = {{0.057046,-0.019913,0.016734}}, .dir={{0.000000,0.000000,1.000000}}, .pattern=0x2b7 },
  { .pos = {{0.038050,-0.042038,0.011762}}, .dir={{0.026263,-0.741606,0.670322}}, .pattern=0x2c8 },
  { .pos = {{0.055757,-0.046356,-0.014778}}, .dir={{0.070019,-0.996931,0.035009}}, .pattern=0x2d1 },
  { .pos = {{0.027246,-0.048235,-0.023051}}, .dir={{0.045047,-0.998533,0.030031}}, .pattern=0x2e3 },
};

void
rift_leds_init_dk2  (rift_leds *leds, uint8_t num_points)
{
	(void)(num_points);
        leds->points = test_leds_dk2;
        leds->num_points = sizeof (test_leds_dk2) / sizeof (test_leds_dk2[0]);
}

void
rift_leds_dump (rift_leds *leds, const char *desc)
{
        int i;
        printf ("LED model: %s\n", desc);
        for (i = 0; i < leds->num_points; i++) {
                rift_led *p = leds->points + i;
                printf ("%f;%f;%f;%f;%f;%f;255;255;0;1.0\n",
                    p->pos.x, p->pos.y, p->pos.z,
                    p->dir.x, p->dir.y, p->dir.z);
        }
}

void
rift_leds_clear (rift_leds *leds)
{
        //free (leds->points);
        leds->points = NULL;
}

/* Dummy OpenHMD functions */
void* ohmd_allocfn(ohmd_context* ctx, const char* e_msg, size_t size)
{
    (void)(ctx);
    (void)(e_msg);

    return malloc (size);
}
