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

namespace BuildingManagement
{
    public partial class DomainClassLCBase : DomainClassLC
    {
        protected static readonly string className = "LC";

        public string DomainName { get { return CIMBuildingManagementLib.DomainName; }}
        public string ClassName { get { return className; } }

        InstanceRepository instanceRepository;
        protected Logger logger;


        public string GetIdForExternalStorage() {  return $"CustomerId={attr_CustomerId};RoomId={attr_RoomId}"; }

        public static DomainClassLCBase CreateInstance(InstanceRepository instanceRepository, Logger logger=null, IList<ChangedState> changedStates=null, bool synchronousMode = false)
        {
            var newInstance = new DomainClassLCBase(instanceRepository, logger, synchronousMode);
            if (logger != null) logger.LogInfo($"@{DateTime.Now.ToString("yyyyMMddHHmmss.fff")}:LC(CustomerId={newInstance.Attr_CustomerId},RoomId={newInstance.Attr_RoomId}):create");

            instanceRepository.Add(newInstance);

            if (changedStates !=null) changedStates.Add(new CInstanceChagedState() { OP = ChangedState.Operation.Create, Target = newInstance, ChangedProperties = null });

            return newInstance;
        }

        public DomainClassLCBase(InstanceRepository instanceRepository, Logger logger, bool synchronousMode)
        {
            this.instanceRepository = instanceRepository;
            this.logger = logger;
        }
        protected string attr_CustomerId;
        protected bool stateof_CustomerId = false;

        protected string attr_RoomId;
        protected bool stateof_RoomId = false;

        protected string attr_ContructNumber;
        protected bool stateof_ContructNumber = false;

        public string Attr_CustomerId { get { return attr_CustomerId; } }
        public string Attr_RoomId { get { return attr_RoomId; } }
        public string Attr_ContructNumber { get { return attr_ContructNumber; } set { attr_ContructNumber = value; stateof_ContructNumber = true; } }


        // This method can be used as compare predicattion when calling InstanceRepository's SelectInstances method. 
        public static bool Compare(DomainClassLC instance, IDictionary<string, object> conditionPropertyValues)
        {
            bool result = true;
            foreach (var propertyName in conditionPropertyValues.Keys)
            {
                switch (propertyName)
                {
                    case "CustomerId":
                        if ((string)conditionPropertyValues[propertyName] != instance.Attr_CustomerId)
                        {
                            result = false;
                        }
                        break;
                    case "RoomId":
                        if ((string)conditionPropertyValues[propertyName] != instance.Attr_RoomId)
                        {
                            result = false;
                        }
                        break;
                    case "ContructNumber":
                        if ((string)conditionPropertyValues[propertyName] != instance.Attr_ContructNumber)
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
        protected LinkedInstance relR8CS;
        // private DomainClassCS relR8CS;
        protected LinkedInstance relR8R;
        // private DomainClassR relR8R;
        public bool LinkR8(DomainClassCS oneInstance, DomainClassR otherInstance, IList<ChangedState> changedStates=null)
        {
            bool result = false;
            if (relR8CS == null && relR8R == null)
            {
                this.attr_CustomerId = oneInstance.Attr_CustomerId;
                this.stateof_CustomerId = true;
                this.attr_RoomId = otherInstance.Attr_RoomId;
                this.stateof_RoomId = true;

                if (logger != null) logger.LogInfo($"@{DateTime.Now.ToString("yyyyMMddHHmmss.fff")}:LC(CustomerId={this.Attr_CustomerId},RoomId={this.Attr_RoomId}):link[One(CS(CustomerId={oneInstance.Attr_CustomerId})),Other(R(RoomId={otherInstance.Attr_RoomId}))]");

                result = (LinkedR8One()!=null) && (LinkedR8Other()!=null);
                if (result)
                {
                    if (changedStates != null)
                    {
                        changedStates.Add(new CLinkChangedState() { OP = ChangedState.Operation.Create, Target = relR8CS });
                        changedStates.Add(new CLinkChangedState() { OP = ChangedState.Operation.Create, Target = relR8R });
                    }
                }
            }
            return result;
        }
        
        public bool UnlinkR8(DomainClassCS oneInstance, DomainClassR otherInstance, IList<ChangedState> changedStates=null)
        {
            bool result = false;
            if (relR8CS != null && relR8R != null)
            {
                if ((this.Attr_CustomerId==oneInstance.Attr_CustomerId) && (this.Attr_RoomId==otherInstance.Attr_RoomId))
                {
                    if (changedStates != null)
                    {
                        changedStates.Add(new CLinkChangedState() { OP = ChangedState.Operation.Delete, Target = relR8CS });
                        changedStates.Add(new CLinkChangedState() { OP = ChangedState.Operation.Delete, Target = relR8R });
                    }
        
                    this.attr_CustomerId = null;
                    this.stateof_CustomerId = true;
                    this.attr_RoomId = null;
                    this.stateof_RoomId = true;
                    relR8CS = null;
                    relR8R = null;

                if (logger != null) logger.LogInfo($"@{DateTime.Now.ToString("yyyyMMddHHmmss.fff")}:LC(CustomerId={this.Attr_CustomerId},RoomId={this.Attr_RoomId}):unlink[CS(CustomerId={oneInstance.Attr_CustomerId})]");

                    result = true;
                }
            }
            return result;
        }
        
        public DomainClassCS LinkedR8One()
        {
            if (relR8CS == null)
            {
                var candidates = instanceRepository.GetDomainInstances("CS").Where(inst=>(this.Attr_CustomerId==((DomainClassCS)inst).Attr_CustomerId));
                if (candidates.Count() == 0)
                {
                   if (instanceRepository.ExternalStorageAdaptor != null) candidates = instanceRepository.ExternalStorageAdaptor.CheckTraverseStatus(DomainName, this, "CS", "R8_", candidates, () => { return DomainClassCSBase.CreateInstance(instanceRepository, logger); }, "any").Result;
                }
                relR8CS = new LinkedInstance() { Source = this, Destination = candidates.FirstOrDefault(), RelationshipID = "R8", Phrase = "" };
                // (DomainClassCS)candidates.FirstOrDefault();
            }
            return relR8CS.GetDestination<DomainClassCS>();
        }
        
        public DomainClassR LinkedR8Other()
        {
            if (relR8R == null)
            {
                var candidates = instanceRepository.GetDomainInstances("R").Where(inst=>(this.Attr_RoomId==((DomainClassR)inst).Attr_RoomId));
                if (candidates.Count() == 0)
                {
                   if (instanceRepository.ExternalStorageAdaptor != null) candidates = instanceRepository.ExternalStorageAdaptor.CheckTraverseStatus(DomainName, this, "R", "R8_", candidates, () => { return DomainClassRBase.CreateInstance(instanceRepository, logger); }, "any").Result;
                }
                relR8R = new LinkedInstance() { Source = this, Destination = candidates.FirstOrDefault(), RelationshipID = "R8", Phrase = "" };
                // (DomainClassR)candidates.FirstOrDefault();
            }
            return relR8R.GetDestination<DomainClassR>();
        }



        
        public bool Validate()
        {
            bool isValid = true;
            if (relR8CS == null)
            {
                isValid = false;
            }
            if (relR8R == null)
            {
                isValid = false;
            }
            return isValid;
        }

        public void DeleteInstance(IList<ChangedState> changedStates=null)
        {
            if (logger != null) logger.LogInfo($"@{DateTime.Now.ToString("yyyyMMddHHmmss.fff")}:LC(CustomerId={this.Attr_CustomerId},RoomId={this.Attr_RoomId}):delete");

            changedStates.Add(new CInstanceChagedState() { OP = ChangedState.Operation.Delete, Target = this, ChangedProperties = null });

            instanceRepository.Delete(this);
        }

        // methods for storage
        public void Restore(IDictionary<string, object> propertyValues)
        {
            if (propertyValues.ContainsKey("CustomerId"))
            {
                attr_CustomerId = (string)propertyValues["CustomerId"];
            }
            stateof_CustomerId = false;
            if (propertyValues.ContainsKey("RoomId"))
            {
                attr_RoomId = (string)propertyValues["RoomId"];
            }
            stateof_RoomId = false;
            if (propertyValues.ContainsKey("ContructNumber"))
            {
                attr_ContructNumber = (string)propertyValues["ContructNumber"];
            }
            stateof_ContructNumber = false;
        }
        
        public IDictionary<string, object> ChangedProperties()
        {
            var results = new Dictionary<string, object>();
            if (stateof_CustomerId)
            {
                results.Add("CustomerId", attr_CustomerId);
                stateof_CustomerId = false;
            }
            if (stateof_RoomId)
            {
                results.Add("RoomId", attr_RoomId);
                stateof_RoomId = false;
            }
            if (stateof_ContructNumber)
            {
                results.Add("ContructNumber", attr_ContructNumber);
                stateof_ContructNumber = false;
            }

            return results;
        }

        public string GetIdentities()
        {
            string identities = $"CustomerId={this.Attr_CustomerId},RoomId={this.Attr_RoomId}";

            return identities;
        }
        
        public IDictionary<string, object> GetProperties(bool onlyIdentity)
        {
            var results = new Dictionary<string, object>();

            if (!onlyIdentity) results.Add("CustomerId", attr_CustomerId);
            if (!onlyIdentity) results.Add("RoomId", attr_RoomId);
            results.Add("ContructNumber", attr_ContructNumber);

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
