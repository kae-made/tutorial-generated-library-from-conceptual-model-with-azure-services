/*----------------------------------------------------------------------------
 * File:  ADTTM_OOD_class.h
 *
 * Class:       Order of Device  (OOD)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef ADTTM_OOD_CLASS_H
#define ADTTM_OOD_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   Order of Device  (OOD)
 */
struct ADTTM_OOD {

  /* application analysis class attributes */
  Escher_UniqueID_t OodId;  /* * OodId */
  Escher_UniqueID_t left_LiefDeviceId;  /* *2 left_LiefDeviceId (R3) */
  Escher_UniqueID_t right_LiefDeviceId;  /* *2 right_LiefDeviceId (R3) */
  /* relationship storage */
  ADTTM_LD * LD_R3_right;
  ADTTM_LD * LD_R3_left;
};

/*

 * R3 is Associative Reflexive:  1-(0..1:0..1)
 *
 *  Referential attribute Order of Device.left_LiefDeviceId
 *    refers across R3 in the direction of right (R_AONE)
 *
 *  Referential attribute Order of Device.right_LiefDeviceId
 *    refers across R3 in the direction of left (R_AOTH)
 */
/* Navigation phrase:  R3.'right' */
/* Note:  Link LD to LD across R3.'right' using OOD not needed.  */
/* Note:  Unlink LD from LD across R3.'right' USING OOD not needed.  */
/* Navigation phrase:  R3.'left' */
/* Note:  Link LD to LD across R3.'left' using OOD not needed.  */
/* Note:  Unlink LD from LD across R3.'left' USING OOD not needed.  */

#define ADTTM_OOD_MAX_EXTENT_SIZE 10
extern Escher_Extent_t pG_ADTTM_OOD_extent;

#ifdef	__cplusplus
}
#endif

#endif  /* ADTTM_OOD_CLASS_H */
