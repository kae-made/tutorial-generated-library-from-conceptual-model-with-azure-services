/*----------------------------------------------------------------------------
 * File:  ADTTM.c
 *
 * UML Component Port Messages
 * Component/Module Name:  ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "ADTTestModel_sys_types.h"
#include "ADTTM.h"
#include "ADTTM_STR_bridge.h"
#include "ADTTM_classes.h"

/*
 * UML Domain Functions (Synchronous Services)
 */

/*
 * Domain Function:  ClearInstances
 */
void
ADTTM_ClearInstances()
{
  ADTTM_TE * te=0;Escher_ObjectSet_s teSet_space={0}; Escher_ObjectSet_s * teSet = &teSet_space;
  /* SELECT many teSet FROM INSTANCES OF TE */
  XTUML_OAL_STMT_TRACE( 1, "SELECT many teSet FROM INSTANCES OF TE" );
  Escher_CopySet( teSet, &pG_ADTTM_TE_extent.active );
  /* FOR EACH te IN teSet */
  XTUML_OAL_STMT_TRACE( 1, "FOR EACH te IN teSet" );
  { Escher_Iterator_s iterte;
  ADTTM_TE * iite;
  Escher_IteratorReset( &iterte, teSet );
  while ( (iite = (ADTTM_TE *)Escher_IteratorNext( &iterte )) != 0 ) {
    te = iite; {
    ADTTM_ME * me=0;Escher_ObjectSet_s meSet_space={0}; Escher_ObjectSet_s * meSet = &meSet_space;
    /* SELECT many meSet RELATED BY te->ME[R1.child] */
    XTUML_OAL_STMT_TRACE( 2, "SELECT many meSet RELATED BY te->ME[R1.child]" );
    Escher_ClearSet( meSet );
    if ( 0 != te ) {
      Escher_CopySet( meSet, &te->ME_R1_child );
    }
    /* FOR EACH me IN meSet */
    XTUML_OAL_STMT_TRACE( 2, "FOR EACH me IN meSet" );
    { Escher_Iterator_s iterme;
    ADTTM_ME * iime;
    Escher_IteratorReset( &iterme, meSet );
    while ( (iime = (ADTTM_ME *)Escher_IteratorNext( &iterme )) != 0 ) {
      me = iime; {
      ADTTM_LD * ld=0;Escher_ObjectSet_s ldSet_space={0}; Escher_ObjectSet_s * ldSet = &ldSet_space;
      /* SELECT many ldSet RELATED BY me->LD[R2.measurement] */
      XTUML_OAL_STMT_TRACE( 3, "SELECT many ldSet RELATED BY me->LD[R2.measurement]" );
      Escher_ClearSet( ldSet );
      if ( 0 != me ) {
        Escher_CopySet( ldSet, &me->LD_R2_measurement );
      }
      /* FOR EACH ld IN ldSet */
      XTUML_OAL_STMT_TRACE( 3, "FOR EACH ld IN ldSet" );
      { Escher_Iterator_s iterld;
      ADTTM_LD * iild;
      Escher_IteratorReset( &iterld, ldSet );
      while ( (iild = (ADTTM_LD *)Escher_IteratorNext( &iterld )) != 0 ) {
        ld = iild; {
        /* UNRELATE ld FROM me ACROSS R2 */
        XTUML_OAL_STMT_TRACE( 4, "UNRELATE ld FROM me ACROSS R2" );
        ADTTM_LD_R2_Unlink_measurement( me, ld );
        /* DELETE OBJECT INSTANCE ld */
        XTUML_OAL_STMT_TRACE( 4, "DELETE OBJECT INSTANCE ld" );
        if ( 0 == ld ) {
          XTUML_EMPTY_HANDLE_TRACE( "LD", "Escher_DeleteInstance" );
        }
        Escher_DeleteInstance( (Escher_iHandle_t) ld, ADTTM_DOMAIN_ID, ADTTM_LD_CLASS_NUMBER );
      }}}
      /* UNRELATE te FROM me ACROSS R1 */
      XTUML_OAL_STMT_TRACE( 3, "UNRELATE te FROM me ACROSS R1" );
      ADTTM_ME_R1_Unlink_child( te, me );
      /* DELETE OBJECT INSTANCE me */
      XTUML_OAL_STMT_TRACE( 3, "DELETE OBJECT INSTANCE me" );
      if ( 0 == me ) {
        XTUML_EMPTY_HANDLE_TRACE( "ME", "Escher_DeleteInstance" );
      }
      Escher_DeleteInstance( (Escher_iHandle_t) me, ADTTM_DOMAIN_ID, ADTTM_ME_CLASS_NUMBER );
      Escher_ClearSet( ldSet ); 
    }}}
    /* DELETE OBJECT INSTANCE te */
    XTUML_OAL_STMT_TRACE( 2, "DELETE OBJECT INSTANCE te" );
    if ( 0 == te ) {
      XTUML_EMPTY_HANDLE_TRACE( "TE", "Escher_DeleteInstance" );
    }
    Escher_DeleteInstance( (Escher_iHandle_t) te, ADTTM_DOMAIN_ID, ADTTM_TE_CLASS_NUMBER );
    Escher_ClearSet( meSet ); 
  }}}
  Escher_ClearSet( teSet );
}

/*
 * Domain Function:  TestExternalEntity
 */
void
ADTTM_TestExternalEntity()
{
  i_t text_length;c_t text[ESCHER_SYS_MAX_STRING_LEN];
  /* ASSIGN text = abc */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN text = abc" );
  Escher_strcpy( text, "abc" );
  /* ASSIGN text_length = STR::len(expression:text) */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN text_length = STR::len(expression:text)" );
  text_length = ADTTM_STR_len( text );
}

/*
 * Domain Function:  TestInitialize
 */
void
ADTTM_TestInitialize()
{
  ADTTM_TE * topEntity=0;
  /* SELECT any topEntity FROM INSTANCES OF TE */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any topEntity FROM INSTANCES OF TE" );
  topEntity = (ADTTM_TE *) Escher_SetGetAny( &pG_ADTTM_TE_extent.active );
  /* IF ( empty topEntity ) */
  XTUML_OAL_STMT_TRACE( 1, "IF ( empty topEntity )" );
  if ( ( 0 == topEntity ) ) {
    i_t index;
    /* CREATE OBJECT INSTANCE topEntity OF TE */
    XTUML_OAL_STMT_TRACE( 2, "CREATE OBJECT INSTANCE topEntity OF TE" );
    topEntity = (ADTTM_TE *) Escher_CreateInstance( ADTTM_DOMAIN_ID, ADTTM_TE_CLASS_NUMBER );
    topEntity->TopEntityId = Escher_ID_factory();
    /* ASSIGN topEntity.X = 10 */
    XTUML_OAL_STMT_TRACE( 2, "ASSIGN topEntity.X = 10" );
    ((ADTTM_TE *)xtUML_detect_empty_handle( topEntity, "TE", "topEntity.X" ))->X = 10;
    /* ASSIGN topEntity.S = hello */
    XTUML_OAL_STMT_TRACE( 2, "ASSIGN topEntity.S = hello" );
    Escher_strcpy( ((ADTTM_TE *)xtUML_detect_empty_handle( topEntity, "TE", "topEntity.S" ))->S, "hello" );
    /* ASSIGN index = 0 */
    XTUML_OAL_STMT_TRACE( 2, "ASSIGN index = 0" );
    index = 0;
    /* WHILE ( index < 2 ) */
    XTUML_OAL_STMT_TRACE( 2, "WHILE ( index < 2 )" );
    while ( index < 2 ) {
      i_t dindex;ADTTM_ME * middleEntity;
      /* CREATE OBJECT INSTANCE middleEntity OF ME */
      XTUML_OAL_STMT_TRACE( 3, "CREATE OBJECT INSTANCE middleEntity OF ME" );
      middleEntity = (ADTTM_ME *) Escher_CreateInstance( ADTTM_DOMAIN_ID, ADTTM_ME_CLASS_NUMBER );
      middleEntity->MiddleEntityId = Escher_ID_factory();
      /* ASSIGN middleEntity.Comfortable = FALSE */
      XTUML_OAL_STMT_TRACE( 3, "ASSIGN middleEntity.Comfortable = FALSE" );
      ((ADTTM_ME *)xtUML_detect_empty_handle( middleEntity, "ME", "middleEntity.Comfortable" ))->Comfortable = FALSE;
      /* ASSIGN middleEntity.PreferredHumidity = ( 49 + ( index * 2 ) ) */
      XTUML_OAL_STMT_TRACE( 3, "ASSIGN middleEntity.PreferredHumidity = ( 49 + ( index * 2 ) )" );
      ((ADTTM_ME *)xtUML_detect_empty_handle( middleEntity, "ME", "middleEntity.PreferredHumidity" ))->PreferredHumidity = ( 49 + ( index * 2 ) );
      /* ASSIGN middleEntity.PreferredTemperature = ( 27 - index ) */
      XTUML_OAL_STMT_TRACE( 3, "ASSIGN middleEntity.PreferredTemperature = ( 27 - index )" );
      ((ADTTM_ME *)xtUML_detect_empty_handle( middleEntity, "ME", "middleEntity.PreferredTemperature" ))->PreferredTemperature = ( 27 - index );
      /* RELATE middleEntity TO topEntity ACROSS R1 */
      XTUML_OAL_STMT_TRACE( 3, "RELATE middleEntity TO topEntity ACROSS R1" );
      ADTTM_ME_R1_Link_child( topEntity, middleEntity );
      /* ASSIGN dindex = 0 */
      XTUML_OAL_STMT_TRACE( 3, "ASSIGN dindex = 0" );
      dindex = 0;
      /* WHILE ( dindex < 3 ) */
      XTUML_OAL_STMT_TRACE( 3, "WHILE ( dindex < 3 )" );
      while ( dindex < 3 ) {
        ADTTM_LD * liefDevice;
        /* CREATE OBJECT INSTANCE liefDevice OF LD */
        XTUML_OAL_STMT_TRACE( 4, "CREATE OBJECT INSTANCE liefDevice OF LD" );
        liefDevice = (ADTTM_LD *) Escher_CreateInstance( ADTTM_DOMAIN_ID, ADTTM_LD_CLASS_NUMBER );
        liefDevice->LiefDeviceId = Escher_ID_factory();
liefDevice->MiddleEntityId = Escher_ID_factory();
        /* ASSIGN liefDevice.Number = dindex */
        XTUML_OAL_STMT_TRACE( 4, "ASSIGN liefDevice.Number = dindex" );
        ((ADTTM_LD *)xtUML_detect_empty_handle( liefDevice, "LD", "liefDevice.Number" ))->Number = dindex;
        /* ASSIGN liefDevice.RequestInterval = 10000 */
        XTUML_OAL_STMT_TRACE( 4, "ASSIGN liefDevice.RequestInterval = 10000" );
        ((ADTTM_LD *)xtUML_detect_empty_handle( liefDevice, "LD", "liefDevice.RequestInterval" ))->RequestInterval = 10000;
        /* RELATE middleEntity TO liefDevice ACROSS R2 */
        XTUML_OAL_STMT_TRACE( 4, "RELATE middleEntity TO liefDevice ACROSS R2" );
        ADTTM_LD_R2_Link_measurement( middleEntity, liefDevice );
        /* ASSIGN dindex = ( dindex + 1 ) */
        XTUML_OAL_STMT_TRACE( 4, "ASSIGN dindex = ( dindex + 1 )" );
        dindex = ( dindex + 1 );
      }
      /* ASSIGN index = ( index + 1 ) */
      XTUML_OAL_STMT_TRACE( 3, "ASSIGN index = ( index + 1 )" );
      index = ( index + 1 );
    }
  }
}

/*
 * Domain Function:  TestSelectInstances
 */
void
ADTTM_TestSelectInstances()
{
  Escher_ObjectSet_s middleEntities_space={0}; Escher_ObjectSet_s * middleEntities = &middleEntities_space;ADTTM_ME * middleEntity=0;Escher_ObjectSet_s middileEntities_space={0}; Escher_ObjectSet_s * middileEntities = &middileEntities_space;
  /* SELECT any middleEntity FROM INSTANCES OF ME */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any middleEntity FROM INSTANCES OF ME" );
  middleEntity = (ADTTM_ME *) Escher_SetGetAny( &pG_ADTTM_ME_extent.active );
  /* SELECT many middleEntities FROM INSTANCES OF ME */
  XTUML_OAL_STMT_TRACE( 1, "SELECT many middleEntities FROM INSTANCES OF ME" );
  Escher_CopySet( middleEntities, &pG_ADTTM_ME_extent.active );
  /* SELECT any middleEntity FROM INSTANCES OF ME WHERE SELECTED.Comfortable == TRUE */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any middleEntity FROM INSTANCES OF ME WHERE SELECTED.Comfortable == TRUE" );
  middleEntity = 0;
  { ADTTM_ME * selected;
    Escher_Iterator_s itermiddleEntityADTTM_ME;
    Escher_IteratorReset( &itermiddleEntityADTTM_ME, &pG_ADTTM_ME_extent.active );
    while ( (selected = (ADTTM_ME *) Escher_IteratorNext( &itermiddleEntityADTTM_ME )) != 0 ) {
      if ( ((ADTTM_ME *)xtUML_detect_empty_handle( selected, "ME", "SELECTED.Comfortable" ))->Comfortable == TRUE ) {
        middleEntity = selected;
        break;
      }
    }
  }
  /* SELECT many middileEntities FROM INSTANCES OF ME WHERE ( ( SELECTED.PreferredHumidity > 50 ) and ( SELECTED.PreferredHumidity < 25 ) ) or ( SELECTED.Comfortable == FALSE ) */
  XTUML_OAL_STMT_TRACE( 1, "SELECT many middileEntities FROM INSTANCES OF ME WHERE ( ( SELECTED.PreferredHumidity > 50 ) and ( SELECTED.PreferredHumidity < 25 ) ) or ( SELECTED.Comfortable == FALSE )" );
  Escher_ClearSet( middileEntities );
  { ADTTM_ME * selected;
    Escher_Iterator_s itermiddileEntitiesADTTM_ME;
    Escher_IteratorReset( &itermiddileEntitiesADTTM_ME, &pG_ADTTM_ME_extent.active );
    while ( (selected = (ADTTM_ME *) Escher_IteratorNext( &itermiddileEntitiesADTTM_ME )) != 0 ) {
      if ( ( ( ((ADTTM_ME *)xtUML_detect_empty_handle( selected, "ME", "SELECTED.PreferredHumidity" ))->PreferredHumidity > 50 ) && ( ((ADTTM_ME *)xtUML_detect_empty_handle( selected, "ME", "SELECTED.PreferredHumidity" ))->PreferredHumidity < 25 ) ) || ( ((ADTTM_ME *)xtUML_detect_empty_handle( selected, "ME", "SELECTED.Comfortable" ))->Comfortable == FALSE ) ) {
        Escher_SetInsertElement( middileEntities, selected );
      }
    }
  }
  Escher_ClearSet( middleEntities );Escher_ClearSet( middileEntities );
}

/*
 * Domain Function:  TestSelectRelated
 */
void
ADTTM_TestSelectRelated()
{
  ADTTM_ME * middleEntity=0;Escher_ObjectSet_s liefDevices_space={0}; Escher_ObjectSet_s * liefDevices = &liefDevices_space;ADTTM_LD * liefDevice=0;ADTTM_TE * topEntity=0;ADTTM_LD * liefDeice=0;
  /* SELECT any middleEntity FROM INSTANCES OF ME */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any middleEntity FROM INSTANCES OF ME" );
  middleEntity = (ADTTM_ME *) Escher_SetGetAny( &pG_ADTTM_ME_extent.active );
  /* SELECT one topEntity RELATED BY middleEntity->TE[R1] */
  XTUML_OAL_STMT_TRACE( 1, "SELECT one topEntity RELATED BY middleEntity->TE[R1]" );
  topEntity = ( 0 != middleEntity ) ? middleEntity->TE_R1 : 0;
  /* SELECT any liefDevice RELATED BY middleEntity->LD[R2.measurement] */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any liefDevice RELATED BY middleEntity->LD[R2.measurement]" );
  liefDevice = ( 0 != middleEntity ) ? (ADTTM_LD *) Escher_SetGetAny( &middleEntity->LD_R2_measurement ) : 0;
  /* SELECT any liefDeice RELATED BY middleEntity->LD[R2.measurement] WHERE ( SELECTED.Environment.Temperature == 25 ) */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any liefDeice RELATED BY middleEntity->LD[R2.measurement] WHERE ( SELECTED.Environment.Temperature == 25 )" );
  liefDeice = 0;
  if ( 0 != middleEntity ) {
    ADTTM_LD * selected;
    Escher_Iterator_s iLD_R2_measurement;
    Escher_IteratorReset( &iLD_R2_measurement, &middleEntity->LD_R2_measurement );
    while ( 0 != ( selected = (ADTTM_LD *) Escher_IteratorNext( &iLD_R2_measurement ) ) ) {
      if ( ((ADTTM_LD *)xtUML_detect_empty_handle( selected, "LD", "SELECTED.Environment" ))->Environment.Temperature == 25 ) {
        liefDeice = selected;
        break;
  }}}
  /* SELECT many liefDevices RELATED BY middleEntity->LD[R2.measurement] */
  XTUML_OAL_STMT_TRACE( 1, "SELECT many liefDevices RELATED BY middleEntity->LD[R2.measurement]" );
  Escher_ClearSet( liefDevices );
  if ( 0 != middleEntity ) {
    Escher_CopySet( liefDevices, &middleEntity->LD_R2_measurement );
  }
  /* SELECT many liefDevices RELATED BY middleEntity->LD[R2.measurement] WHERE ( ( SELECTED.Environment.Humidity > 50 ) and ( SELECTED.CurrentInterval < 10000 ) ) */
  XTUML_OAL_STMT_TRACE( 1, "SELECT many liefDevices RELATED BY middleEntity->LD[R2.measurement] WHERE ( ( SELECTED.Environment.Humidity > 50 ) and ( SELECTED.CurrentInterval < 10000 ) )" );
  Escher_ClearSet( liefDevices );
  if ( 0 != middleEntity ) {
  {ADTTM_LD * selected;
  Escher_Iterator_s iLD_R2_measurement;
  Escher_IteratorReset( &iLD_R2_measurement, &middleEntity->LD_R2_measurement );
  while ( 0 != ( selected = (ADTTM_LD *) Escher_IteratorNext( &iLD_R2_measurement ) ) ) {
    if ( ( ((ADTTM_LD *)xtUML_detect_empty_handle( selected, "LD", "SELECTED.Environment" ))->Environment.Humidity > 50 ) && ( ((ADTTM_LD *)xtUML_detect_empty_handle( selected, "LD", "SELECTED.CurrentInterval" ))->CurrentInterval < 10000 ) ) {
      if ( ! Escher_SetContains( (Escher_ObjectSet_s *) liefDevices, selected ) ) {
        Escher_SetInsertElement( (Escher_ObjectSet_s *) liefDevices, selected );
  }}}}}
  Escher_ClearSet( liefDevices ); 
}
/* xtUML class info (collections, sizes, etc.) */
Escher_Extent_t * const ADTTM_class_info[ ADTTM_MAX_CLASS_NUMBERS ] = {
  &pG_ADTTM_LD_extent,
  &pG_ADTTM_W_extent,
  &pG_ADTTM_TE_extent,
  &pG_ADTTM_ME_extent,
  &pG_ADTTM_OOD_extent,
  &pG_ADTTM_TS_extent,
  &pG_ADTTM_SC1_extent,
  &pG_ADTTM_SC2_extent,
  &pG_ADTTM_MML_extent
};

/*
 * Array of pointers to the class event dispatcher method.
 * Index is the (model compiler enumerated) number of the state model.
 */
const EventTaker_t ADTTM_EventDispatcher[ ADTTM_STATE_MODELS ] = {
  ADTTM_class_dispatchers
};

void ADTTM_execute_initialization()
{
}
