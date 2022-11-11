/*----------------------------------------------------------------------------
 * File:  ADTTM_SC1_class.h
 *
 * Class:       SubClass1  (SC1)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef ADTTM_SC1_CLASS_H
#define ADTTM_SC1_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   SubClass1  (SC1)
 */
struct ADTTM_SC1 {

  /* application analysis class attributes */
  Escher_UniqueID_t TSId;  /* * TSId (R4) */
  /* relationship storage */
  ADTTM_TS * TS_R4;
};

/* Note:  TS<-R4->SC1 never related (or note needed).  */
/* Note:  No TS<-R4->SC1 unrelate accessor needed.  */

#define ADTTM_SC1_MAX_EXTENT_SIZE 10
extern Escher_Extent_t pG_ADTTM_SC1_extent;

#ifdef	__cplusplus
}
#endif

#endif  /* ADTTM_SC1_CLASS_H */
