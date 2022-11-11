# Tutorial - Generated library from Conceptual Model with Microsoft Azure services

This document describes how to develop <b>Digital Twins & IoT Solution</b> by using <b>Conceptual Modeling</b> for <b>Business scenarios and subject matters</b>. 

The "<b>Conceptual Modeling</b>" is extension of [xtUML](https://xtuml.org/) based modeling techniques for visualizing business, taking into account [my](https://www.linkedin.com/in/hiroshi-ota-009/) [knowledge and experience](https://www.kae-made.jp/).
With the tools and services presented in this document, you can model your business using [BridgePoint](https://github.com/xtuml/bridgepoint), a dedicated conceptual moderling tool, to build not only scalable Digital Twins solution on a cloud but also IoT device application with minimul effort.  
For more information on <b>Conceptual Modeling</b>, please read "[Art of Conceptual Modeling](https://note.com/kae_made/m/m054c9f9f8b61)".

## The big picture of developing solution 
The following services are used to build solution.  
- [Azure IoT Hub](https://learn.microsoft.com/azure/iot-hub/)
- [Azure Digital Twins](https://learn.microsoft.com/azure/digital-twins/)
- [Azure Functions](https://learn.microsoft.com/azure/azure-functions/)
- [Azure Event Hubs](https://learn.microsoft.com/azure/event-hubs/)
- [Azure Event Grid](https://learn.microsoft.com/ja-jp/azure/event-grid/)

The architecture of the solution that can be developed is as follows.  

![solution architecture](./images/architecture-overview.svg)  

- Secure device connectivity and two-way communication with services using <b>Azure IoT Hub</b>
- Current state of conceptual instances and relationship is hold into <b>Azure Digital Twins</b>, which is very compatible with Conceptual Modeling
- Execute behavior based on business scenario and maintain consistency int conceptual world with a <b>C# code library automatically generated from a Conceptual Model</b> created by <b>BridgePoint</b>.

## Overview of build solution process  
Twin Models described by DTDL and most of the logic of Azure Functions and IoT device application relies on artifacts automatically generated from the <b>Conceptual Model</b>.  
The generated parts are shown as follows.  

![process overview](./images/flow-of-development-process.svg)  

The generators shown in the figure are published from the following repositories.  
- DTDL Generator - https://github.com/kae-made/dtdl-schema-generator
- C# Generator - https://github.com/kae-made/domainmodel-code-generator-csharp
- IoT App Generator - https://github.com/kae-made/dtdl-iot-app-generator

All generators are also published as NuGet Packages. You can built-in these generator into your DevOps pipeline.  
All Generators are developed using "<b>Implementation by Translation</b>(This techinique is established in Shlaer-Mellor method and xtUML)".  
For more information on "<b>Implementation by Translation</b>", please read "[Technique of Tranfromation](https://note.com/kae_made/m/md806463fb58a)". 

The solution consists of parts that are automatically generated from your conceptual model and fixed code on Azure Functions that don't depend on idividual conceptual models.  

The name of the Azure Functions are as follows.  

![Name of Azure Functions](./images/name-of-functions.svg)

All Azure Functions are published from Github.  
- ReceiveD2CToTwinGraph - [ReceiveD2CToTwinGraph.cs](https://github.com/kae-made/domain-model-csharp-azure-digital-twins-adaptor/blob/main/AzureDigitalTwinsAdaptorSamples/Kae.DomainMode.Csharp.AzureDigitalTwins.AzureIoTHubBinder/ReceiveD2CToTwinGraph.cs)
    - Completely independent formally of indivisual Conceptual Model
- ReceiveReportedPropertiesToTwinGraph - [ReceiveReportedPropertiesToTwinGraph.cs](https://github.com/kae-made/domain-model-csharp-azure-digital-twins-adaptor/blob/main/AzureDigitalTwinsAdaptorSamples/Kae.DomainMode.Csharp.AzureDigitalTwins.AzureIoTHubBinder/ReceiveReportedPropertiesToTwinGraph.cs)
    - Completely independent formally of indivisual Conceptual Model
- DomainModelExecutor - [DomainModelExecutor.cs](https://github.com/kae-made/domain-model-csharp-azure-digital-twins-adaptor/blob/main/AzureDigitalTwinsAdaptorSamples/AzureDigitalTwinsAdaptorForCsharpFramework/DomainModelExecutor.cs)
    - The code itself is formally independent of individual conceptual models.
    - Run with domain model C# code libary automatically genenerated from conceptual model. 
- TelemetryNotified - [TelemetryNotified.cs](https://github.com/kae-made/domain-model-csharp-azure-digital-twins-adaptor/blob/main/AzureDigitalTwinsAdaptorSamples/AzureDigitalTwinsAdaptorForCsharpFramework/TelemetryNotified.cs)
    - The code itself is formally independent of individual conceptual models.
    - Run with domain model C# code libary automatically genenerated from conceptual model. 

---
## Step by Step.  
This section will explain the procedure step by step.  
### 1. Create Conceptual Model for your business  
First of all, building a conceptual model by BridgePoint based on subject matter and scenarios your business works with.  
To learn how to use BridgePoint, please refere to "[ビジネスをモデル化する ～ BridgePoint を使ってみよう](https://note.com/kae_made/n/n26c1d91e686f)".  
I have released training tutorials to build better modes, please refer to "[概念モデリングチュートリアル集](https://note.com/kae_made/m/m737f9295692f)".  

### 2. Generate Twin Model by DTDL  
