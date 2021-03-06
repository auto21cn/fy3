#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("宗王师",({"zong wangshi","zong"}));
    set("gender","男性");
    set("age",27);
    set("long","一身锦袍,越发显得潇洒风流,据说武功在年轻一
    辈中,可称翘楚。\n");
    set("title",RED"幽冥山庄少宗主"NOR);
    set("combat_exp",1000000);
    set("kee",1000);
    set("max_kee",1000);
    set("force",1000);
    set("max_force",1000);
    set("force_factor",25);
    set("food",200);
    set("water",200);
    
    set("inquiry",([
    "幽冥山庄":"自从二十年前被各大门派围攻,我爹就躲到了此处?\n",
    "道心种魔大法":"我门中无上大法，可惜早几代就失传了.\n",
    ]));
        set("shen_type",-1);
    
    set("chat_chance",3);
    set("chat_msg",({
    CYN"我教中人才凋零,看来要多招人手才行.\n"NOR,
    CYN"听说我教中还有位长老,不过我也从没见过.\n"NOR,
    CYN"这大屋修建得还算不错,任谁也想不到机关在池塘底下。\n"NOR,
    }));
    
    set_skill("dodge",100);
    set_skill("parry",100);
    set_skill("unarmed",100);
    set_skill("force",100);
    set_skill("literate",60);
    set_skill("guiyingmizong",100);
    set_skill("jiuyou-xinfa",100);
    set_skill("youming-zhang",100);
    
    map_skill("dodge","guiyingmizong");
    map_skill("unarmed","youming-zhang");
    map_skill("parry","youming-zhang");
    map_skill("force","jiuyou-xinfa");
    
create_family(RED"幽冥山庄"NOR,5,"少宗主");    
    setup();
    add_money("gold",1);
 }
void attempt_apprentice(object ob)
{
  if (ob->query("mingwang")>0)   {
  	command("say 像你这种正道中人,怎能诚心加入我幽冥山庄?\n");
  	return;
      }
command("recruit "+ob->query("id"));
  return;
 }
  
