inherit NPC;
void create()
{
   set_name("术赤",({"shu chi"}));
   set("gender","男性");
   set("long","铁木真的大儿子,他脸形瘦削,生性险诈!\n");
   set("mingwang",-20000);
   set("combat_exp",700000);
   set("area_name","蒙古草原");
   
set("age",39);
set("kee",1200);
   set("max_kee",1200);
set("food",250);
set("water",250);
   set("force",900);
   set("max_force",900);
   set("force_factor",50);

   set_skill("dodge",120);
   set_skill("force",120);
   set_skill("parry",120);
   set_skill("unarmed",120);
   set_skill("spear",120);
   set("chat_chance",5);
   set("chat_msg",({
"术赤嘿嘿冷笑两声:察合台是个笨蛋,这[汗]的位置迟早是我的.\n",
"术赤举起桌上的金樽,把血色的葡萄酒一饮而尽.\n",
}));

   setup();
   add_money("silver",30);
carry_object("/obj/std/armor/tiejia")->wear();
carry_object("/d/obj/weapon/spear/jinqiang")->wield();
}
void init()
{
        object area;
        area=new("/obj/area");
	area->create(query("area_name"));
        set("banghui",(string)area->query("banghui"));
        destruct(area);
}