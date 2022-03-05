
#include "smee.h"
#include <EH4A_if.h>
#include <TR4A_if.h>
#include <CN4A_if.h>

//TODO: ~{293dFdK|Mb2?M7ND<~R}SC~}
//////////////////////////////////////////////////////////////////////////
#include <ME4A_if.h>
#include <WS4A_if.h>
#include <WA4A_tc.h>
#include <RA4A_if.h>
#include <CO4A_tc.h>

//#include <CA4A_if.h>
//#include <RH4A_if.h>
#include <CI4A_if.h>
#include <CM4A_if.h>
#include <FE4A_if.h>
#include <ME2PME_if.h>
#include <MC2PME_tc.h>
#include <FEMC_tc.h>
#include <WSMC_tc.h>
#include <MF4A_if.h>
#include <UA4A_if.h>
#include <CBMC_tc.h>
#include <AOMC_tc.h>
#include <AO4A_if.h>
#include <DC4A_if.h>
#include <EC2PME_if.h>
#include <EC4A_if.h>
#include <FS4A_if.h>
#include <CT4A_if.h>
#include <ES4A_tc.h>
#include <IDMC_tc.h>
#include <MC4A_tc.h>




int main()
{
	
	int ret_val=0;
	int func_num=0;
	int iResult=OK;
	int item;
	int iLink_error[2]={};
	EC4A_LOT_STRUCT lot;
	AO4A_FF_RESULTS_STRUCT FF_resuts;	
	EC2PME_ALIGN_SCENARIO_STRUCT  sAlignScenaro;
	ME4A_RETICLE_LEVEL_PLATE_ENUM RS_plate_id;		
	int color_index,grating_index;
	SMEE_BOOL step_out=SMEE_FALSE;

	SMEE_BOOL initialised=SMEE_TRUE;

	SMEE_BOOL bFF_Done=SMEE_FALSE;
	
	SMEE_INT32 iErrorLink[2]={0,0};

	iResult = CN4A_task_init(NULL);
	if (OK != iResult)
	{
		iLink_error[0] = iResult;
		iLink_error[1] = 0;
	
	   EH4A_show_exception( iResult, NULL,	__FILE__, __LINE__,	"CN4A_task_init failed." );
	}
	
	// ~{OBCf:/J}SCSZ3uJ<;/H+2?=S?Z#:~}
     ME4A_TRM_STRUCT plate_trm={};
  if(OK==iResult)
  {
  	iResult=ME4A_initialize();
  	
  }
//  if(OK==iResult)
//  {
//  	iResult=ME4A_get_plate_TRM(ME4A_WAFER_LEVEL_PLATE_RA2,  &plate_trm);
//  }
  if(OK==iResult)
  {
  	iResult=MT4A_initialize();
  	
  }
  if(OK==iResult)
  {
  	iResult=AO4A_initialize();
  	
  }
 

	if(OK==iResult)
  {
  	iResult=CO4A_initialize();
  	
  }
  if(OK==iResult)
  {
  	iResult=CB4A_initialize();
  	
  }
 
  
  if(OK==iResult)
  {
  	iResult=FM4A_initialize();
  	
  }
  if(OK==iResult)
  {
  	iResult=FE4A_initialize();
  	
  }
  if(OK==iResult)
  {
  	iResult=MC4A_initialize();
  	
  }
  
  if(OK==iResult)
  {
  	iResult=EC4A_initialize();
  	
  }
  if(OK==iResult)
  {
  	iResult=RO4A_initialize();
  	
  }
  if(OK==iResult)
  {
  	 // printf("sunccessed!\n");
	  printf("hello! I'm 134");
  }
  else
  {
  	  printf("failed look EH TR!\n");
  }
   printf("hello! I'm 139");
  //begin test Measure pos
  MC4A_LOT_DATA_STRUCT sLotData;   
  FM4A_XVSA_LOT_DATA_STRUCT  sXVSA_lot_data;//��չ����̨��ƽ������
  
  memset(&sXVSA_lot_data, 0, sizeof(FM4A_XVSA_LOT_DATA_STRUCT));  
  memset(&sLotData, 0, sizeof(MC4A_LOT_DATA_STRUCT));
   printf("hello! I'm 145");
  
     /************************************************************************/
	 /* 1 LOT ����׼��														 */
	 /************************************************************************/
	 /******************************************/
	 /* 1.1 ����FM��ƽ����(����׼���ƽRA��IS) */
	 /******************************************/
  
	 sLotData.fm_lot_data.bUse_high_precision_xsa_level = SMEE_TRUE;

			 
	 printf("hello! I'm 154");
			 

//	 if(OK == iResult)
//	 {
//		 //����RO��ȡ��׼���ƽ������
//		 iResult = RO4A_det_XSA_lot_data(&sXVSA_lot_data);  
//		 if(OK != iResult)
//		 {
//			 iErrorLink[0] = iResult;
//			 EH4A_show_exception(iResult, iResult, __FILE__, __LINE__,
//								 "%s: get the XVSA data error.", __FUNCTION__);
//
//		 }
//		 else
//		 {
//			 memcpy(&(sLotData.fm_lot_data.sXVSA_lot_data), &sXVSA_lot_data, sizeof(FM4A_XVSA_LOT_DATA_STRUCT));
//		 }
//	 }
//	 //TR4A_trace("EM", TR4A_TRACE_INT, __FUNCTION__, "<( sXVSA_lot_data.IS_pos.x=%lf)", sXVSA_lot_data.IS_pos->x);
//	 //TR4A_trace("EM", TR4A_TRACE_INT, __FUNCTION__, "<( sXVSA_lot_data.IS_pos.y=%lf)",	sXVSA_lot_data.IS_pos->y);
//  
	 /**************************************/
	 /* 1.2 ˮƽ���������ݵ����		  */
	 /* 	(�����Ƭ��˲���Ҫ��д) 	  */
	 /**************************************/
//	 //�����׼����(��)
	 if(OK == ret_val)
	 {
		 strncpy(sLotData.co_lot_data.active_strategy.strategy_id, "Default_strat", 100);
		 sLotData.co_lot_data.active_strategy.strategy_id[100] = '\0';
		 sLotData.co_lot_data.active_strategy.marks.nr_align_marks = 0;
		 sLotData.co_lot_data.active_strategy.marks.mark[0].position.x = 0.08;
		 sLotData.co_lot_data.active_strategy.marks.mark[0].position.y = 0.0;
  
		 sLotData.co_lot_data.active_strategy.marks.mark[1].position.x = -0.08;
		 sLotData.co_lot_data.active_strategy.marks.mark[1].position.y = 0.0;
  
		 sLotData.co_lot_data.active_strategy.marks.mark[2].position.x = 0.0;
		 sLotData.co_lot_data.active_strategy.marks.mark[2].position.y = 0.0;
//
		 printf("hello! I'm 200");
		 for( item = 0; item < sLotData.co_lot_data.active_strategy.marks.nr_align_marks; item++)
		 {
			 sLotData.co_lot_data.active_strategy.marks.mark[item].type = XPA;
  
			 sLotData.co_lot_data.active_strategy.marks.mark[item].mark_id = item + 1;
  
			 sLotData.co_lot_data.active_strategy.marks.mark[item].mark_align_usage = CO4A_COARSE_AND_FINE_PHASE;		//coarse &fine
  
			 strncpy(sLotData.co_lot_data.active_strategy.marks.mark[item].recipe_id,
					 "ME_default_fiducial_recipe",
					 100);
			 sLotData.co_lot_data.active_strategy.marks.mark[item].recipe_id[100] = '\0';
  
			 strncpy(sLotData.co_lot_data.active_strategy.marks.mark[item].varient_id,
					 "VARIANT",
					 100);
			 sLotData.co_lot_data.active_strategy.marks.mark[item].varient_id[100] = '\0';
		 }
  		 printf("hello! I'm 219");
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.min_absolute_wafermark_distance_for_coarse_phase = 0.06;  //60mm
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.min_relative_wafermark_distance_for_fine_phase = 0.6;	 //60%
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.delta_80_88_um_shift_threshold = 0.001;					 //1mm
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wafer_mark_residual_threshold = 0.001;					 //1mm
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.use_8u_error_detection = CO4A_LET_MC_DECIDE_ABOUT_8U_ERROR_DETECTION;
  
		 strncpy(sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wafer_grid_model.key,
				 "4_parameter_model",
				 100);
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wafer_grid_model.key[100] = '\0';
         printf("hello! I'm 231");
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wa_corr_process_data.red_branch_shift_80_88.x = 0.0;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wa_corr_process_data.red_branch_shift_80_88.y = 0.0;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wa_corr_process_data.green_branch_shift_80_88.x = 0.0;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wa_corr_process_data.green_branch_shift_80_88.y = 0.0;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wa_corr_process_data.red_branch_shift_80_16.x = 0.0;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wa_corr_process_data.red_branch_shift_80_16.y = 0.0;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wa_corr_process_data.green_branch_shift_80_16.x = 0.0;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wa_corr_process_data.green_branch_shift_80_16.y = 0.0;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wa_corr_process_data.red_branch_shift_80_14.x = 0.0;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wa_corr_process_data.red_branch_shift_80_14.y = 0.0;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wa_corr_process_data.green_branch_shift_80_14.x = 0.0;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.wa_corr_process_data.green_branch_shift_80_14.y = 0.0;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.use_fast_SPM_scans_in_fine_phase = SMEE_FALSE;
  
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.use_HPA_complete_wa = SMEE_FALSE;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.n_complete_WA = 0;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.min_nr_fine_align_marks_x = 3;
		 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.min_nr_fine_align_marks_y = 3;
		 printf("hello! I'm 250");
//
//
		 for( color_index = 0; color_index < CO4A_MAX_COLORS; color_index++)
		 {
			 for( grating_index = 0; grating_index < CO4A_MAX_SINGLE_GRATING; grating_index++)
			 {
				 sLotData.co_lot_data.active_strategy.wafer_alignment_requirements.monitoring_overrule[color_index][grating_index] = CO4A_LET_MC_DECIDE_ABOUT_MONITORING_OVERRULE;
			 }
		 }
		 
     }
	  printf("hello! I'm 262");
//
	 if (ret_val==OK)
		 {
				printf("hello! victory:266");
		 }
//
//
//	 VTMA
	 //��Ƭ��ת��
	 sLotData.co_lot_data.wafer_orientation = CO4A_DEGR_0;	 //��Ƭ����ϵ�����빤��̨����ϵ������ͬ
  
	 //������׼������
	 sLotData.co_lot_data.nr_align_recipes = 0;
	 //��׼��������
	 sLotData.co_lot_data.nr_align_recipes = 1;
	 printf("hello! victory:278");
//  
//	 /******************************************/
//	 /* 1.3 ˮƽ���׼recipe���ݵĶ�ȡ		 */
//	 /******************************************/
//
	 if(OK == ret_val)
	 {
		 //ע�⣺�����recipe_file_name��ָ�����./SEMEE��·����(ע��name��ͬ��ID)
	
		 {
			 strncpy(sLotData.co_lot_data.align_recipes[0].recipe_id,
					"ME_default_fiducial_recipe",CO4A_RECIPE_ID_SIZE-1); //Recipe ID��ͬ��Recipe Name
					sLotData.co_lot_data.align_recipes[0].recipe_id[CO4A_RECIPE_ID_SIZE-1] = '\0';
			 strncpy(sLotData.co_lot_data.align_recipes[0].recipe_data.recipe_description,
					 "ab", WA4A_MAX_FILENAME_SIZE - 1); //��׼����������
			 sLotData.co_lot_data.align_recipes[0].recipe_data.recipe_description[WA4A_MAX_FILENAME_SIZE - 1] = '\0';
  
			 sLotData.co_lot_data.align_recipes[0].recipe_data.MCC_threshold_process =
				 SMEE_TRUE;  //�Ƿ���WCC��ֵ�趨
			 sLotData.co_lot_data.align_recipes[0].recipe_data.WQ_threshold_process =
				 SMEE_TRUE;    //�Ƿ���WQ��ֵ�趨
			 sLotData.co_lot_data.align_recipes[0].recipe_data.flyer_detection_process =
				 SMEE_TRUE; //�Ƿ�ʹ��flyer_detection
			 sLotData.co_lot_data.align_recipes[0].recipe_data.color_dynamic_process =
				 SMEE_TRUE; //�Ƿ�ʹ��ɫ��̬
			 sLotData.co_lot_data.align_recipes[0].recipe_data.WQ_dynamic_selection =
				 SMEE_TRUE; //WQ��̬�������
			 sLotData.co_lot_data.align_recipes[0].recipe_data.WQ_dynamic_selection_count =
				 SMEE_TRUE; //WQ��̬�������
			 sLotData.co_lot_data.align_recipes[0].recipe_data.MCC_dynamic_selection =
				 SMEE_TRUE; //�Ƿ�ʹ��MCC��̬����
			 sLotData.co_lot_data.align_recipes[0].recipe_data.MCC_dynamic_selection_count =
				1;//MCC��̬�������
			 sLotData.co_lot_data.align_recipes[0].recipe_data.all_to_be_validated_orders_should_survive =
				 SMEE_TRUE; //�Ƿ�ʹ��validated_orders_should_survive����
			 sLotData.co_lot_data.align_recipes[0].recipe_data.s_factor =
				 1.0; //�Զ�������
  
			 //Ȩ�ز��ֵĴ���(����RE�ӿ���WA�Ľӿڲ�һ�£�������ֱ�Ӹ�ֵ)


				 sLotData.co_lot_data.align_recipes[0].recipe_data.weight_method = WA4A_STATICS_METHOD;

				 int dir,color,period,order;

			 //��������
			 for( dir = 0; (OK == ret_val) && (dir < WA4A_DIRECTIONS_NUMBER); dir++)
			 {
				// if(sMyAlign_recipe_data.directions[dir].is_enabled) //�÷����Ƿ����
				 {
					 sLotData.co_lot_data.align_recipes[0].recipe_data.direction[dir].enabled
						 = SMEE_TRUE;
					 //������ɫ
					 for(color = 0; (OK == ret_val) && (color < WA4A_COLOURS_NUMBER); color++)
					 {
						// if(sMyAlign_recipe_data.directions[dir].colors[color].is_enabled) //��ɫ�Ƿ����
						 {
							 sLotData.co_lot_data.align_recipes[0].recipe_data.direction[dir].color[color].enabled
								 = SMEE_TRUE;
							 sLotData.co_lot_data.align_recipes[0].recipe_data.direction[dir].color[color].flyer_range
								 = 1.0;
  
							 //��������

							 
							 for( period = 0; (OK == ret_val) && (period < WA4A_PERIODS_NUMBER); period++)
							 {
								// if(sMyAlign_recipe_data.directions[dir].colors[color].periods[period].is_enabled)
								 {
									 sLotData.co_lot_data.align_recipes[0].recipe_data.direction[dir].color[color].period[period].enabled
										 = SMEE_TRUE;
  
									 //��������
									 for( order = 0; (OK == ret_val) && (order < WA4A_ORDERS_NUMBER); order++)
									 {

  
										 sLotData.co_lot_data.align_recipes[0].recipe_data.direction[dir].color[color].period[period].order[order].deterctor_used
											 = SMEE_TRUE;
										 sLotData.co_lot_data.align_recipes[0].recipe_data.direction[dir].color[color].period[period].order[order].use_for_validation
											 = SMEE_TRUE;
										 sLotData.co_lot_data.align_recipes[0].recipe_data.direction[dir].color[color].period[period].order[order].WQ_threshold
											 = 1.0;
										 sLotData.co_lot_data.align_recipes[0].recipe_data.direction[dir].color[color].period[period].order[order].MCC_threshold
											 =1.0;
										 sLotData.co_lot_data.align_recipes[0].recipe_data.direction[dir].color[color].period[period].order[order].weight_factor
											 = 1.0;
  
									 }
								 }
							 }
						 }
					 }
				 }
			 }
  
		 } //recipe data����
	 }
//

	 if(OK == ret_val)
	 {
		   ret_val = MC2PME_start_test(&sLotData);
	
	 }
	 MC2PME_POTEST_RESULTS_STRUCT sWaferResult;
	 memset(&sWaferResult, 0, sizeof(MC2PME_POTEST_RESULTS_STRUCT));
	 if (ret_val ==OK)
	 {
		 ret_val = MC2PME_prepare_POTest(
			 1,
			 1,
			 1,
			 1,
			 &sWaferResult);

	 }

	 if (ret_val == OK)
	 {
		 printf("hello! victory all");

	 }
	return ret_val;
	

}
