/*----------------------------------------------------------------------------
 * File:  ADTTM_ME_class.h
 *
 * Class:       Middle Entity  (ME)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef ADTTM_ME_CLASS_H
#define ADTTM_ME_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   Middle Entity  (ME)
 */
struct ADTTM_ME {

  /* application analysis class attributes */
  Escher_UniqueID_t MiddleEntityId;  /* * MiddleEntityId */
  Escher_UniqueID_t TopEntityId;  /* - TopEntityId (R1) */
  bool Comfortable;  /* - Comfortable */
  i_t PreferredTemperature;  /* - PreferredTemperature */
  i_t PreferredHumidity;  /* - PreferredHumidity */
  /* relationship storage */
  ADTTM_TE * TE_R1;
  Escher_ObjectSet_s LD_R2_measurement;
  ADTTM_MML * MML_R5;
};
void ADTTM_ME_op_Command( ADTTM_ME *, c_t[ESCHER_SYS_MAX_STRING_LEN] );
void ADTTM_ME_R1_Link_child( ADTTM_TE *, ADTTM_ME * );
void ADTTM_ME_R1_Unlink_child( ADTTM_TE *, ADTTM_ME * );
#define ADTTM_LD_R2_From_ME_measurement( ME ) ( &((ME)->LD_R2_measurement) )

#define ADTTM_ME_MAX_EXTENT_SIZE 10
extern Escher_Extent_t pG_ADTTM_ME_extent;

#ifdef	__cplusplus
}
#endif

#endif  /* ADTTM_ME_CLASS_H */
