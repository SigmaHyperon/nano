var coreStats = ["Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"];
var extendedStats = ["Armor", "Dodgechance", "Initiative", "Hitchance", "Damage", "Blockchance", "Resistance", "Reflex", "Willpower"];
var charStats = ["Hitpoints", "Magicpoints"];
var abilitiesCommon = ["Sense Motive", "Balance", "Diplomacy", "Intimidate", "Listen", "Climb", "Ride", "Roll", "Appraise", "Sneak", "Swim", "Spot", "Jump", "Search", "Dress up", "Survivability instincts", "Hide"];

class characterSheet{
	constructor() {
		this.data = new charSheetData();
		this.name = "test char";
	}
}

class charSheetData{
	constructor() {
		this.coreStats = [];
		this.extendedStats = [];
		this.charStats = [];
		this.abilities = new abilities();
		this.level = 0;
		
		for(var i = 0; i < coreStats.length; i++){
			this.coreStats[i] = new stat();
			this.coreStats[i].name = coreStats[i];
			this.coreStats[i].type = "coreStat";
		}
		for(var i = 0; i < extendedStats.length; i++){
			this.extendedStats[i] = new stat();
			this.extendedStats[i].name = extendedStats[i];
			this.extendedStats[i].type = "extendedStat";
		}
		for(var i = 0; i < charStats.length; i++){
			this.charStats[i] = new stat();
			this.charStats[i].name = charStats[i];
			this.charStats[i].type = "charStat";
		}
	}
}

class stat {
	constructor() {
		this.id = 0;
		this.name = "";
		this.type = "";
		this.base = 0;
		this.bonus = 0;
	}
	get total(){
		return this.calcTotal();
	}
	get modifier(){
		return this.calcModifier();
	}
	calcTotal(){
		return this.base + this.bonus;
	}
	calcModifier(){
		return Math.floor((this.total - 10) / 2); 
	}
};

class statScaling extends stat {
	constructor() {
		super();
		this.scalesWith = null;
	}
	get base(){
		if (this.scalesWith != null) {
			return this.scalesWith.modifier;
		} else {
			return 0;
		}
	}
	set base(val){
		
	}
};



class abilities{
	constructor(){
		this.common = [];
		this.special = [];
		
		for(var i = 0; i < abilitiesCommon.length; i++){
			this.common[i] = new statScaling();
			this.common[i].name = abilitiesCommon[i];
			this.common[i].type = "abilityCommon";
		}
	}
}
