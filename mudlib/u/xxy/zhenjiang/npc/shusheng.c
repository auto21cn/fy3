//music yangzhou' 书生

inherit NPC;

void create()
{
	set_name("书生", ({ "shusheng","shu sheng", "sheng" }) );
	set("gender", "男性" );
	set("age", 26);
	set("int", 28);
        set("combat_exp",200);
	set("long",
		"是个久考不中，却又自命不凡的落魄书生。\n");

	set("attitude", "peaceful");
	set_skill("literate", 40);
        set_skill("parry",20);
	setup();
}

