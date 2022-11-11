/*----------------------------------------------------------------------------
 * File:  ADTTM_MML_class.h
 *
 * Class:       Mapping Middel To Lief  (MML)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef ADTTM_MML_CLASS_H
#define ADTTM_MML_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   Mapping Middel To Lief  (MML)
 */
struct ADTTM_MML {

  /* application analysis class attributes */
  Escher_UniqueID_t MMLId;  /* * MMLId */
  Escher_UniqueID_t MiddleEntityId;  /* *2 MiddleEntityId (R5) */
  Escher_UniqueID_t LiefDeviceId;  /* *2 LiefDeviceId (R5) */
  /* relationship storage */
  ADTTM_ME * ME_R5_middle;
  ADTTM_LD * LD_R5_lief;
};

/* Note:  Link ME to LD across R5 using MML not needed.  */
/* Note:  Unlink ME from LD across R5 using MML not needed.  */

#define ADTTM_MML_MAX_EXTENT_SIZE 10
extern Escher_Extent_t pG_ADTTM_MML_extent;

#ifdef	__cplusplus
}
#endif

#endif  /* ADTTM_MML_CLASS_H */
