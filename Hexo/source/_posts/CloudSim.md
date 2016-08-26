title: CloudSim Introduction 
layout: post  
date: 5/17/2016 8:52:18 PM  
comments: true  
categories: Technical  
tags: Cloud Computing, CloudSim 
description: 云计算仿真平台CloudSim软件的介绍和使用，主要基于IaaS的资源调度的仿真，自己之前摸索了一段时间，也算有点收获。  

---
#  一. CloudSim介绍 #
　　2009年4月8日，澳大利亚墨尔本大学的网格实验室和Gridbus项目宣布推出云计算仿真软件，称为CloudSim。它是在离散事件模拟包SimJava上开发的函数库，可在Windows和Linux系统上跨平台运行，CloudSim继承了GridSim的编程模型，支持云计算的研究和开发，并提供了以下新的特点：  
⑴. 支持大规模的云计算环境的模拟与仿真，包括数据中心，单一物理计算节点；  
⑵. 为模拟云、服务代理、供应、分配策略提供独立的平台；  
⑶. 支持在模拟系统元素间仿真网络连接；  
⑷. 具有在联合的云环境下仿真的功能，私有和公共领域的混合网络资源，对有关Cloud-Bursts 和自动应用伸缩的关键功能的研究。  
　　CloudSim 是在GridSim 模型基础上发展而来，提供了云计算的特性，支持云计算的资源管理和调度模拟。云计算与网格计算的一个显著区别是云计算采用了成熟的虚拟化技术，将数据中心的资源虚拟化为资源池，打包对外向用户提供服务，CloudSim 体现了此特点，扩展部分实现了一系列接口，提供基于数据中心的虚拟化技术、虚拟化云的建模和仿真功能。通常，数据中心的一台主机的资源可以根据用户的需求映射到多台虚拟机上，因此，虚拟机之间存在对主机资源的竞争关系。CloudSim 提供了资源的监测、主机到虚拟机的映射功能。CloudSim的CIS（Cloud Information Service）和DataCenterBroker 实现资源发现和信息交互，是模拟调度的核心。用户自行开发的调度算法可在DataCenterBroker 的方法中实现，从而实现调度算法的模拟。

---
# 二. CloudSim 详细介绍 #
## CloudSim 的几个核心类 ##
1. Cloudlet类：构建云环境下的任务。  
2. DataCenter类：数据中心，提供虚拟化的网格资源，处理虚拟机信息的查询，包含虚拟机对资源的分配策略，云计算采用VMProvisioner处理虚拟机。  
3. DataCenterBroker类：隐藏了虚拟机的管理，如创建、任务提交、虚拟机的销毁等。  
4. Host类：扩展了机器对虚拟机除处理单元(PE)之外的参数分配策略，如带宽、存储空间、内存等，一台Host可对应多台虚拟机。  
5. VirtualMachine类：虚拟机类，运行在Host上，与其它虚拟机共享资源，每台虚拟机由一个拥有者所有，可提交任务，并由VMScheduler类定制该虚拟机的调度策略。  
6. VMScheduler类：虚拟机的调度策略，用来管理执行任务，实现了任务接口。  
7. VMCharacteristics类：提供虚拟机描述。  
8. VMMAllocationPolicy类：虚拟机监视器策略类，描述同一Host上的多台虚拟机共享资源的策略。  
9. VMProvisioner类：实现数据中心的主机到虚拟机的映射。  

## 2.1 CloudSim体系结构 ##
　　在体系结构上，CloudSim仿真器采用分层的结构，自底向上由SimJava，GridSim，CloudSim，用户代码四个层次组成。  
![image](/images/2016/05/CloudSim_Architecture.jpg)   
### 2.1.1 SimJava###
　　最底层的是离散事件模拟引擎SimJava，它负责执行高层模拟框架的核心功能，比如：查询和处理事件，系统组件的创建(服务、客户端、数据中心、代理和虚拟机)，在不同组件之间的通信，模拟时钟的管理。
### 2.1.2GridSim###
　　在SimJava上面是GridSim，支持高层软件组件，建模多个网格基础设施，包括网络和网络流量文件，基础的网格组件诸如资源，数据集，负载 测量和信息服务。
### 2.1.3CloudSim###
　　CloudSim在下一层执行，它扩展由GridSim提供的核心功能。CloudSim层提供对虚拟基于云的数据中心诸如VM，内存，存储和带宽等管理接口。CloudSim层在模拟阶段管理核心实体(比如VM，客户端，数据中心，应用)的实例和执行。这一层能够并发地实例化和透明地管理大规模云基础设施包括数以千计的系统组件。    

## 2.2 CloudSim的技术实现##
CloudSim 云模拟器的类设计图如下所示：  
![](/images/2016/05/CloudSim_Class.jpg)  
主要类的功能描述如下：  
### 2.2.1 BwProvisioner###
　　这个抽象类用于模拟虚拟机的带宽分配策略。云系统开发和研究人员可以通过这个类反映其应用需求的变化，实现自己的策略（基于优先级或服务质量）。BwProvisionerSimple允许虚拟机保留尽可能多的带宽。
### 2.2.2 CLoudCoordinator###
　　这个抽象类整合了云数据中心，负责周期性地监控数据中心的内部状态和执行动态负载均衡决策。这个组件的具体实现包括专门的传感器和负载均衡过程中需要遵循的策略。updateDatacenter()方法通过查询传感器实现监控数据中心资源。SetDatacenter()抽象方法实现了服务/资源的发现机制，这个方法可以被扩展实现自定义的协议及发现机制(多播、广播和点对点)。此外，还能扩展该组件模拟如Amazon EC2 Load-Balacer的云服务。对于想要在多个云环境下部署的开发人员，可以扩展这个类来实现自己的云间调度策略。
### 2.2.3 Cloudlet###
　　模拟了云应用服务（如内容分发、社区网络和业务工作流等）。每一个应用服务都会拥有一个预分配的指令长度和其生命周期内所需的数据传输开销
### 2.2.4 CloudletScheduler ###
　　扩展实现了多种策略，用于决定虚拟机内的应用服务如何共享处理器能力。支持两种调度策略：空间共享（CloudletSchedulerSpaceShared）和时间共享（CloudletSchedulerTimeShared）策略   
### 2.2.5 Datacenter###
　　模拟了云提供商提供的核心基础设施级服务（硬件）。它封装了一系列的主机，且这些主机都支持同构和异构的资源（内存、内核、容量和存储）配置 
### 2.2.6 DatacenterBroker###
　　模拟了一个代理，负责根据服务质量需求协调SaaS提供商和云提供商。该代理代表SaaS提供商，它通过查询云信息服务（Cloud Information Service）找到合适的云服务提供者，并根据服务质量的需求在线协商资源和服务的分配策略 
### 2.2.7 DatacenterCharacteristics###
　　包含了数据中心资源的配置信息
### 2.2.8 Host###
　　模拟如计算机、存储服务器等物理资源。它封装了一些重要信息，如内存/存储器的容量、处理器内核列表及类型（多核机器）、虚拟机之间共享处理能力的分配策略、为虚拟机分配内存和带宽的策略等
### 2.2.9 NetworkTopology###
　　包含模拟网络行为（延时）的信息。它里面保存了网络拓扑信息，该信息由BRITE拓扑生成器生成
### 2.2.10 RamProvisioner ###
　　代表为虚拟机分配主存的策略
### 2.2.11 SanStorage ###
　　模拟了云数据中心的存储区域网，主要用于存储大量数据，类似于Amazon S3、Azure blob storage等  
### 2.2.12 Sensor###
　　该接口的实现必须通过实例化一个能够被云协调器使用的传感器组件，用于监控特定的性能参数（能量消耗、资源利用）。该接口定义了如下方法：
1. 为性能参数设置最小值和最大值。
2. 周期性地更新测量值。
3. 该类能够用于模拟由主流云提供商提供的真实服务 

### 2.2.13 Vm###
　　模拟由主机组件托管和管理的虚拟机 
### 2.2.14 VmAllocationPolicy###
　　代表虚拟机监视器使用的调度策略，该策略用于将虚拟机分配给主机 
### 2.2.15 VmSheduler###
　　由一个主机组件实现，模拟为虚拟机分配处理核所用的策略（空间共享和时间共享） 

---
# 三. CloudSim 源码分析#
## 3.1 CloudSim仿真的一般步骤##
1.初始化CloudSim 库   

    CloudSim.init(num_user, calendar, trace_flag);
2.创建数据中心，在CloudSim 仿真平台中，一个数据中心由一个或多个Machine 组成，一个Machine 是由一个或多个PEs 或CPUs 组成。

    Datacenter datacenter0 = createDatacenter("Datacenter_0");
3.创建代理Broker

    DatacenterBroker broker = createBroker();
    int brokerId = broker.getId();
4.创建虚拟机

    vmlist = new ArrayList<Vm>();
    //VM 描述参数
    int vmid = 0;
    int mips = 250;
    long size = 10000;
    int ram = 512;
    long bw = 1000;
    int pesNumber = 1;
    String vmm = "Xen";
    //创建时为虚拟机指定Broker
    Vm vm1 = new Vm(vmid, brokerId, mips, pesNumber, ram, bw, size,
    vmm, new CloudletSchedulerTimeShared());
    //将虚拟机加入虚拟机列表
    vmlist.add(vm1);
    //向相应代理Broker 提交虚拟机列表
    broker.submitVmList(vmlist);
5.创建云任务

    cloudletList = new ArrayList<Cloudlet>();
    //创建时指定任务的用户ID,BrokerID
    //Cloudlet 描述参数
    int id = 0;
    pesNumber=1;
    long length = 250000;
    long fileSize = 300;
    long outputSize = 300;
    UtilizationModel utilizationModel =new
    UtilizationModelFull();
    Cloudlet cloudlet1 = new Cloudlet(id, length, pesNumber,fileSize, outputSize, utilizationModel,utilizationModel,utilizationModel);
    cloudlet1.setUserId(brokerId);
    ……
    //将任务加入任务列表
    cloudletList.add(cloudlet1);
    ……
    //向代理Broker提交任务列表
    broker.submitCloudletList(cloudletList);
6.启动仿真

    CloudSim.startSimulation();
7.在仿真结束后统计结果

    List<Cloudlet> newList = broker.getCloudletReceivedList();
	CloudSim.stopSimulation();
	printCloudletList(newList);
	datacenter0.printDebts();
## 3.2 CloudSim 的扩展##
CloudSim 主要是对真实的云环境的一种模拟仿真，其各个类分别模拟了云计算的资源分配的各个过程，包括虚拟机向物理机的分配过程，计算任务向虚拟机的分配过程等等，这些分配策略分别在不同的class中进行了描述。由于CloudSim 只是搭建了一个云数据中心的框架，因此具体的分配策略需要我们自己去实现，也就需要去在相应的Class中添加自己的策略函数。  
在CloudSim 给的examples中，给运任务分配虚拟机的时候，使用的函数为`broker.bindCloudletToVm(cloudlet1.getCloudletId(),vm1.getId());`,我们可以跟进去发现，该函数是在`DatacenterBroker.java`中，该函数使用的是直接绑定的策略，即程序中指定了云任务和虚拟机的绑定方式，如果我们需要使用自己的分配策略，就得在`DatacenterBroker.java`中添加自己的分配策略函数。  
下面分别使用两种分配策略对云任务进行分配虚拟机，分别为顺序分配策略和贪心分配策略：  
### 顺序分配策略###
在DatacenterBroker 类中实现方法bindCloudletsToVmsSimple()：用于把一组任务顺序分配给一组虚拟机，当所有的虚拟机都运行有任务后，再从第一个虚拟机开始重头分配任务。
    
    public void bindCloudletsToVmsSimple() {
    		int vmNum = vmList.size();
    		int cloudletNum = cloudletList.size();
    		int idx = 0;
    		for (int i = 0; i < cloudletNum; i++) {
    			cloudletList.get(i).setVmId(vmList.get(idx).getId());
    			idx = (idx + 1) % vmNum;
    		}
    	}
### 贪心策略 ###
在DatacenterBroker 类中实现方法bindCloudletsToVmsTimeAwared()：
定义一个矩阵time[i][j]，表示任务i 在虚拟机j 上所需的执行时间。在初始化矩阵time 前，首先将任务按MI 的大小降序排序，将虚拟机按MIPS 的大小升序排列。  
从矩阵中行号为0 的任务开始，每次都尝试分配给最后一列对应的虚拟机，如果该选择相对于其他选择是最优的，就完成分配，否则将任务分配给使当前结果最优的虚拟机。同时，如果有多种分配方法都能使当前结果最优，则将任务分配给运行任务最少的虚拟机。

    public void bindCloudletsToVmsTimeAwared() {
    		int cloudletNum = cloudletList.size();
    		int vmNum = vmList.size();
    		// time[i][j] 表示任务i在虚拟机j上的执行时间
    		double[][] time = new double[cloudletNum][vmNum];
    		// cloudletList按MI降序排列, vm按MIPS升序排列
    		Collections.sort(cloudletList, new CloudletComparator());
    		Collections.sort(vmList, new VmComparator());
    		// ////////For test//////////////////////////////////
    		System.out.println("///////////For test///////////////");
    		for (int i = 0; i < cloudletNum; i++) {
    			System.out.print(cloudletList.get(i).getCloudletId() + ":"
    					+ cloudletList.get(i).getCloudletLength() + " ");
    		}
    		System.out.println();
    		for (int i = 0; i < vmNum; i++) {
    			System.out.print(vmList.get(i).getId() + ":"
    					+ vmList.get(i).getMips() + " ");
    		}
    		System.out.println();
    		System.out.println("//////////////////////////////////");
    		// ////////////////////////////////////////////////////////////////////
    		for (int i = 0; i < cloudletNum; i++) {
    			for (int j = 0; j < vmNum; j++) {
    				time[i][j] = (double) cloudletList.get(i).getCloudletLength()
    						/ vmList.get(j).getMips();
    				System.out.print("time[" + i + "][" + j + "]=" + time[i][j]
    						+ " ");
    				// For test
    			}
    			System.out.println(); // For test
    		}
    		double[] vmLoad = new double[vmNum];// 在某个虚拟机上任务的总执行时间
    		int[] vmTasks = new int[vmNum]; // 在某个Vm上运行的任务数量
    		double minLoad = 0;// 记录当前任务分配方式的最优值
    		int idx = 0;// 记录当前任务最优分配方式对应的虚拟机列号
    		// 第一个cloudlet分配给最快的vm
    		vmLoad[vmNum - 1] = time[0][vmNum - 1];
    		vmTasks[vmNum - 1] = 1;
    		cloudletList.get(0).setVmId(vmList.get(vmNum - 1).getId());
    		for (int i = 1; i < cloudletNum; i++) {
    			minLoad = vmLoad[vmNum - 1] + time[i][vmNum - 1];
    			idx = vmNum - 1;
    			for (int j = vmNum - 2; j >= 0; j--) {
    				// 如果当前虚拟机未分配任务，则比较完当前任务分配给该虚拟机是否最优
    				if (vmLoad[j] == 0) {
    					if (minLoad >= time[i][j])
    						idx = j;
    					break;
    				}
    				if (minLoad > vmLoad[j] + time[i][j]) {
    					minLoad = vmLoad[j] + time[i][j];
    					idx = j;
    				}
    				// 简单的负载均衡
    				else if (minLoad == vmLoad[j] + time[i][j]
    						&& vmTasks[j] < vmTasks[idx])
    					idx = j;
    			}
    			vmLoad[idx] += time[i][idx];
    			vmTasks[idx]++;
    			cloudletList.get(i).setVmId(vmList.get(idx).getId());
    			System.out.print(i + "th " + "vmLoad[" + idx + "]=" + vmLoad[idx]
    					+ "minLoad=" + minLoad);
    			System.out.println();
    		}
    	}
写完两个分配策略函数，后面可以写一个测试函数，分别对这两种分配策略进行仿真实验，并进行对比。  
在org.cloudbus.cloudsim.examples中，写一个自己的MyAllocationTest类，其源码为：

    public class MyAllocationTest {
    
    	/** The cloudlet list. */
    	private static List<Cloudlet> cloudletList;
    	private static int cloudletNum = 10;
    	
    	/** The vmlist. */
    	private static List<Vm> vmlist;
    	private static int vmNum = 5;
    	
    	/**
    	* Creates main() to run this example
    	*/
    	public static void main(String[] args) {
    		
    		Log.printLine("Starting TestAllocation...");
    		try {
    			// First step: Initialize the CloudSim package. It should be called
    			// before creating any entities.
    			int num_user = 1; // number of cloud users
    			Calendar calendar = Calendar.getInstance();
    			boolean trace_flag = false; // mean trace events
    			
    			// Initialize the CloudSim library
    			CloudSim.init(num_user, calendar, trace_flag);
    			
    			// Second step: Create Datacenters
    			/*
    			 * Datacenters are the resource providers in CloudSim. We need at list one of
    			 *  them to run a CloudSim simulation
    			 */
    			Datacenter datacenter0 = createDatacenter("Datacenter_0");
    			
    			//Third step: Create Broker
    			DatacenterBroker broker = createBroker();
    			int brokerId = broker.getId();
    			
    			//VM description
    			int vmid = 0;
    			int[] mipss = new int[]{278,289,132,209,286};
    			long size = 10000;
    			int ram = 256;
    			long bw = 1000;
    			int pesNumber = 1;
    			String vmm = "Xen";
    			
    			//Fourth step: Create one virtual machine
    			vmlist = new ArrayList<Vm>();
    			for(int i=0;i<vmNum;i++){
    				vmlist.add(new Vm(vmid,brokerId,mipss[i],pesNumber,
    						ram,bw,size,vmm,new CloudletSchedulerSpaceShared()));
    				vmid++;
    			}
    			
    			//submit vm list to the broker
    			broker.submitVmList(vmlist);
    			
    			//Cloudlet properties
    			int id = 0;
    			long[] lengths = new long[]{19365,49809,32018,44157,16754,
    										18336,20045,31493,30727,31017};
    			long fileSize = 300;
    			long outputSize = 300;
    			UtilizationModel utilizationModel = new UtilizationModelFull();
    			
    			//Fifth step: Create two Cloudlets
    			cloudletList = new ArrayList<Cloudlet>();
    			for(int i = 0;i < cloudletNum;i++){
    				Cloudlet cloudlet = new Cloudlet(id,lengths[i],pesNumber,fileSize,
    									outputSize,utilizationModel,utilizationModel,utilizationModel);
    				//add the cloudlets to the list
    				cloudlet.setUserId(brokerId);
    				cloudletList.add(cloudlet);
    				id++;
    			}
    			
    			//submit cloudlet list to the broker
    			broker.submitCloudletList(cloudletList);
    			
    			//bind the cloudlets to the vms. This way, the broker
    			// will submit the bound cloudlets only to the specific VM
    			broker.bindCloudletsToVmsSimple();
    			//broker.bindCloudletsToVmsTimeAwared();
    			
    			// Sixth step: Starts the simulation
    			CloudSim.startSimulation();
    			
    			// Final step: Print results when simulation is over
    			List<Cloudlet> newList = broker.getCloudletReceivedList();
    			CloudSim.stopSimulation();
    			printCloudletList(newList);
    			
    			//Print the debt of each user to each datacenter
    			//datacenter0;
    			Log.printLine("TestAllocation finished!");
    		}
    		catch (Exception e) {
    			e.printStackTrace();
    			Log.printLine("Unwanted errors happen");
    		}	
    	}
    	
    	/**
    	 * 
    	 * @Title: createDatacenter
    	 * @Description: TODO
    	 * @param: @param name
    	 * @param: @return
    	 * @return: Datacenter
    	 * @Date: May 17, 20167:16:32 PM
    	 */
    	private static Datacenter createDatacenter(String name){
    		// Here are the steps needed to create a PowerDatacenter:
    		
    		// 1. We need to create a list to store
    		// our machine
    		List<Host> hostList = new ArrayList<Host>();
    		// PE and its properties
    		int mips = 1000;
    		int hostId=0;
    		int ram = 2048; //host memory (MB)
    		long storage = 1000000; //host storage
    		int bw = 10000;
    		
    		// 2. A Machine contains one or more PEs or CPUs/Cores.
    		List<Pe> peList = new ArrayList<Pe>();
    		
    		// 3. Create PEs and add these into a list.
    		peList.add(new Pe(0, new PeProvisionerSimple(mips))); 
    		// need to store Pe id and MIPS Rating
    		
    		//4. Create Host with its id and list of PEs and add them to the list of machines
    		hostList.add( new Host(
    				hostId,
    				new RamProvisionerSimple(ram),
    				new BwProvisionerSimple(bw),
    				storage,
    				peList,
    				new VmSchedulerTimeShared(peList)
    				)
    		); // This is our machine
    		
    		// 5. Create a DatacenterCharacteristics object that stores the
    		// properties of a data center: architecture, OS, list of
    		// Machines, allocation policy: time- or space-shared, time zone
    		// and its price (G$/Pe time unit).
    		
    		String arch = "x86"; // system architecture
    		String os = "Linux"; // operating system
    		String vmm = "Xen";
    		double time_zone = 10.0; // time zone this resource located
    		double cost = 3.0; // the cost of using processing in this resource
    		double costPerMem = 0.05; // the cost of using memory in this resource
    		double costPerStorage = 0.001; // the cost of using storage in this resource
    		double costPerBw = 0.0; // the cost of using bw in this resource
    		LinkedList<Storage> storageList = new LinkedList<Storage>(); //we are not adding SAN devices by now
    		//创建数据中心特征对象
    		DatacenterCharacteristics characteristics = new DatacenterCharacteristics( arch, os, vmm, 
    				hostList, time_zone, cost, costPerMem, costPerStorage, costPerBw);
    		
    		// 6. Finally, we need to create a PowerDatacenter object.
    		Datacenter datacenter = null;
    		try {
    			datacenter = new Datacenter(name, characteristics,
    					new VmAllocationPolicySimple(hostList), storageList, 0);
    		} catch (Exception e) {
    			e.printStackTrace();
    		}
    		return datacenter;
    	}
    	
    	/*
    	 * We strongly encourage users to develop their own broker policies, to submit vms and cloudlets 
    	 * according to the specific rules of the simulated scenario
    	 */
    
    	/**
    	 * 
    	 * @Title: createBroker
    	 * @Description: TODO
    	 * @param: @return
    	 * @return: DatacenterBroker
    	 * @Date: May 17, 20167:17:32 PM
    	 */
    	private static DatacenterBroker createBroker() {
    		DatacenterBroker broker = null;
    		try {
    			broker = new DatacenterBroker("Broker");
    		} catch (Exception e) {
    			e.printStackTrace();
    			return null;
    		}
    		return broker;
    	}
    	
    	private static void printCloudletList(List<Cloudlet> list) {
    		int size = list.size();
    		Cloudlet cloudlet;
    		String indent = " ";
    		Log.printLine();
    		Log.printLine("========== OUTPUT ==========");
    		Log.printLine("CloudletID" + indent + "STATUS" + indent +
    						"DatacenterID" + indent + "VMID" + indent +
    						"Time" + indent + "StartTime" + indent + "FinishTime");
    		DecimalFormat dft = new DecimalFormat("###.##");
    		for (int i = 0; i < size; i++) 
    		{
    			cloudlet = list.get(i);
    			Log.print(indent + cloudlet.getCloudletId() + indent + indent);
    			if (cloudlet.getCloudletStatus() == Cloudlet.SUCCESS)
    			{
    				Log.print("SUCCESS");
    				Log.printLine( indent + indent + cloudlet.getResourceId() +
    								indent + indent + indent + cloudlet.getVmId() + indent + indent +
    								dft.format(cloudlet.getActualCPUTime()) + indent + indent +
    								dft.format(cloudlet.getExecStartTime())+ indent + indent +
    								dft.format(cloudlet.getFinishTime()));
    			}
    		}
    	}
    }
在主函数中，分别调用函数`broker.bindCloudletsToVmsSimple()`和`broker.bindCloudletsToVmsTimeAwared()`，表示分别启动顺序分配策略和贪心策略，其运行结果分别为：
![](/images/2016/05/Run_Result1.jpg)  
![](/images/2016/05/Run_Result2.jpg)