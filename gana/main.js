class character {
	constructor()
	{
		this.rom = "";
		this.hir = "";
	}
	setRom(character){
		this.rom = character;
		this.hir = wanakana.toHiragana(character);
	}
}

var test = {
		task: {
			rom: "",
			set: function(task){
				this.rom = wanakana.toRomaji(task);
				$("#task span").html(task);
			},
			get: function(){
				return this.rom;
			},
			create: function(length){
				var task ="";
				for(var i = 0; i < 5; i++){
					var index = Math.floor(Math.random()*Object.keys(wanakana.R_to_J).length+1);
					var key = Object.keys(wanakana.R_to_J)[index];
					task += wanakana.R_to_J[key];	
				}
				return task;
			}
		},
		solution: {
			evaluate: function(){
				if(test.task.rom == wanakana.toRomaji(this.get())){
					return true;
				} else {
					return false;
				}
			},
			get: function(){
				return $("#solution input[name=solution]").val();
			},
			set: function(text){
				$("#solution input[name=solution]").val(text);
			},
		},
}

$(function(){
	test.task.set(test.task.create(5));
	$("body").on("keydown",function(e){
		if(e.which == 13){
			if(test.solution.evaluate()){
				console.log("correct");
			} else {
				console.log("wrong");
				console.log(test.solution.get());
				console.log(test.task.get());
			}
		}
	});
	$("#solution input[name=instaconvert]").on("change",function(){
		if($("#solution input[name=instaconvert]").is(":checked")){
			test.solution.set(wanakana.toHiragana(test.solution.get()));
			wanakana.bind(document.getElementById("inputText"));
		} else {
			test.solution.set(wanakana.toRomaji(test.solution.get()));
			wanakana.unbind(document.getElementById("inputText"));
		}
		
	});
});