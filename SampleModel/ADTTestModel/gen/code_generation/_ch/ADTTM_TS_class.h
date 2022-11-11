/*----------------------------------------------------------------------------
 * File:  ADTTM_TS_class.h
 *
 * Class:       TestSuper  (TS)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef ADTTM_TS_CLASS_H
#define ADTTM_TS_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   TestSuper  (TS)
 */
struct ADTTM_TS {

  /* application analysis class attributes */
  Escher_UniqueID_t TSId;  /* * TSId */
  /* relationship storage */
  void * R4_subtype;
  Escher_ClassNumber_t R4_object_id;
};


/* Accessors to TS[R4] subtypes */
/* Note:  TS->SC1[R4] not navigated */
/* Note:  TS->SC2[R4] not navigated */


#define ADTTM_TS_MAX_EXTENT_SIZE 10
extern Escher_Extent_t pG_ADTTM_TS_extent;

#ifdef	__cplusplus
}
#endif

#endif  /* ADTTM_TS_CLASS_H */
