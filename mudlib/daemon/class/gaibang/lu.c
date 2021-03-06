#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string do_yaoqing();
void create()
{
	set_name("鲁有脚", ({"lu youjiao", "lu", "youjiao"}));
	set("nickname", "丐帮九袋长老");
	set("gender", "男性");
	set("age", 45);
	set("long", 
		"鲁有脚虽然武功算不得顶尖高手，可是在江湖上却颇有声望。\n"
		"因为他在丐帮中有仁有义，行事光明磊落，深得洪七公的器重。\n");
	set("attitude", "peaceful");
        set("class", "beggar");
	set("str", 25);
	set("int", 12);
	set("con", 25);
        set("banghui","丐帮");
	set("kee", 900);
	set("max_kee", 900);
        set("shen_type",1);
	set("gin", 100);
	set("max_gin", 100);
	set("force", 1200);
	set("max_force", 1200);
	set("force_factor", 100);
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 90); // 基本内功
	set_skill("huntian-qigong", 90); // 混天气功
	set_skill("unarmed", 95); // 基本拳脚
	set_skill("xianglong-zhang", 90); // 降龙十八掌
	set_skill("dodge", 90); // 基本躲闪
	set_skill("xiaoyaoyou", 90); // 逍遥游
	set_skill("parry", 90); // 基本招架
	set_skill("staff", 85); // 基本棍杖
        set_skill("dagou-bang",90);
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
        map_skill("parry","dagou-bang");
        map_skill("staff","dagou-bang");
	set("inquiry",([
        "加入丐帮":(:do_yaoqing:),
"洪七公":"帮主对杭州楼外楼的糖醋鱼很对胃口,好象一直没走.\n",
        ]));
	
	setup();
	carry_object(__DIR__"obj/zhuzhang")->wield();
	carry_object("/obj/cloth")->wear();
}
void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	string banghui;
	if(!ob || environment(ob)!=environment()) return;
	banghui=(string)ob->query("banghui");
	if(! banghui || banghui!=query("banghui"))
	message_vision("$N对$n嘻嘻一笑道：可是来"+YEL+"加入丐帮"+NOR+"的么?\n",
	this_object(),ob);
	else   {
	  if (!present("mantou",ob))  {
	    new(__DIR__"obj/mantou")->move(ob);
   message_vision("$N偷偷塞给$n一个馒头.\n",this_object(),ob);
         }
          if (!present("shuiwan",ob))  {
            new(__DIR__"obj/shuiwan")->move(ob);
   message_vision("$N拿出一个水碗给$n道:喝口水，兄弟.\n",this_object(),ob);
              }
          return;   
     }	
}                                                                                

string do_yaoqing()
{
	object ob;
	string banghui;
	ob=this_player();
	banghui=(string)ob->query("banghui");
	if(! banghui)	{
		ob->set_temp("oldsix/target",this_object());
		return "你既然有心加入我丐帮，我就为你引介(jiaru lu).";
	}
	else if(banghui !=(string)query("banghui"))	{
		return "你既然入了"+banghui+",又想加入我帮，作卧底啊你!";
	}
	else	return "你已是丐帮弟子，还想从头来过啊.";
}
int recognize_apprentice(object ob)
{
  string banghui;
  banghui=ob->query("banghui");
  if (!banghui||banghui!="丐帮")  
   return notify_fail("鲁有脚摇头道:你并非我丐帮弟子,老化子不能传武功给你.\n");
	if(ob->query("score")<1500)
   return notify_fail("鲁有脚皱眉道:你如能为本帮再作些事情,老化子再考虑吧.\n");
  return 1;
}
   
