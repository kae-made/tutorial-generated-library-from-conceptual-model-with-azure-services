// ------------------------------------------------------------------------------
// <auto-generated>
//     This file is generated by tool.
//     Runtime Version : 1.0.0
//  
//     Updates this file cause incorrect behavior 
//     and will be lost when the code is regenerated.
// </auto-generated>
// ------------------------------------------------------------------------------
using System;
using System.Collections.Generic;
using System.Linq;
using Kae.StateMachine;
using Kae.Utility.Logging;
using Kae.DomainModel.Csharp.Framework;
using Kae.DomainModel.Csharp.Framework.Adaptor.ExternalStorage;
using Kae.DomainModel.Csharp.Framework.ExternalEntities.AzureIoTHub;

namespace BuildingManagement
{
    public partial class DomainClassACBase : DomainClassAC
    {
        protected static readonly string className = "AC";

        public string DomainName { get { return CIMBuildingManagementLib.DomainName; }}
        public string ClassName { get { return className; } }

        InstanceRepository instanceRepository;
        protected Logger logger;

        protected AIHWrapper azureIoTHubWrapper { get; set; }


        public string GetIdForExternalStorage() {  return $"AirConId={attr_AirConId}"; }

        public static DomainClassACBase CreateInstance(InstanceRepository instanceRepository, Logger logger=null, IList<ChangedState> changedStates=null, bool synchronousMode = false)
        {
            var newInstance = new DomainClassACBase(instanceRepository, logger, synchronousMode);
            // Extension for Azure IoT Hub
            newInstance.azureIoTHubWrapper = (AIHWrapper)instanceRepository.GetExternalEntity("AIH");
            if (logger != null) logger.LogInfo($"@{DateTime.Now.ToString("yyyyMMddHHmmss.fff")}:AC(AirConId={newInstance.Attr_AirConId}):create");

            instanceRepository.Add(newInstance);

            if (changedStates !=null) changedStates.Add(new CInstanceChagedState() { OP = ChangedState.Operation.Create, Target = newInstance, ChangedProperties = null });

            return newInstance;
        }

        public DomainClassACBase(InstanceRepository instanceRepository, Logger logger, bool synchronousMode)
        {
            this.instanceRepository = instanceRepository;
            this.logger = logger;
            attr_AirConId = Guid.NewGuid().ToString();
        }
        protected string attr_AirConId;
        protected bool stateof_AirConId = false;

        protected string attr_TargetRoomId;
        protected bool stateof_TargetRoomId = false;

        protected string attr_ModelName;
        protected bool stateof_ModelName = false;

        protected bool attr_PowerState;
        protected bool stateof_PowerState = false;

        protected double attr_PowerWatts;
        protected bool stateof_PowerWatts = false;

        protected DomainTypeEquipmentsState attr_CurrentState;
        protected bool stateof_CurrentState = false;

        public string Attr_AirConId { get { return attr_AirConId; } set { attr_AirConId = value; stateof_AirConId = true; } }
        public string Attr_TargetRoomId { get { return attr_TargetRoomId; } }
        public string Attr_ModelName { get { return attr_ModelName; } set { attr_ModelName = value; stateof_ModelName = true; } }
        public bool Attr_PowerState { get { return attr_PowerState; } set { attr_PowerState = value; stateof_PowerState = true; } }
        public double Attr_PowerWatts { get { return attr_PowerWatts; } set { attr_PowerWatts = value; stateof_PowerWatts = true; } }
        public DomainTypeEquipmentsState Attr_CurrentState { get { return attr_CurrentState; } set { attr_CurrentState = value; stateof_CurrentState = true; } }


        // This method can be used as compare predicattion when calling InstanceRepository's SelectInstances method. 
        public static bool Compare(DomainClassAC instance, IDictionary<string, object> conditionPropertyValues)
        {
            bool result = true;
            foreach (var propertyName in conditionPropertyValues.Keys)
            {
                switch (propertyName)
                {
                    case "AirConId":
                        if ((string)conditionPropertyValues[propertyName] != instance.Attr_AirConId)
                        {
                            result = false;
                        }
                        break;
                    case "TargetRoomId":
                        if ((string)conditionPropertyValues[propertyName] != instance.Attr_TargetRoomId)
                        {
                            result = false;
                        }
                        break;
                    case "ModelName":
                        if ((string)conditionPropertyValues[propertyName] != instance.Attr_ModelName)
                        {
                            result = false;
                        }
                        break;
                    case "PowerState":
                        if ((bool)conditionPropertyValues[propertyName] != instance.Attr_PowerState)
                        {
                            result = false;
                        }
                        break;
                    case "PowerWatts":
                        if ((double)conditionPropertyValues[propertyName] != instance.Attr_PowerWatts)
                        {
                            result = false;
                        }
                        break;
                    case "CurrentState":
                        if ((DomainTypeEquipmentsState)conditionPropertyValues[propertyName] != instance.Attr_CurrentState)
                        {
                            result = false;
                        }
                        break;
                }
                if (result== false)
                {
                    break;
                }
            }
            return result;
        }
        protected LinkedInstance relR4R;
        public DomainClassR LinkedR4()
        {
            if (relR4R == null)
            {
                var candidates = instanceRepository.GetDomainInstances("R").Where(inst=>(this.Attr_TargetRoomId==((DomainClassR)inst).Attr_RoomId));
                if (candidates.Count() == 0)
                {
                   if (instanceRepository.ExternalStorageAdaptor != null) candidates = instanceRepository.ExternalStorageAdaptor.CheckTraverseStatus(DomainName, this, "R", "R4", candidates, () => { return DomainClassRBase.CreateInstance(instanceRepository, logger); }, "any").Result;
                }
                relR4R = new LinkedInstance() { Source = this, Destination = candidates.FirstOrDefault(), RelationshipID = "R4", Phrase = "" };

            }
            return relR4R.GetDestination<DomainClassR>();
        }

        public bool LinkR4(DomainClassR instance, IList<ChangedState> changedStates=null)
        {
            bool result = false;
            if (relR4R == null)
            {
                this.attr_TargetRoomId = instance.Attr_RoomId;
                this.stateof_TargetRoomId = true;

                if (logger != null) logger.LogInfo($"@{DateTime.Now.ToString("yyyyMMddHHmmss.fff")}:AC(AirConId={this.Attr_AirConId}):link[R(RoomId={instance.Attr_RoomId})]");

                result = (LinkedR4()!=null);
                if (result)
                {
                    if(changedStates != null) changedStates.Add(new CLinkChangedState() { OP = ChangedState.Operation.Create, Target = relR4R });
                }
            }
            return result;
        }

        public bool UnlinkR4(DomainClassR instance, IList<ChangedState> changedStates=null)
        {
            bool result = false;
            if (relR4R != null && ( this.Attr_TargetRoomId==instance.Attr_RoomId ))
            {
                if (changedStates != null) changedStates.Add(new CLinkChangedState() { OP = ChangedState.Operation.Delete, Target = relR4R });
        
                this.attr_TargetRoomId = null;
                this.stateof_TargetRoomId = true;
                relR4R = null;

                if (logger != null) logger.LogInfo($"@{DateTime.Now.ToString("yyyyMMddHHmmss.fff")}:AC(AirConId={this.Attr_AirConId}):unlink[R(RoomId={instance.Attr_RoomId})]");


                result = true;
            }
            return result;
        }

        public DomainClassAT LinkedR6One()
        {
            var candidates = instanceRepository.GetDomainInstances("AT").Where(inst=>(this.Attr_AirConId==((DomainClassAT)inst).Attr_AirConId));
            if (candidates.Count() == 0)
            {
                if (instanceRepository.ExternalStorageAdaptor != null) candidates = instanceRepository.ExternalStorageAdaptor.CheckTraverseStatus(DomainName, this, "AT", "R6_", candidates, () => { return DomainClassATBase.CreateInstance(instanceRepository, logger); }, "any").Result;
                if (candidates.Count() > 0) ((DomainClassAT)candidates.FirstOrDefault()).LinkedR6OtherAffect();
            }
            return (DomainClassAT)candidates.FirstOrDefault();
        }



        
        public bool Validate()
        {
            bool isValid = true;
            if (relR4R == null)
            {
                isValid = false;
            }
            return isValid;
        }

        public void DeleteInstance(IList<ChangedState> changedStates=null)
        {
            if (logger != null) logger.LogInfo($"@{DateTime.Now.ToString("yyyyMMddHHmmss.fff")}:AC(AirConId={this.Attr_AirConId}):delete");

            changedStates.Add(new CInstanceChagedState() { OP = ChangedState.Operation.Delete, Target = this, ChangedProperties = null });

            instanceRepository.Delete(this);
        }

        // methods for storage
        public void Restore(IDictionary<string, object> propertyValues)
        {
            if (propertyValues.ContainsKey("AirConId"))
            {
                attr_AirConId = (string)propertyValues["AirConId"];
            }
            stateof_AirConId = false;
            if (propertyValues.ContainsKey("TargetRoomId"))
            {
                attr_TargetRoomId = (string)propertyValues["TargetRoomId"];
            }
            stateof_TargetRoomId = false;
            if (propertyValues.ContainsKey("ModelName"))
            {
                attr_ModelName = (string)propertyValues["ModelName"];
            }
            stateof_ModelName = false;
            if (propertyValues.ContainsKey("PowerState"))
            {
                attr_PowerState = (bool)propertyValues["PowerState"];
            }
            stateof_PowerState = false;
            if (propertyValues.ContainsKey("PowerWatts"))
            {
                attr_PowerWatts = (double)propertyValues["PowerWatts"];
            }
            stateof_PowerWatts = false;
            if (propertyValues.ContainsKey("CurrentState"))
            {
                attr_CurrentState = (DomainTypeEquipmentsState)propertyValues["CurrentState"];
            }
            stateof_CurrentState = false;
        }
        
        public IDictionary<string, object> ChangedProperties()
        {
            var results = new Dictionary<string, object>();
            if (stateof_AirConId)
            {
                results.Add("AirConId", attr_AirConId);
                stateof_AirConId = false;
            }
            if (stateof_TargetRoomId)
            {
                results.Add("TargetRoomId", attr_TargetRoomId);
                stateof_TargetRoomId = false;
            }
            if (stateof_ModelName)
            {
                results.Add("ModelName", attr_ModelName);
                stateof_ModelName = false;
            }
            if (stateof_PowerState)
            {
                results.Add("PowerState", attr_PowerState);
                stateof_PowerState = false;
            }
            if (stateof_PowerWatts)
            {
                results.Add("PowerWatts", attr_PowerWatts);
                stateof_PowerWatts = false;
            }
            if (stateof_CurrentState)
            {
                results.Add("CurrentState", attr_CurrentState);
                stateof_CurrentState = false;
            }

            return results;
        }

        public string GetIdentities()
        {
            string identities = $"AirConId={this.Attr_AirConId}";

            return identities;
        }
        
        public IDictionary<string, object> GetProperties(bool onlyIdentity)
        {
            var results = new Dictionary<string, object>();

            results.Add("AirConId", attr_AirConId);
            if (!onlyIdentity) results.Add("TargetRoomId", attr_TargetRoomId);
            if (!onlyIdentity) results.Add("ModelName", attr_ModelName);
            if (!onlyIdentity) results.Add("PowerState", attr_PowerState);
            if (!onlyIdentity) results.Add("PowerWatts", attr_PowerWatts);
            if (!onlyIdentity) results.Add("CurrentState", attr_CurrentState);

            return results;
        }

#if false
        List<ChangedState> changedStates = new List<ChangedState>();

        public IList<ChangedState> ChangedStates()
        {
            List<ChangedState> results = new List<ChangedState>();
            results.AddRange(changedStates);
            results.Add(new CInstanceChagedState() { OP = ChangedState.Operation.Update, Target = this, ChangedProperties = ChangedProperties() });
            changedStates.Clear();

            return results;
        }
#endif
    }
}
