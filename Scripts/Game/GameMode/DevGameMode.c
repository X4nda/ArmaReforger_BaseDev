class DevGameModeClass: SCR_BaseGameModeClass {
};


class DevGameMode: SCR_BaseGameMode {
	
	protected bool m_GatherHintShown = false;
	
	override protected void EOnInit(IEntity owner) {
		super.EOnInit(owner);
		
		if(!System.IsConsoleApp())
		{
			Event_OnControllableSpawned.Insert(OnPlayerSpawnedClient);
		}
	}
	
	
	static DevGameMode GetInstance() {
		return DevGameMode.Cast(GetGame().GetGameMode());
	}

	
	void OnPlayerSpawnedClient(IEntity entity) {
		
		GetGame().GetCallqueue().CallLater(ShowGamemodeHint, 5000);
	}
	
	
	void ShowGamemodeHint() {
		SCR_HintManagerComponent.GetInstance().ShowCustomHint("Dev", "GameMode", 20.0);
	}
	
}
