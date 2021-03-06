//Mr.music yangzhou 欧阳修

inherit NPC;
inherit F_MASTER;

int get_again();

void create()
{
        set_name("欧阳修", ({ "ouyangxiu", "ouyang xiu","ouyang" }) );
        set("gender", "男性" );
        set("age", 54);
        set("str", 90);
        set("cor", 90);
        set("cps", 90);
        set("int", 90);
        set("mingwang",1);
        set("max_force", 4000);
        set("force", 3000);
        set("force_factor", 3);

        set("rank_info/respect", "大人");

        set("long","这位就是扬州知府欧扬大人，\n结婚、离婚、补结婚证都有他一手操办。\n");

        create_family("翰林学社", 1, "社长");
        set("title","扬州知府");
        set("combat_exp", 100000);
        set("score", 2000);
        set("inquiry",([
        "结婚":"要年满16才行,和伴侣一起,用jiehun xxx.\n",
        "离婚":"用lihun xxx就成.\n",
        "补结婚证": (: get_again :),
        ]));

        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("literate", 300);

        setup();
        carry_object("/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
 {
        if( (int)ob->query_skill("literate",1) < 50 ) 
            {
             command("say " + RANK_D->query_respect(ob) +
 "聪明过人，但文学根基好象略显不足。\n");
                return;
            }
        command("smile");
        command("say " + RANK_D->query_respect(ob) + 
 "才思敏捷，见解不凡，孺子可教。\n");
        command("recruit " + ob->query("id") );
 }

 void recruit_apprentice(object ob)
 {
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shusheng");
 }
 

void init()
{
        ::init();
        add_action("do_jiehun","jiehun");
        add_action("do_jiehun","marry");
        add_action("do_lihun","lihun");
}

int do_lihun(string arg)
{
	object me,ob,card;
	string target;
	me=this_player(1);

	if(!arg || arg==me->query("id"))   {
             tell_object(me,"你自己和自己离婚啊？\n");
             return 1;
            }
	target=(string)me->query("marry/id");
	if( !target)	{
		tell_object(me,"你还没有结婚，如何离婚？\n");
		return 1;
	}
	if( target!=arg)	{
		tell_object(me,"你的配偶不是"+arg+"！\n");
		return 1;
	}

	ob=new("/cmds/adm/stdnpc");
	ob->create(arg);
	if( ob->query("no_use") || (string)ob->query("marry/id")!=me->query("id"))	{
		me->delete("marry");
		card=present("jiehunzheng",me);
		if( objectp(card))	destruct(card);
		say("欧阳修道：你的配偶早已不在人世，我这就给你办离婚吧。\n");
		say("欧阳修道：好啦，你现在又是自由人了。\n");
		destruct(ob);
		return 1;
	}

	ob=find_player(arg);
	if( !objectp(ob))	
         {
            tell_object(me,"你提的人目前不在游戏中吧？\n");
            return 1;
         }

      say(me->query("name")+"想要和"+ob->query("name")+"离婚.\n");

      if(!present(arg,environment()))
        {
         say("知府摇摇头说:"+ob->query("name")+"现在不在这里。\n");
         return 1;
        }
      if( ob->query_temp("want_lihun")==me->query("id") )
        {
         say("知府叹息道：你们好自为之。\n");
         card=present("jiehunzheng",me);
         if( objectp(card))	destruct(card);
         card=present("jiehunzheng",ob);
         if( objectp(card))	destruct(card);

         me->delete("marry");
         me->delete_temp("want_marry");
         me->delete_temp("want_lihun");
         ob->delete("marry");
         ob->delete_temp("want_marry");
         ob->delete_temp("want_lihun");
         tell_object(me,"你的婚姻关系被解除了\n");
         tell_object(ob,"你的婚姻关系被解除了\n");
        }
      else
        {
         say("知府道:"+me->query("name")+",你的想法我知道了"+
             ",不过还要问问"+ob->query("name")+"的意思.\n");
         me->set_temp("want_lihun",arg);
         return 1;
        }

return 1;
}



int do_jiehun(string arg)
{
object me;
object ob;
object card;

me=this_player(1);

if(!arg || arg==me->query("id"))   {
             tell_object(me,"你自己和自己结婚啊？\n");
             return 1;
            }

if( !objectp(ob = find_player(arg)))
         {
            tell_object(me,"你提的人目前不在这世界吧？\n");
            return 1;
         }


      say(me->query("name")+"想要和"+ob->query("name")+"结婚.\n");
      
      if(me->query("age") <16)
        {
         say("知府摇摇头，显然你没达到结婚年龄。\n");
         return 1;
        }
	if( me->query("marry/id") || me->query("marry/name"))
	{
	  say("知府道：你已结过婚了，先离了再说。\n");
	  return 1;
	}
      
      if(!present(arg,environment()))
        {
         say("知府摇摇头说:"+ob->query("name")+"现在不在这里。\n");
         return 1;
        }
      if( ob->query_temp("want_marry")==me->query("id") )
        {
         say("知府微笑道：祝你们俩白头谐老，永无二心。\n");   
         ob->set("marry/id",me->query("id"));
         ob->set("marry/name",me->query("name"));
         me->set("marry/id",arg);
         me->set("marry/name",ob->query("name"));
         card= clone_object("/obj/marry_c");
         card->set("name","你和"+ob->query("name")+"("+arg+")的结婚证");
         card->set("marry_id",arg);
         card->set("marry_name",ob->query("name"));
         card->move(me);
         card= clone_object("/obj/marry_c");
         card->set("name","你和"+me->query("name")+"("+me->query("id")+")的结婚证");
         card->set("marry_id",me->query("id"));
         card->set("marry_name",me->query("name"));
         card->move(ob);
         say("知府递给"+ob->query("name")+"和"+me->query("name")
                  +"一人一张结婚证书.\n");
         me->delete_temp("want_marry");
         ob->delete_temp("want_marry");
         command("chat 恭禧"+me->query("name")+"与"+ob->query("name")+
         "两位新人，千秋成载，永为夫妇！");
         return 1 ;
         
        } 
      else
        {
         if( me->query("gender") == ob->query("gender") )
          {
           say ("同性恋啊！, 欧阳修被"+me->query("name")+
                  "气得口吐白沫昏了过去.\n");
           return 1;
          }
         say("知府微笑道:"+me->query("name")+",你的心意我知道了"+
             ",不过还要问问"+ob->query("name")+"的意思.\n");
         me->set_temp("want_marry",arg);
         return 1;
        }

return 1;
}


int get_again()
{
	object me=this_player(),card;
	string id,name;

	id=(string)me->query("marry/id");
	name=(string)me->query("marry/name");

	if( !id || !name)	{
		tell_object(me,"欧阳修道：你还没结婚，补什么啊？\n");
		return 1;
	}
	
	card=present("jiehunzheng",me);
	if( objectp(card))	{
		tell_object(me,"欧阳修怒道：你身上不是有吗？难道想戏弄本官不成！\n");
		return 1;
	}
	card=new("/obj/marry_c");
	card->set("marry_id",id);
	card->set("marry_name",name);
	card->set("name","你和"+name+"("+id+")的结婚证");
	card->move(me);
	tell_object(me,"欧阳修点点头道：好吧，这张结婚证一定要保管好啊。\n");
	return 1;
}
