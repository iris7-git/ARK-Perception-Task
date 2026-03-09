/* Include files */

#include "flightControlSystem_sfun.h"
#include "c1_flightControlSystem.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c1_emlrtMCI = { 82, /* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtMCInfo c1_b_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "D:\\Matlab R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c1_c_emlrtMCI = { 90,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "D:\\Matlab R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtMCInfo c1_d_emlrtMCI = { 198,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "D:\\Matlab R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtMCInfo c1_e_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c1_f_emlrtMCI = { 48,/* lineNo */
  15,                                  /* colNo */
  "mean",                              /* fName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"/* pName */
};

static emlrtMCInfo c1_g_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtRSInfo c1_emlrtRSI = { 21, /* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 26,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_c_emlrtRSI = { 31,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_d_emlrtRSI = { 32,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_e_emlrtRSI = { 61,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_f_emlrtRSI = { 62,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_g_emlrtRSI = { 63,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_h_emlrtRSI = { 67,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_i_emlrtRSI = { 68,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_j_emlrtRSI = { 69,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_k_emlrtRSI = { 72,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_l_emlrtRSI = { 73,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_m_emlrtRSI = { 74,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_n_emlrtRSI = { 78,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_o_emlrtRSI = { 79,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_p_emlrtRSI = { 80,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_q_emlrtRSI = { 96,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2798"          /* pathName */
};

static emlrtRSInfo c1_r_emlrtRSI = { 87,/* lineNo */
  "imerode",                           /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\images\\images\\imerode.m"/* pathName */
};

static emlrtRSInfo c1_s_emlrtRSI = { 17,/* lineNo */
  "morphop",                           /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\images\\images\\+images\\+internal\\morphop.m"/* pathName */
};

static emlrtRSInfo c1_t_emlrtRSI = { 22,/* lineNo */
  "morphop",                           /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphop.m"/* pathName */
};

static emlrtRSInfo c1_u_emlrtRSI = { 487,/* lineNo */
  "morphopConstantFoldingImpl",        /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphopConstantFoldingImpl.m"/* pathName */
};

static emlrtRSInfo c1_v_emlrtRSI = { 709,/* lineNo */
  "morphopConstantFoldingImpl",        /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\morphopConstantFoldingImpl.m"/* pathName */
};

static emlrtRSInfo c1_w_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c1_x_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo c1_y_emlrtRSI = { 35,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_ab_emlrtRSI = { 132,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_bb_emlrtRSI = { 249,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_cb_emlrtRSI = { 248,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_db_emlrtRSI = { 247,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_eb_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c1_fb_emlrtRSI = { 15,/* lineNo */
  "min",                               /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"/* pathName */
};

static emlrtRSInfo c1_gb_emlrtRSI = { 66,/* lineNo */
  "minOrMax",                          /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c1_hb_emlrtRSI = { 112,/* lineNo */
  "minOrMax",                          /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c1_ib_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRTEInfo c1_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_b_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_c_emlrtRTEI = { 61,/* lineNo */
  10,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2798"          /* pName */
};

static emlrtRTEInfo c1_d_emlrtRTEI = { 61,/* lineNo */
  17,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2798"          /* pName */
};

static emlrtRTEInfo c1_e_emlrtRTEI = { 189,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_f_emlrtRTEI = { 191,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_g_emlrtRTEI = { 247,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_h_emlrtRTEI = { 248,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static char_T c1_cv[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm',
  'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

/* Function Declarations */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_update_jit_animation_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st);
static void c1_imerode(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_A[19200], boolean_T c1_b_B[19200]);
static void c1_eml_find(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_x[19200], int32_T c1_i_data[], int32_T c1_i_size[1], int32_T
  c1_j_data[], int32_T c1_j_size[1]);
static void c1_indexShapeCheck(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void c1_b_eml_find(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_x[4800], int32_T c1_i_data[], int32_T c1_i_size[1], int32_T
  c1_j_data[], int32_T c1_j_size[1]);
static real_T c1_mean(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, real_T c1_x_data[], int32_T
                      c1_x_size[1]);
static real_T c1_sumColumnB(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_x_data[], int32_T c1_vlen);
static real_T c1_sumColumnB4(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_x_data[], int32_T c1_vstart);
static real_T c1_b_sumColumnB(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_x_data[], int32_T c1_vlen, int32_T c1_vstart);
static void c1_c_eml_find(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_x[4960], int32_T c1_i_data[], int32_T c1_i_size[1], int32_T
  c1_j_data[], int32_T c1_j_size[1]);
static real_T c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c1_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_doneDoubleBufferReInit = false;
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  static const int32_T c1_postfixPredicateTree[5] = { 0, 1, -3, 2, -3 };

  static const int32_T c1_condTxtEndIdx[3] = { 1033, 1053, 1066 };

  static const int32_T c1_condTxtStartIdx[3] = { 1024, 1039, 1058 };

  static const uint32_T c1_decisionTxtEndIdx = 0U;
  static const uint32_T c1_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c1_JITStateAnimation[0],
                        &chartInstance->c1_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c1_covrtInstance, 1U, 0U, 1U,
    13U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 9U, 0U,
                  0U, 0U, 0U, 0U, 3U, 1U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U,
                     "c1_flightControlSystem", 0, -1, 4001);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 443, 459, 810,
                    907, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 1U, 810, 824, 879,
                    907, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 2U, 1020, 1066,
                    1832, 2605, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 3U, 1832, 1847,
                    2080, 2605, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 4U, 2080, 2099,
                    2280, 2605, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 5U, 2280, 2300,
                    2442, 2605, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 6U, 3110, 3129,
                    3531, 3741, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 7U, 3531, 3545,
                    3602, 3741, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 8U, 3602, 3620,
                    3674, 3741, false);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 1023, 1066,
                      3U, 0U, &c1_condTxtStartIdx[0], &c1_condTxtEndIdx[0], 5U,
                      &c1_postfixPredicateTree[0], false);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 446,
    459, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 1U, 813,
    824, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 2U, 1024,
    1033, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 3U, 1039,
    1053, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 4U, 1835,
    1847, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 5U, 2087,
    2099, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 6U, 2287,
    2300, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 7U, 3113,
    3129, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 8U, 3534,
    3545, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 9U, 3609,
    3620, -1, 4U);
}

static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  static char_T c1_b_cv[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  static char_T c1_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  static char_T c1_cv2[4] = { 's', 'q', 'r', 't' };

  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_b_tCols_data[4800];
  real_T c1_IQ;
  real_T c1_X_raw;
  real_T c1_Y_raw;
  real_T c1_a;
  real_T c1_absY;
  real_T c1_b_X;
  real_T c1_b_Y;
  real_T c1_b_a;
  real_T c1_c;
  real_T c1_c_a;
  real_T c1_c_c;
  real_T c1_c_x;
  real_T c1_dCol;
  real_T c1_dRow;
  real_T c1_d_a;
  real_T c1_d_c;
  real_T c1_d_x;
  real_T c1_e_a;
  real_T c1_e_x;
  real_T c1_ex;
  real_T c1_f_x;
  real_T c1_farRed;
  real_T c1_g_a;
  real_T c1_g_x;
  real_T c1_h_a;
  real_T c1_i_a;
  real_T c1_j_a;
  real_T c1_k_a;
  real_T c1_l_a;
  real_T c1_m_a;
  real_T c1_magnitude;
  real_T c1_midRed;
  real_T c1_minval;
  real_T c1_n_a;
  real_T c1_nearRed;
  real_T c1_o_a;
  real_T c1_p_a;
  real_T c1_perimPx;
  real_T c1_speedScale;
  real_T c1_targetCol;
  real_T c1_targetRow;
  real_T c1_totalRed;
  int32_T c1_c_ii_data[4960];
  int32_T c1_c_jj_data[4960];
  int32_T c1_b_ii_data[4800];
  int32_T c1_b_jj_data[4800];
  int32_T c1_allC_size[1];
  int32_T c1_allRows_size[1];
  int32_T c1_b_ii_size[1];
  int32_T c1_b_jj_size[1];
  int32_T c1_b_tCols_size[1];
  int32_T c1_b_tRows_size[1];
  int32_T c1_c_ii_size[1];
  int32_T c1_c_jj_size[1];
  int32_T c1_ii_size[1];
  int32_T c1_jj_size[1];
  int32_T c1_tCols_size[1];
  int32_T c1_tRows_size[1];
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_c;
  int32_T c1_b_ix;
  int32_T c1_b_k;
  int32_T c1_b_last;
  int32_T c1_b_loop_ub;
  int32_T c1_b_nz;
  int32_T c1_b_xoffset;
  int32_T c1_c_ix;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_c_nz;
  int32_T c1_c_xoffset;
  int32_T c1_d_b;
  int32_T c1_d_ix;
  int32_T c1_d_k;
  int32_T c1_d_loop_ub;
  int32_T c1_d_nz;
  int32_T c1_d_xoffset;
  int32_T c1_e_b;
  int32_T c1_e_ix;
  int32_T c1_e_k;
  int32_T c1_e_loop_ub;
  int32_T c1_e_nz;
  int32_T c1_e_xoffset;
  int32_T c1_f_a;
  int32_T c1_f_b;
  int32_T c1_f_k;
  int32_T c1_f_loop_ub;
  int32_T c1_g_loop_ub;
  int32_T c1_h_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i_loop_ub;
  int32_T c1_ix;
  int32_T c1_j_loop_ub;
  int32_T c1_k;
  int32_T c1_k_loop_ub;
  int32_T c1_last;
  int32_T c1_loop_ub;
  int32_T c1_nx;
  int32_T c1_nz;
  int32_T c1_xoffset;
  boolean_T c1_erodedMask[19200];
  boolean_T c1_redMask[19200];
  boolean_T c1_b_x[4960];
  boolean_T c1_midMask[4960];
  boolean_T c1_nearMask[4960];
  boolean_T c1_farMask[4800];
  boolean_T c1_x[4800];
  boolean_T c1_b_p;
  boolean_T c1_c_b;
  boolean_T c1_lineGone;
  boolean_T c1_p;
  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  if (covrtIsSigCovEnabledFcn(chartInstance->c1_covrtInstance, 2U) != 0U) {
    for (c1_i = 0; c1_i < 19200; c1_i++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c1_covrtInstance, 2U,
        (real_T)(*chartInstance->c1_B)[c1_i]);
    }
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c1_covrtInstance, 1U) != 0U) {
    for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c1_covrtInstance, 1U,
        (real_T)(*chartInstance->c1_G)[c1_i1]);
    }
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c1_covrtInstance, 0U) != 0U) {
    for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c1_covrtInstance, 0U,
        (real_T)(*chartInstance->c1_R)[c1_i2]);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  chartInstance->c1_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 4U, 0, 0);
  for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
    chartInstance->c1_Rd[c1_i3] = (real_T)(*chartInstance->c1_R)[c1_i3];
  }

  for (c1_i4 = 0; c1_i4 < 19200; c1_i4++) {
    chartInstance->c1_Gd[c1_i4] = (real_T)(*chartInstance->c1_G)[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 19200; c1_i5++) {
    chartInstance->c1_Bd[c1_i5] = (real_T)(*chartInstance->c1_B)[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 19200; c1_i6++) {
    c1_redMask[c1_i6] = (chartInstance->c1_Rd[c1_i6] > 110.0);
  }

  for (c1_i7 = 0; c1_i7 < 19200; c1_i7++) {
    c1_erodedMask[c1_i7] = (chartInstance->c1_Rd[c1_i7] - chartInstance->
      c1_Gd[c1_i7] > 40.0);
  }

  for (c1_i8 = 0; c1_i8 < 19200; c1_i8++) {
    c1_redMask[c1_i8] = (c1_redMask[c1_i8] && c1_erodedMask[c1_i8]);
  }

  for (c1_i9 = 0; c1_i9 < 19200; c1_i9++) {
    c1_erodedMask[c1_i9] = (chartInstance->c1_Rd[c1_i9] - chartInstance->
      c1_Bd[c1_i9] > 40.0);
  }

  for (c1_i10 = 0; c1_i10 < 19200; c1_i10++) {
    c1_redMask[c1_i10] = (c1_redMask[c1_i10] && c1_erodedMask[c1_i10]);
  }

  for (c1_i11 = 0; c1_i11 < 19200; c1_i11++) {
    c1_erodedMask[c1_i11] = c1_redMask[c1_i11];
  }

  c1_nz = (int32_T)c1_erodedMask[0];
  for (c1_k = 0; c1_k < 19199; c1_k++) {
    c1_xoffset = c1_k;
    c1_ix = c1_xoffset;
    c1_b = (int32_T)c1_erodedMask[c1_ix + 1];
    c1_nz += (c1_b != 0);
  }

  c1_totalRed = (real_T)c1_nz;
  if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance,
        4U, 0U, 0U, c1_totalRed, 20.0, -1, 2U, c1_totalRed < 20.0))) {
    c1_b_X = 0.0;
    c1_b_Y = 0.3;
  } else {
    c1_b_st.site = &c1_emlrtRSI;
    c1_imerode(chartInstance, c1_redMask, c1_erodedMask);
    for (c1_i12 = 0; c1_i12 < 19200; c1_i12++) {
      c1_erodedMask[c1_i12] = !c1_erodedMask[c1_i12];
    }

    for (c1_i13 = 0; c1_i13 < 19200; c1_i13++) {
      c1_erodedMask[c1_i13] = (c1_redMask[c1_i13] && c1_erodedMask[c1_i13]);
    }

    c1_b_nz = (int32_T)c1_erodedMask[0];
    for (c1_b_k = 0; c1_b_k < 19199; c1_b_k++) {
      c1_b_xoffset = c1_b_k;
      c1_b_ix = c1_b_xoffset;
      c1_b_b = (int32_T)c1_erodedMask[c1_b_ix + 1];
      c1_b_nz += (c1_b_b != 0);
    }

    c1_perimPx = (real_T)c1_b_nz;
    if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 1,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c1_covrtInstance, 4U, 0U, 1U, c1_perimPx,
                        0.0, -1, 4U, c1_perimPx > 0.0))) {
      c1_b_st.site = &c1_b_emlrtRSI;
      c1_a = c1_perimPx;
      c1_c_st.site = &c1_w_emlrtRSI;
      c1_b_a = c1_a;
      c1_d_st.site = &c1_x_emlrtRSI;
      c1_c_a = c1_b_a;
      c1_d_a = c1_c_a;
      c1_e_a = c1_d_a;
      c1_c = c1_e_a * c1_e_a;
      c1_IQ = 12.566370614359172 * c1_totalRed / c1_c;
    } else {
      c1_IQ = 0.0;
    }

    c1_b_st.site = &c1_c_emlrtRSI;
    c1_c_st.site = &c1_y_emlrtRSI;
    c1_eml_find(chartInstance, c1_redMask, chartInstance->c1_ii_data, c1_ii_size,
                chartInstance->c1_jj_data, c1_jj_size);
    c1_allRows_size[0] = c1_ii_size[0];
    c1_loop_ub = c1_ii_size[0] - 1;
    for (c1_i14 = 0; c1_i14 <= c1_loop_ub; c1_i14++) {
      chartInstance->c1_allRows_data[c1_i14] = (real_T)chartInstance->
        c1_ii_data[c1_i14];
    }

    c1_b_st.site = &c1_d_emlrtRSI;
    c1_c_st.site = &c1_fb_emlrtRSI;
    c1_d_st.site = &c1_gb_emlrtRSI;
    c1_e_st.site = &c1_hb_emlrtRSI;
    if ((c1_allRows_size[0] == 1) || (c1_allRows_size[0] != 1)) {
      c1_c_b = true;
    } else {
      c1_c_b = false;
    }

    if (!c1_c_b) {
      c1_y = NULL;
      sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv, 10, 0U, 1, 0U, 2, 1, 36),
                    false);
      c1_c_y = NULL;
      sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv, 10, 0U, 1, 0U, 2, 1, 36),
                    false);
      sf_mex_call(&c1_e_st, &c1_c_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                  sf_mex_call(&c1_e_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c1_e_st, NULL, "message", 1U, 1U, 14, c1_c_y)));
    }

    if (c1_allRows_size[0] < 1) {
      c1_b_y = NULL;
      sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 39),
                    false);
      c1_d_y = NULL;
      sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1, 0U, 2, 1, 39),
                    false);
      sf_mex_call(&c1_e_st, &c1_d_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                  sf_mex_call(&c1_e_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c1_e_st, NULL, "message", 1U, 1U, 14, c1_d_y)));
    }

    c1_last = c1_allRows_size[0] - 1;
    c1_f_a = c1_last;
    c1_b_c = (uint16_T)c1_f_a + 1;
    c1_nx = c1_b_c;
    if (c1_nx <= 2) {
      if (c1_nx == 1) {
        c1_minval = chartInstance->c1_allRows_data[0];
      } else if (chartInstance->c1_allRows_data[0] >
                 chartInstance->c1_allRows_data[c1_last]) {
        c1_minval = chartInstance->c1_allRows_data[c1_last];
      } else {
        c1_minval = chartInstance->c1_allRows_data[0];
      }
    } else {
      c1_b_last = c1_last + 1;
      c1_ex = chartInstance->c1_allRows_data[0];
      for (c1_c_k = 2; c1_c_k <= c1_b_last; c1_c_k++) {
        if (c1_ex > chartInstance->c1_allRows_data[c1_c_k - 1]) {
          c1_ex = chartInstance->c1_allRows_data[c1_c_k - 1];
        }
      }

      c1_minval = c1_ex;
    }

    c1_lineGone = (c1_minval > 20.0);
    if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 0,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 4U, 0U, 2U, c1_IQ,
                          0.65, -1, 4U, c1_IQ > 0.65)) && covrtEmlCondEval
        (chartInstance->c1_covrtInstance, 4U, 0, 1, covrtRelationalopUpdateFcn
         (chartInstance->c1_covrtInstance, 4U, 0U, 3U, c1_totalRed, 400.0, -1,
          4U, c1_totalRed > 400.0)) && covrtEmlCondEval
        (chartInstance->c1_covrtInstance, 4U, 0, 2, c1_lineGone)) {
      covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 0, true);
      covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 2, true);
      c1_b_X = 0.0;
      c1_b_Y = 0.0;
    } else {
      covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 0, false);
      covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 2, false);
      c1_i15 = 0;
      c1_i16 = 0;
      for (c1_i17 = 0; c1_i17 < 160; c1_i17++) {
        for (c1_i19 = 0; c1_i19 < 30; c1_i19++) {
          c1_farMask[c1_i19 + c1_i15] = c1_redMask[c1_i19 + c1_i16];
        }

        c1_i15 += 30;
        c1_i16 += 120;
      }

      c1_i18 = 0;
      c1_i20 = 0;
      for (c1_i21 = 0; c1_i21 < 160; c1_i21++) {
        for (c1_i23 = 0; c1_i23 < 31; c1_i23++) {
          c1_midMask[c1_i23 + c1_i18] = c1_redMask[(c1_i23 + c1_i20) + 44];
        }

        c1_i18 += 31;
        c1_i20 += 120;
      }

      c1_i22 = 0;
      c1_i24 = 0;
      for (c1_i25 = 0; c1_i25 < 160; c1_i25++) {
        for (c1_i27 = 0; c1_i27 < 31; c1_i27++) {
          c1_nearMask[c1_i27 + c1_i22] = c1_redMask[(c1_i27 + c1_i24) + 89];
        }

        c1_i22 += 31;
        c1_i24 += 120;
      }

      for (c1_i26 = 0; c1_i26 < 4800; c1_i26++) {
        c1_x[c1_i26] = c1_farMask[c1_i26];
      }

      c1_c_nz = (int32_T)c1_x[0];
      for (c1_d_k = 0; c1_d_k < 4799; c1_d_k++) {
        c1_c_xoffset = c1_d_k;
        c1_c_ix = c1_c_xoffset;
        c1_d_b = (int32_T)c1_x[c1_c_ix + 1];
        c1_c_nz += (c1_d_b != 0);
      }

      c1_farRed = (real_T)c1_c_nz;
      for (c1_i28 = 0; c1_i28 < 4960; c1_i28++) {
        c1_b_x[c1_i28] = c1_midMask[c1_i28];
      }

      c1_d_nz = (int32_T)c1_b_x[0];
      for (c1_e_k = 0; c1_e_k < 4959; c1_e_k++) {
        c1_d_xoffset = c1_e_k;
        c1_d_ix = c1_d_xoffset;
        c1_e_b = (int32_T)c1_b_x[c1_d_ix + 1];
        c1_d_nz += (c1_e_b != 0);
      }

      c1_midRed = (real_T)c1_d_nz;
      for (c1_i29 = 0; c1_i29 < 4960; c1_i29++) {
        c1_b_x[c1_i29] = c1_nearMask[c1_i29];
      }

      c1_e_nz = (int32_T)c1_b_x[0];
      for (c1_f_k = 0; c1_f_k < 4959; c1_f_k++) {
        c1_e_xoffset = c1_f_k;
        c1_e_ix = c1_e_xoffset;
        c1_f_b = (int32_T)c1_b_x[c1_e_ix + 1];
        c1_e_nz += (c1_f_b != 0);
      }

      c1_nearRed = (real_T)c1_e_nz;
      if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 3,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 4U, 0U, 4U, c1_farRed,
                          10.0, -1, 5U, c1_farRed >= 10.0))) {
        c1_b_st.site = &c1_e_emlrtRSI;
        c1_c_st.site = &c1_y_emlrtRSI;
        c1_b_eml_find(chartInstance, c1_farMask, c1_b_ii_data, c1_b_ii_size,
                      c1_b_jj_data, c1_b_jj_size);
        c1_tRows_size[0] = c1_b_ii_size[0];
        c1_b_loop_ub = c1_b_ii_size[0] - 1;
        for (c1_i30 = 0; c1_i30 <= c1_b_loop_ub; c1_i30++) {
          chartInstance->c1_b_tRows_data[c1_i30] = (real_T)c1_b_ii_data[c1_i30];
        }

        c1_tCols_size[0] = c1_b_jj_size[0];
        c1_f_loop_ub = c1_b_jj_size[0] - 1;
        for (c1_i34 = 0; c1_i34 <= c1_f_loop_ub; c1_i34++) {
          c1_b_tCols_data[c1_i34] = (real_T)c1_b_jj_data[c1_i34];
        }

        c1_b_tRows_size[0] = c1_tRows_size[0];
        c1_j_loop_ub = c1_tRows_size[0] - 1;
        for (c1_i38 = 0; c1_i38 <= c1_j_loop_ub; c1_i38++) {
          chartInstance->c1_tRows_data[c1_i38] = chartInstance->
            c1_b_tRows_data[c1_i38];
        }

        c1_b_tCols_size[0] = c1_tCols_size[0];
        c1_k_loop_ub = c1_tCols_size[0] - 1;
        for (c1_i39 = 0; c1_i39 <= c1_k_loop_ub; c1_i39++) {
          chartInstance->c1_tCols_data[c1_i39] = c1_b_tCols_data[c1_i39];
        }

        c1_b_st.site = &c1_f_emlrtRSI;
        c1_targetCol = c1_mean(chartInstance, &c1_b_st,
          chartInstance->c1_tCols_data, c1_b_tCols_size);
        c1_b_st.site = &c1_g_emlrtRSI;
        c1_targetRow = c1_mean(chartInstance, &c1_b_st,
          chartInstance->c1_tRows_data, c1_b_tRows_size);
      } else if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 4,
                  covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance, 4U,
        0U, 5U, c1_midRed, 10.0, -1, 5U, c1_midRed >= 10.0))) {
        c1_b_st.site = &c1_h_emlrtRSI;
        c1_c_st.site = &c1_y_emlrtRSI;
        c1_c_eml_find(chartInstance, c1_midMask, c1_c_ii_data, c1_c_ii_size,
                      c1_c_jj_data, c1_c_jj_size);
        c1_b_tRows_size[0] = c1_c_ii_size[0];
        c1_c_loop_ub = c1_c_ii_size[0] - 1;
        for (c1_i31 = 0; c1_i31 <= c1_c_loop_ub; c1_i31++) {
          chartInstance->c1_tRows_data[c1_i31] = (real_T)c1_c_ii_data[c1_i31];
        }

        c1_b_tCols_size[0] = c1_c_jj_size[0];
        c1_g_loop_ub = c1_c_jj_size[0] - 1;
        for (c1_i35 = 0; c1_i35 <= c1_g_loop_ub; c1_i35++) {
          chartInstance->c1_tCols_data[c1_i35] = (real_T)c1_c_jj_data[c1_i35];
        }

        c1_b_st.site = &c1_i_emlrtRSI;
        c1_targetCol = c1_mean(chartInstance, &c1_b_st,
          chartInstance->c1_tCols_data, c1_b_tCols_size);
        c1_b_st.site = &c1_j_emlrtRSI;
        c1_targetRow = c1_mean(chartInstance, &c1_b_st,
          chartInstance->c1_tRows_data, c1_b_tRows_size) + 44.0;
      } else if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 5,
                  covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance, 4U,
        0U, 6U, c1_nearRed, 10.0, -1, 5U, c1_nearRed >= 10.0))) {
        c1_b_st.site = &c1_k_emlrtRSI;
        c1_c_st.site = &c1_y_emlrtRSI;
        c1_c_eml_find(chartInstance, c1_nearMask, c1_c_ii_data, c1_c_ii_size,
                      c1_c_jj_data, c1_c_jj_size);
        c1_b_tRows_size[0] = c1_c_ii_size[0];
        c1_e_loop_ub = c1_c_ii_size[0] - 1;
        for (c1_i33 = 0; c1_i33 <= c1_e_loop_ub; c1_i33++) {
          chartInstance->c1_tRows_data[c1_i33] = (real_T)c1_c_ii_data[c1_i33];
        }

        c1_b_tCols_size[0] = c1_c_jj_size[0];
        c1_i_loop_ub = c1_c_jj_size[0] - 1;
        for (c1_i37 = 0; c1_i37 <= c1_i_loop_ub; c1_i37++) {
          chartInstance->c1_tCols_data[c1_i37] = (real_T)c1_c_jj_data[c1_i37];
        }

        c1_b_st.site = &c1_l_emlrtRSI;
        c1_targetCol = c1_mean(chartInstance, &c1_b_st,
          chartInstance->c1_tCols_data, c1_b_tCols_size);
        c1_b_st.site = &c1_m_emlrtRSI;
        c1_targetRow = c1_mean(chartInstance, &c1_b_st,
          chartInstance->c1_tRows_data, c1_b_tRows_size) + 89.0;
      } else {
        c1_b_st.site = &c1_n_emlrtRSI;
        c1_c_st.site = &c1_y_emlrtRSI;
        c1_eml_find(chartInstance, c1_redMask, chartInstance->c1_ii_data,
                    c1_ii_size, chartInstance->c1_jj_data, c1_jj_size);
        c1_allRows_size[0] = c1_ii_size[0];
        c1_d_loop_ub = c1_ii_size[0] - 1;
        for (c1_i32 = 0; c1_i32 <= c1_d_loop_ub; c1_i32++) {
          chartInstance->c1_allRows_data[c1_i32] = (real_T)
            chartInstance->c1_ii_data[c1_i32];
        }

        c1_allC_size[0] = c1_jj_size[0];
        c1_h_loop_ub = c1_jj_size[0] - 1;
        for (c1_i36 = 0; c1_i36 <= c1_h_loop_ub; c1_i36++) {
          chartInstance->c1_allC_data[c1_i36] = (real_T)
            chartInstance->c1_jj_data[c1_i36];
        }

        c1_b_st.site = &c1_o_emlrtRSI;
        c1_targetCol = c1_mean(chartInstance, &c1_b_st,
          chartInstance->c1_allC_data, c1_allC_size);
        c1_b_st.site = &c1_p_emlrtRSI;
        c1_targetRow = c1_mean(chartInstance, &c1_b_st,
          chartInstance->c1_allRows_data, c1_allRows_size);
      }

      c1_dRow = 120.0 - c1_targetRow;
      c1_dCol = c1_targetCol - 80.0;
      c1_b_st.site = &c1_q_emlrtRSI;
      c1_g_a = c1_dRow;
      c1_c_st.site = &c1_w_emlrtRSI;
      c1_h_a = c1_g_a;
      c1_d_st.site = &c1_x_emlrtRSI;
      c1_i_a = c1_h_a;
      c1_j_a = c1_i_a;
      c1_k_a = c1_j_a;
      c1_c_c = c1_k_a * c1_k_a;
      c1_b_st.site = &c1_q_emlrtRSI;
      c1_l_a = c1_dCol;
      c1_c_st.site = &c1_w_emlrtRSI;
      c1_m_a = c1_l_a;
      c1_d_st.site = &c1_x_emlrtRSI;
      c1_n_a = c1_m_a;
      c1_o_a = c1_n_a;
      c1_p_a = c1_o_a;
      c1_d_c = c1_p_a * c1_p_a;
      c1_b_st.site = &c1_q_emlrtRSI;
      c1_c_x = c1_c_c + c1_d_c;
      c1_magnitude = c1_c_x;
      c1_d_x = c1_magnitude;
      if (c1_d_x < 0.0) {
        c1_p = true;
      } else {
        c1_p = false;
      }

      c1_b_p = c1_p;
      if (c1_b_p) {
        c1_e_y = NULL;
        sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv1, 10, 0U, 1, 0U, 2, 1,
          30), false);
        c1_f_y = NULL;
        sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_cv1, 10, 0U, 1, 0U, 2, 1,
          30), false);
        c1_g_y = NULL;
        sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_cv2, 10, 0U, 1, 0U, 2, 1, 4),
                      false);
        sf_mex_call(&c1_b_st, &c1_g_emlrtMCI, "error", 0U, 2U, 14, c1_e_y, 14,
                    sf_mex_call(&c1_b_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c1_b_st, NULL, "message", 1U, 2U, 14, c1_f_y, 14, c1_g_y)));
      }

      c1_magnitude = muDoubleScalarSqrt(c1_magnitude);
      if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 6,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 4U, 0U, 7U,
                          c1_magnitude, 1.0E-6, -1, 2U, c1_magnitude < 1.0E-6)))
      {
        c1_b_X = 1.0;
        c1_b_Y = 0.0;
      } else {
        c1_X_raw = c1_dRow / c1_magnitude;
        c1_Y_raw = c1_dCol / c1_magnitude;
        c1_e_x = c1_Y_raw;
        c1_f_x = c1_e_x;
        c1_g_x = c1_f_x;
        c1_absY = muDoubleScalarAbs(c1_g_x);
        if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 7,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c1_covrtInstance, 4U, 0U, 8U, c1_absY,
                            0.75, -1, 4U, c1_absY > 0.75))) {
          c1_speedScale = 0.25;
        } else if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 8,
                    covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance,
                     4U, 0U, 9U, c1_absY, 0.45, -1, 4U, c1_absY > 0.45))) {
          c1_speedScale = 0.45;
        } else {
          c1_speedScale = 0.7;
        }

        c1_b_X = c1_X_raw * c1_speedScale;
        c1_b_Y = c1_Y_raw * c1_speedScale;
      }
    }
  }

  *chartInstance->c1_X = c1_b_X;
  *chartInstance->c1_Y = c1_b_Y;
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 3U, *chartInstance->c1_X);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 4U, *chartInstance->c1_Y);
}

static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_update_jit_animation_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(2, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", chartInstance->c1_X, 0, 0U, 0, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", chartInstance->c1_Y, 0, 0U, 0, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *chartInstance->c1_X = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 0)), "X");
  *chartInstance->c1_Y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 1)), "Y");
  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

static void c1_imerode(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_A[19200], boolean_T c1_b_B[19200])
{
  real_T c1_asizeT[2];
  real_T c1_nsizeT[2];
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  boolean_T c1_nhood[9];
  (void)chartInstance;
  for (c1_i = 0; c1_i < 9; c1_i++) {
    c1_nhood[c1_i] = true;
  }

  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_asizeT[c1_i1] = 120.0 + 40.0 * (real_T)c1_i1;
  }

  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_nsizeT[c1_i2] = 3.0;
  }

  erode_binary_ones33_tbb(&c1_A[0], &c1_asizeT[0], 2.0, &c1_nhood[0],
    &c1_nsizeT[0], 2.0, &c1_b_B[0]);
}

static void c1_eml_find(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_x[19200], int32_T c1_i_data[], int32_T c1_i_size[1], int32_T
  c1_j_data[], int32_T c1_j_size[1])
{
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_idx;
  int32_T c1_ii;
  int32_T c1_jj;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_exitg1;
  boolean_T c1_guard1;
  c1_idx = 0;
  c1_ii = 1;
  c1_jj = 1;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_jj <= 160)) {
    c1_guard1 = false;
    if (c1_x[(c1_ii + 120 * (c1_jj - 1)) - 1]) {
      c1_idx++;
      c1_i_data[c1_idx - 1] = c1_ii;
      c1_j_data[c1_idx - 1] = c1_jj;
      if (c1_idx >= 19200) {
        c1_exitg1 = true;
      } else {
        c1_guard1 = true;
      }
    } else {
      c1_guard1 = true;
    }

    if (c1_guard1) {
      c1_ii++;
      if (c1_ii > 120) {
        c1_ii = 1;
        c1_jj++;
      }
    }
  }

  c1_b = (c1_idx < 1);
  if (c1_b) {
    c1_i = 0;
  } else {
    c1_i = c1_idx;
  }

  c1_indexShapeCheck(chartInstance);
  c1_i_size[0] = c1_i;
  c1_b1 = (c1_idx < 1);
  if (c1_b1) {
    c1_i1 = 0;
  } else {
    c1_i1 = c1_idx;
  }

  c1_indexShapeCheck(chartInstance);
  c1_j_size[0] = c1_i1;
  c1_indexShapeCheck(chartInstance);
}

static void c1_indexShapeCheck(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_b_eml_find(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_x[4800], int32_T c1_i_data[], int32_T c1_i_size[1], int32_T
  c1_j_data[], int32_T c1_j_size[1])
{
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_idx;
  int32_T c1_ii;
  int32_T c1_jj;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_exitg1;
  boolean_T c1_guard1;
  c1_idx = 0;
  c1_ii = 1;
  c1_jj = 1;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_jj <= 160)) {
    c1_guard1 = false;
    if (c1_x[(c1_ii + 30 * (c1_jj - 1)) - 1]) {
      c1_idx++;
      c1_i_data[c1_idx - 1] = c1_ii;
      c1_j_data[c1_idx - 1] = c1_jj;
      if (c1_idx >= 4800) {
        c1_exitg1 = true;
      } else {
        c1_guard1 = true;
      }
    } else {
      c1_guard1 = true;
    }

    if (c1_guard1) {
      c1_ii++;
      if (c1_ii > 30) {
        c1_ii = 1;
        c1_jj++;
      }
    }
  }

  c1_b = (c1_idx < 1);
  if (c1_b) {
    c1_i = 0;
  } else {
    c1_i = c1_idx;
  }

  c1_indexShapeCheck(chartInstance);
  c1_i_size[0] = c1_i;
  c1_b1 = (c1_idx < 1);
  if (c1_b1) {
    c1_i1 = 0;
  } else {
    c1_i1 = c1_idx;
  }

  c1_indexShapeCheck(chartInstance);
  c1_j_size[0] = c1_i1;
  c1_indexShapeCheck(chartInstance);
}

static real_T c1_mean(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, real_T c1_x_data[], int32_T
                      c1_x_size[1])
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  real_T c1_accumulatedData;
  real_T c1_accumulatedWeights;
  real_T c1_s;
  int32_T c1_a;
  int32_T c1_b_vlen;
  int32_T c1_c_vlen;
  int32_T c1_d_vlen;
  int32_T c1_ib;
  int32_T c1_inb;
  int32_T c1_lidx;
  int32_T c1_nfb;
  int32_T c1_nleft;
  int32_T c1_vlen;
  boolean_T c1_b;
  if ((c1_x_size[0] == 1) || (c1_x_size[0] != 1)) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    sf_mex_call(c1_sp, &c1_f_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c1_sp, NULL, "message", 1U, 1U, 14, c1_c_y)));
  }

  c1_vlen = c1_x_size[0];
  c1_b_vlen = c1_vlen;
  if ((c1_x_size[0] == 0) || (c1_b_vlen == 0)) {
    c1_accumulatedData = 0.0;
  } else {
    c1_c_vlen = c1_b_vlen;
    c1_d_vlen = c1_c_vlen;
    if (c1_d_vlen < 4096) {
      c1_accumulatedData = c1_sumColumnB(chartInstance, c1_x_data, c1_d_vlen);
    } else {
      c1_a = c1_d_vlen;
      c1_nfb = (uint16_T)((uint32_T)(uint16_T)c1_a >> 12);
      c1_inb = c1_nfb << 12;
      c1_lidx = c1_inb;
      c1_nleft = c1_d_vlen - c1_inb;
      c1_s = c1_sumColumnB4(chartInstance, c1_x_data, 1);
      for (c1_ib = 2; c1_ib <= c1_nfb; c1_ib++) {
        c1_s += c1_sumColumnB4(chartInstance, c1_x_data, 1 + ((c1_ib - 1) << 12));
      }

      if (c1_nleft > 0) {
        c1_s += c1_b_sumColumnB(chartInstance, c1_x_data, c1_nleft, c1_lidx + 1);
      }

      c1_accumulatedData = c1_s;
    }
  }

  c1_accumulatedWeights = (real_T)c1_x_size[0];
  return c1_accumulatedData / c1_accumulatedWeights;
}

static real_T c1_sumColumnB(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_x_data[], int32_T c1_vlen)
{
  real_T c1_b_y;
  real_T c1_c_y;
  real_T c1_y;
  int32_T c1_a;
  int32_T c1_b_k;
  int32_T c1_b_vlen;
  int32_T c1_b_vstart;
  int32_T c1_c_k;
  int32_T c1_c_vlen;
  int32_T c1_d_k;
  int32_T c1_e_k;
  int32_T c1_f_k;
  int32_T c1_g_k;
  int32_T c1_h_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i_k;
  int32_T c1_inb;
  int32_T c1_k;
  int32_T c1_lidx;
  int32_T c1_nfb;
  int32_T c1_nleft;
  int32_T c1_vstart;
  (void)chartInstance;
  if (c1_vlen <= 1024) {
    c1_b_vlen = c1_vlen - 1;
    c1_y = c1_x_data[0];
    c1_i = c1_b_vlen;
    c1_i1 = (uint16_T)c1_i;
    for (c1_b_k = 0; c1_b_k < c1_i1; c1_b_k++) {
      c1_e_k = c1_b_k;
      c1_y += c1_x_data[c1_e_k + 1];
    }
  } else {
    c1_a = c1_vlen;
    c1_nfb = (uint16_T)((uint32_T)(uint16_T)c1_a >> 10);
    c1_inb = c1_nfb << 10;
    c1_y = c1_x_data[0];
    for (c1_k = 0; c1_k < 1023; c1_k++) {
      c1_d_k = c1_k;
      c1_y += c1_x_data[c1_d_k + 1];
    }

    for (c1_c_k = 2; c1_c_k <= c1_nfb; c1_c_k++) {
      c1_vstart = (c1_c_k - 1) << 10;
      c1_b_y = c1_x_data[c1_vstart];
      for (c1_f_k = 0; c1_f_k < 1023; c1_f_k++) {
        c1_g_k = c1_f_k;
        c1_b_y += c1_x_data[(c1_vstart + c1_g_k) + 1];
      }

      c1_y += c1_b_y;
    }

    if (c1_vlen > c1_inb) {
      c1_nleft = c1_vlen - c1_inb;
      c1_lidx = c1_inb;
      c1_c_vlen = c1_nleft - 1;
      c1_b_vstart = c1_lidx;
      c1_c_y = c1_x_data[c1_b_vstart];
      c1_i2 = c1_c_vlen;
      for (c1_h_k = 0; c1_h_k < c1_i2; c1_h_k++) {
        c1_i_k = c1_h_k;
        c1_c_y += c1_x_data[(c1_b_vstart + c1_i_k) + 1];
      }

      c1_y += c1_c_y;
    }
  }

  return c1_y;
}

static real_T c1_sumColumnB4(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_x_data[], int32_T c1_vstart)
{
  real_T c1_psum1;
  real_T c1_psum2;
  real_T c1_psum3;
  real_T c1_psum4;
  int32_T c1_b_k;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_k;
  (void)chartInstance;
  c1_i2 = c1_vstart + 1023;
  c1_i3 = c1_vstart + 2047;
  c1_i4 = c1_vstart + 3071;
  c1_psum1 = c1_x_data[c1_vstart - 1];
  c1_psum2 = c1_x_data[c1_i2];
  c1_psum3 = c1_x_data[c1_i3];
  c1_psum4 = c1_x_data[c1_i4];
  for (c1_k = 0; c1_k < 1023; c1_k++) {
    c1_b_k = c1_k + 1;
    c1_psum1 += c1_x_data[(c1_vstart + c1_b_k) - 1];
    c1_psum2 += c1_x_data[c1_i2 + c1_b_k];
    c1_psum3 += c1_x_data[c1_i3 + c1_b_k];
    c1_psum4 += c1_x_data[c1_i4 + c1_b_k];
  }

  return (c1_psum1 + c1_psum2) + (c1_psum3 + c1_psum4);
}

static real_T c1_b_sumColumnB(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_x_data[], int32_T c1_vlen, int32_T c1_vstart)
{
  real_T c1_b_y;
  real_T c1_c_y;
  real_T c1_y;
  int32_T c1_a;
  int32_T c1_b_k;
  int32_T c1_b_vlen;
  int32_T c1_b_vstart;
  int32_T c1_c_k;
  int32_T c1_c_vlen;
  int32_T c1_c_vstart;
  int32_T c1_d_k;
  int32_T c1_d_vstart;
  int32_T c1_e_k;
  int32_T c1_e_vstart;
  int32_T c1_f_k;
  int32_T c1_g_k;
  int32_T c1_h_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i_k;
  int32_T c1_inb;
  int32_T c1_k;
  int32_T c1_lidx;
  int32_T c1_nfb;
  int32_T c1_nleft;
  (void)chartInstance;
  if (c1_vlen <= 1024) {
    c1_b_vlen = c1_vlen - 1;
    c1_b_vstart = c1_vstart - 1;
    c1_y = c1_x_data[c1_b_vstart];
    c1_i = c1_b_vlen;
    for (c1_k = 0; c1_k < c1_i; c1_k++) {
      c1_c_k = c1_k;
      c1_y += c1_x_data[(c1_b_vstart + c1_c_k) + 1];
    }
  } else {
    c1_a = c1_vlen;
    c1_nfb = (uint16_T)((uint32_T)(uint16_T)c1_a >> 10);
    c1_inb = c1_nfb << 10;
    c1_c_vstart = c1_vstart - 1;
    c1_y = c1_x_data[c1_c_vstart];
    for (c1_b_k = 0; c1_b_k < 1023; c1_b_k++) {
      c1_e_k = c1_b_k;
      c1_y += c1_x_data[(c1_c_vstart + c1_e_k) + 1];
    }

    for (c1_d_k = 2; c1_d_k <= c1_nfb; c1_d_k++) {
      c1_d_vstart = (c1_vstart + ((c1_d_k - 1) << 10)) - 1;
      c1_b_y = c1_x_data[c1_d_vstart];
      for (c1_f_k = 0; c1_f_k < 1023; c1_f_k++) {
        c1_g_k = c1_f_k;
        c1_b_y += c1_x_data[(c1_d_vstart + c1_g_k) + 1];
      }

      c1_y += c1_b_y;
    }

    if (c1_vlen > c1_inb) {
      c1_nleft = c1_vlen - c1_inb;
      c1_lidx = c1_vstart + c1_inb;
      c1_c_vlen = c1_nleft - 1;
      c1_e_vstart = c1_lidx - 1;
      c1_c_y = c1_x_data[c1_e_vstart];
      c1_i1 = c1_c_vlen;
      for (c1_h_k = 0; c1_h_k < c1_i1; c1_h_k++) {
        c1_i_k = c1_h_k;
        c1_c_y += c1_x_data[(c1_e_vstart + c1_i_k) + 1];
      }

      c1_y += c1_c_y;
    }
  }

  return c1_y;
}

static void c1_c_eml_find(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_x[4960], int32_T c1_i_data[], int32_T c1_i_size[1], int32_T
  c1_j_data[], int32_T c1_j_size[1])
{
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_idx;
  int32_T c1_ii;
  int32_T c1_jj;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_exitg1;
  boolean_T c1_guard1;
  c1_idx = 0;
  c1_ii = 1;
  c1_jj = 1;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_jj <= 160)) {
    c1_guard1 = false;
    if (c1_x[(c1_ii + 31 * (c1_jj - 1)) - 1]) {
      c1_idx++;
      c1_i_data[c1_idx - 1] = c1_ii;
      c1_j_data[c1_idx - 1] = c1_jj;
      if (c1_idx >= 4960) {
        c1_exitg1 = true;
      } else {
        c1_guard1 = true;
      }
    } else {
      c1_guard1 = true;
    }

    if (c1_guard1) {
      c1_ii++;
      if (c1_ii > 31) {
        c1_ii = 1;
        c1_jj++;
      }
    }
  }

  c1_b = (c1_idx < 1);
  if (c1_b) {
    c1_i = 0;
  } else {
    c1_i = c1_idx;
  }

  c1_indexShapeCheck(chartInstance);
  c1_i_size[0] = c1_i;
  c1_b1 = (c1_idx < 1);
  if (c1_b1) {
    c1_i1 = 0;
  } else {
    c1_i1 = c1_idx;
  }

  c1_indexShapeCheck(chartInstance);
  c1_j_size[0] = c1_i1;
  c1_indexShapeCheck(chartInstance);
}

const mxArray *sf_c1_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static real_T c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId);
  sf_mex_destroy(&c1_nullptr);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_d;
  real_T c1_y;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_R = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_X = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c1_G = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_B = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_Y = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c1_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2996098885U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2542457981U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(684739594U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1699639796U);
}

mxArray *sf_c1_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Morphop_binary_tbb_Buildable"));
  return(mxcell3p);
}

mxArray *sf_c1_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("erode_binary_ones33_tbb");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiC+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lkI6BcAsiKg4QILn4Fzvw5Z7o9Ecj"
    "8AW/UQvQ=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sWLYYMH3mhqQ28mgEVD0dXF";
}

static void sf_opaque_initialize_c1_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_flightControlSystem(void *chartInstanceVar)
{
  enable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_flightControlSystem(void *chartInstanceVar)
{
  disable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc1_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c1_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrdWE1v40QYnqSlYtGyKhKClUBaLkgcQNq2WmkPCNrNBxupoQGn3S0XNLHf2KOOx+58JA2/gD/",
    "BgV/Amb/BaW9InDhy5Mg7jpNGTmg8DqgFS44zdp5533n8vB8TUut0CR4P8Nx9SMgOXl/Hs06mx2",
    "v5uLZwTu9vk0/zce8NQvyISt0Rw4S4H34SQAjCM8Mhu3LEChP3qKSxqmBX0Bi+BpVwo1ki3JxnY",
    "ggShI8TpInUTnYViw1n4qJthG8tqxcR8yMvSgwPnuGENDgRfPJ3dlOje2ixyST4ug0Q6EgmJoza",
    "nIY3syD1uBGBf6FM7MyVAu2Z1C5VdQ3XLOXQugK/I5SmyIJas15PUw0NfeWsEKa8GTqJU86oKM9",
    "1RJUHKapDw2ka4OeJ0cheSbtob8AE1YlklLdi3rAKL4ntcfSzi7LmzjzrWDdhYMKQidCyK00MAt",
    "ePOinB1bCRjEDSEE6EYwza1bWushc812X5GOxYWVaKQRNP34qqhM3stkbIkKpot+2LBuVcuWH7S",
    "XoMI+CZ/SbVtAJ2at8BrBQL+skZlTYKHCPJCHZpIMc2EhGw8m94VEBlCfdLTJ4l4Cy2koIAaZ67",
    "Pp9onSaN0kncwDBqHh+XtLeM7QgNckh9KJ37JGUK0OFMV452A6bogFs0sqSzVZaeAURlKFFDI5r",
    "jRF4gx65J9porGwluaAhCaIKGLGG0UN1nlJuSPscKM5yVx6nCjOVmF7E2fiqBfepHENh6wjh0Qd",
    "kJVOn8jHXkCFc7YnrSBOVLlpaNJKMgwEJiWepPUjgVFyIZi7ZMYi/vCG7QFQBmDSoFloVnWJbkp",
    "I3Ol/NawmXfKqtKexZTzenAauMLEFhZ7FptJaQ+RlVLYOuGDm2C9dh3WNqFYkpjOzVpZTEQZP3o",
    "w5pbP/pWPj6Yx1JH9SW+KYplWGCndDTImj3osxiyGx7FnmI6zA9r9zG5tnuvfrPdOn6rVcSRDXH",
    "PF3DbK/h5ZwG3m4/9vW+HnIWRTcJaJtybIO/xsh/3S/C9yv8ijizhrnmeXT9awNdW2CUL13V8bS",
    "3xtUVqtVqGO1zAvVmws13A7eSc/frj3qPJb+mH5L3ff/ph75efN9HH93U3PT/Ix+/P+rN5BRstJ",
    "fkyeni3oAc7Vi+Oz8+7zw/i6PKr/adx2DprPg5etrP5Xq2Jv3rB39n9D/DUmOCyfCn9TpDvteyY",
    "mukewM7/dMHfnTV83FvQEyF/fL4Z/u3D4nvcXoPfxW8vC7q9Pf8/ruT/ecH/u57nbiuv3qafZfL",
    "uVkVcnfx7ef6fxG26Ptd68l///U15gBR+v3uH10FuyE8ufcVdW9cr4lb3H+Xjz+Z7/kbEeLBi15",
    "E/xo3BcNXT/4m+/3Tkb9bntCx/+Z+W3xwcCconuM2YbuPy2z1p/y+bP5JA1eq93G3Uodn1cE2dv",
    "1+IbzseMxEkY/XJ3v6T/U3q2l8AiQOt",
    ""
  };

  static char newstr [1457] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c1_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(523346399U));
  ssSetChecksum1(S,(628155001U));
  ssSetChecksum2(S,(2951224064U));
  ssSetChecksum3(S,(3117560221U));
}

static void mdlRTW_c1_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c1_flightControlSystem(SimStruct *S)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc1_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c1_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c1_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_flightControlSystem;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c1_flightControlSystem(chartInstance);
}

void c1_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
