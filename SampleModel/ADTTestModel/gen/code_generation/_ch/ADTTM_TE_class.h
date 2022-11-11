/*----------------------------------------------------------------------------
 * File:  ADTTM_TE_class.h
 *
 * Class:       Top Entity  (TE)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef ADTTM_TE_CLASS_H
#define ADTTM_TE_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   Top Entity  (TE)
 */
struct ADTTM_TE {

  /* application analysis class attributes */
  Escher_UniqueID_t TopEntityId;  /* * TopEntityId */
  i_t X;  /* - X */
  c_t S[ESCHER_SYS_MAX_STRING_LEN];  /* - S */
  i_t TestInterval;  /* - TestInterval */
  /* relationship storage */
  Escher_ObjectSet_s ME_R1_child;
};
i_t ADTTM_TE_op_GetNumberOfLiefDevices( ADTTM_TE * );
#define ADTTM_ME_R1_From_TE_child( TE ) ( &((TE)->ME_R1_child) )

#define ADTTM_TE_MAX_EXTENT_SIZE 10
extern Escher_Extent_t pG_ADTTM_TE_extent;

#ifdef	__cplusplus
}
#endif

#endif  /* ADTTM_TE_CLASS_H */
