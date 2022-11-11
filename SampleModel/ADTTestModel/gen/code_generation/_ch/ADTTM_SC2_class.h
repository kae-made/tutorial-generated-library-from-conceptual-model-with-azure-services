/*----------------------------------------------------------------------------
 * File:  ADTTM_SC2_class.h
 *
 * Class:       SubClass2  (SC2)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef ADTTM_SC2_CLASS_H
#define ADTTM_SC2_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   SubClass2  (SC2)
 */
struct ADTTM_SC2 {

  /* application analysis class attributes */
  Escher_UniqueID_t TSId;  /* * TSId (R4) */
  /* relationship storage */
  ADTTM_TS * TS_R4;
};

/* Note:  TS<-R4->SC2 never related (or note needed).  */
/* Note:  No TS<-R4->SC2 unrelate accessor needed.  */

#define ADTTM_SC2_MAX_EXTENT_SIZE 10
extern Escher_Extent_t pG_ADTTM_SC2_extent;

#ifdef	__cplusplus
}
#endif

#endif  /* ADTTM_SC2_CLASS_H */
