-- MySQL dump 10.13  Distrib 5.6.17, for Win32 (x86)
--
-- Host: localhost    Database: shop0609
-- ------------------------------------------------------
-- Server version	5.6.17

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `ci_attribute`
--

DROP TABLE IF EXISTS `ci_attribute`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ci_attribute` (
  `attr_id` smallint(5) unsigned NOT NULL AUTO_INCREMENT COMMENT '商品属性ID',
  `attr_name` varchar(50) NOT NULL DEFAULT '' COMMENT '商品属性名称',
  `type_id` smallint(6) NOT NULL DEFAULT '0' COMMENT '商品属性所属类型ID',
  `attr_type` tinyint(4) NOT NULL DEFAULT '1' COMMENT '属性是否可选 0 为唯一，1为单选，2为多选',
  `attr_input_type` tinyint(4) NOT NULL DEFAULT '1' COMMENT '属性录入方式 0为手工录入，1为从列表中选择，2为文本域',
  `attr_value` text COMMENT '属性的值',
  `sort_order` tinyint(4) NOT NULL DEFAULT '50' COMMENT '属性排序依据',
  PRIMARY KEY (`attr_id`),
  KEY `type_id` (`type_id`)
) ENGINE=MyISAM AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ci_attribute`
--

LOCK TABLES `ci_attribute` WRITE;
/*!40000 ALTER TABLE `ci_attribute` DISABLE KEYS */;
INSERT INTO `ci_attribute` VALUES (12,'清晰度',3,0,1,'普清\r\n高清\r\n超清',0),(2,'尺寸',14,0,1,'S\r\nM\r\nL\r\nXL\r\nXXL',50),(3,'风格',14,0,0,'0',0),(4,'作者',2,0,0,'0',0),(5,'出版社',2,0,0,'0',0),(6,'包装',2,0,1,'平装\r\n精装',0);
/*!40000 ALTER TABLE `ci_attribute` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ci_auth`
--

DROP TABLE IF EXISTS `ci_auth`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ci_auth` (
  `auth_id` smallint(6) unsigned NOT NULL AUTO_INCREMENT,
  `auth_name` varchar(20) NOT NULL COMMENT '权限名称',
  `auth_pid` smallint(6) unsigned NOT NULL COMMENT '父id',
  `auth_c` varchar(32) NOT NULL DEFAULT '' COMMENT '控制器',
  `auth_a` varchar(32) NOT NULL COMMENT '操作方法',
  `auth_path` varchar(32) NOT NULL COMMENT '全路径',
  `auth_level` tinyint(4) NOT NULL DEFAULT '0' COMMENT '级别',
  PRIMARY KEY (`auth_id`)
) ENGINE=InnoDB AUTO_INCREMENT=122 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ci_auth`
--

LOCK TABLES `ci_auth` WRITE;
/*!40000 ALTER TABLE `ci_auth` DISABLE KEYS */;
INSERT INTO `ci_auth` VALUES (100,'商品管理',0,'','','100',0),(101,'订单管理',0,'','','101',0),(102,'权限管理',0,'','','102',0),(103,'商品列表',100,'Goods','showlist','100-103',1),(104,'添加商品',100,'Goods','tianjia','100-104',1),(105,'商品分类',100,'Goods','category','100-105',1),(106,'订单列表',101,'Order','showlist','101-106',1),(107,'订单查询',101,'Order','look','101-107',1),(108,'订单打印',101,'Order','dayin','101-108',1),(109,'管理员列表',102,'Manager','showlist','102-109',1),(110,'角色管理',102,'Role','showlist','102-110',1),(111,'权限列表',102,'Auth','showlist','102-111',1),(119,'会员管理',0,'','','119',0),(120,'会员列表',119,'User','showlist','119-120',1),(121,'商品品牌',100,'Goods','brand','100-121',1);
/*!40000 ALTER TABLE `ci_auth` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ci_brand`
--

DROP TABLE IF EXISTS `ci_brand`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ci_brand` (
  `brand_id` smallint(5) unsigned NOT NULL AUTO_INCREMENT COMMENT '商品品牌ID',
  `brand_name` varchar(30) NOT NULL DEFAULT '' COMMENT '商品品牌名称',
  `brand_desc` varchar(255) NOT NULL DEFAULT '' COMMENT '商品品牌描述',
  `url` varchar(100) NOT NULL DEFAULT '' COMMENT '商品品牌网址',
  `logo` varchar(50) NOT NULL DEFAULT '' COMMENT '品牌logo',
  `sort_order` tinyint(3) unsigned NOT NULL DEFAULT '50' COMMENT '商品品牌排序依据',
  `is_show` tinyint(4) NOT NULL DEFAULT '1' COMMENT '是否显示，默认显示',
  PRIMARY KEY (`brand_id`)
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ci_brand`
--

LOCK TABLES `ci_brand` WRITE;
/*!40000 ALTER TABLE `ci_brand` DISABLE KEYS */;
INSERT INTO `ci_brand` VALUES (3,'小米','为发烧友而生','xiaomi.com','',50,1),(4,'顶你学堂','在线大学','www.topu.com','logo8.png',50,1),(5,'索尼','','sony.com','12248801995180083714.gif',50,0),(6,'华为','更美好的全连接世界','www.huawei.com','huawei.png',50,1);
/*!40000 ALTER TABLE `ci_brand` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ci_category`
--

DROP TABLE IF EXISTS `ci_category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ci_category` (
  `cat_id` smallint(5) unsigned NOT NULL AUTO_INCREMENT COMMENT '商品类别ID',
  `cat_name` varchar(30) NOT NULL DEFAULT '' COMMENT '商品类别名称',
  `parent_id` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT '商品类别父ID',
  `cat_desc` varchar(255) NOT NULL DEFAULT '' COMMENT '商品类别描述',
  `sort_order` tinyint(4) NOT NULL DEFAULT '50' COMMENT '排序依据',
  `unit` varchar(15) NOT NULL DEFAULT '' COMMENT '单位',
  `is_show` tinyint(4) NOT NULL DEFAULT '1' COMMENT '是否显示，默认显示',
  PRIMARY KEY (`cat_id`),
  KEY `pid` (`parent_id`)
) ENGINE=MyISAM AUTO_INCREMENT=16 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ci_category`
--

LOCK TABLES `ci_category` WRITE;
/*!40000 ALTER TABLE `ci_category` DISABLE KEYS */;
INSERT INTO `ci_category` VALUES (1,'广东',0,'',50,'',1),(2,'湖北',0,'',50,'',1),(3,'中山',1,'',50,'',1),(4,'武汉',2,'',50,'',1),(5,'顺德',3,'',50,'',1),(6,'武昌',4,'',50,'',1),(7,'汉口',4,'                    ',50,'0',1),(8,'惠州',1,'                    ',50,'0',1),(9,'北京',0,'',50,'0',1),(10,'海淀区',9,'',50,'0',1),(11,'朝阳区',9,'',50,'0',1),(12,'惠阳区',8,'',50,'0',1),(13,'后厂',10,'',50,'0',1),(14,'国贸',11,'',50,'0',1),(15,'回龙观',9,'',50,'0',1);
/*!40000 ALTER TABLE `ci_category` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ci_goods`
--

DROP TABLE IF EXISTS `ci_goods`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ci_goods` (
  `goods_id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT '商品ID',
  `goods_sn` varchar(30) NOT NULL DEFAULT '' COMMENT '商品货号',
  `goods_name` varchar(100) NOT NULL DEFAULT '' COMMENT '商品名称',
  `goods_brief` varchar(255) NOT NULL DEFAULT '' COMMENT '商品简单描述',
  `goods_desc` text COMMENT '商品详情',
  `cat_id` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT '商品所属类别ID',
  `brand_id` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT '商品所属品牌ID',
  `market_price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '市场价',
  `shop_price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '本店价格',
  `promote_price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '促销价格',
  `promote_start_time` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '促销起始时间',
  `promote_end_time` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '促销截止时间',
  `goods_img` varchar(50) NOT NULL DEFAULT '' COMMENT '商品图片',
  `goods_thumb` varchar(50) NOT NULL DEFAULT '' COMMENT '商品缩略图',
  `goods_number` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT '商品库存',
  `click_count` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '点击次数',
  `type_id` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT '商品类型ID',
  `is_promote` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT '是否促销，默认为0不促销',
  `is_best` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT '是否精品,默认为0',
  `is_new` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT '是否新品，默认为0',
  `is_hot` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT '是否热卖,默认为0',
  `is_onsale` tinyint(3) unsigned NOT NULL DEFAULT '1' COMMENT '是否上架,默认为1',
  `add_time` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '添加时间',
  PRIMARY KEY (`goods_id`),
  KEY `cat_id` (`cat_id`),
  KEY `brand_id` (`brand_id`),
  KEY `type_id` (`type_id`)
) ENGINE=MyISAM AUTO_INCREMENT=22 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ci_goods`
--

LOCK TABLES `ci_goods` WRITE;
/*!40000 ALTER TABLE `ci_goods` DISABLE KEYS */;
INSERT INTO `ci_goods` VALUES (9,'ECS000032','huaweiP9','1241v','<p>&nbsp;爱好请问王企鹅 二万五千二无</p>',4,5,0.00,2500.00,2750.00,1243785600,1417276800,'2.jpg','2_thumb.jpg',301,0,0,0,1,1,1,0,1242110760),(8,'ECS000032','huaweiP10','你好','<p> <a id=\"p-cat-insert\" target=\"_blank\" title=\"\" href=\"https://c-nfa.jd.com/adclick?keyStr=6PQwtwh0f06syGHwQVvRO2qQjwLJ5GHB8CWaVmO7akw8kRNUgm14u0WFAY6zp+eaNiAYfgtpim82Oa05ikX84+dsyKwPnxzxPaHOMOsH928s3j7d9BreBntyNxgAyLm+4fLWlvRBkxoM4QrINBB7LV2iyKJjDAcOaPa8p8pRycSzCtpI/8VedmAx6YXxYAhQPcADfOydEgb3r/t/IOD6jebwKAFQoJNlTkPYqRWHa7QpodVXpEL15gIhF7tS9XGTIH/3PVpFk1yWjCKplUWsYiZkUIzjmhlPlHv4wTLvUHI6PS3e2iAxIftN/cIOoqdkLMz+Zwh2Sv2uEPtOqU+3QA==&cv=2.0&url=https://sale.jd.com/act/owGvima4ZCp.html\" style=\"font-family: tahoma, arial, \"Microsoft YaHei\", \"Hiragino Sans GB\", u5b8bu4f53, sans-serif; line-height: 18px; text-align: center; margin: 0px; padding: 0px; color: rgb(102, 102, 102); text-decoration: none;\"><img alt=\"\" src=\"https://img11.360buyimg.com/da/jfs/t3280/235/6715120832/240330/b6d54788/58afd4a7Ne5c80f5a.jpg\" style=\"margin: 0px; padding: 0px; border: 0px; vertical-align: middle; width: 990px;\" /></a></p>\r\n<div class=\"detail-content clearfix\" data-name=\"z-have-detail-nav\" style=\"margin: 10px 0px; padding: 0px; position: relative; color: rgb(102, 102, 102); font-family: tahoma, arial, \"Microsoft YaHei\", \"Hiragino Sans GB\", u5b8bu4f53, sans-serif; line-height: 18px; background: rgb(247, 247, 247);\">\r\n<div class=\"detail-content-wrap\" style=\"margin: 0px; padding: 0px; width: 990px; float: left; background-color: rgb(255, 255, 255);\">\r\n<div class=\"detail-content-item\" style=\"margin: 0px; padding: 0px; width: 990px;\">\r\n<div id=\"activity_header\" clstag=\"shangpin|keycount|product|activityheader\" style=\"margin: 0px; padding: 0px;\">\r\n<div style=\"margin: 0px; padding: 0px; text-align: center;\"><img alt=\"\" border=\"0\" usemap=\"#MapALL\" src=\"https://img30.360buyimg.com/jgsq-productsoa/jfs/t3133/204/6839212487/56952/f4db2eda/58ad326bN00c5ff18.jpg\" style=\"margin: 0px; padding: 0px; border: 0px; vertical-align: middle;\" /><map name=\"MapALL\">\r\n<area shape=\"rect\" coords=\"3,7,153,147\" href=\"https://sale.jd.com/act/owGvima4ZCp.html\" target=\"_blank\" />\r\n<area shape=\"rect\" coords=\"157,6,296,144\" href=\"https://sale.jd.com/act/rixtzJM24NwmO.html\" target=\"_blank\" />\r\n<area shape=\"rect\" coords=\"305,8,446,152\" href=\"https://sale.jd.com/act/Ifxlmt2gDeQS7.html\" target=\"_blank\" />\r\n<area shape=\"rect\" coords=\"450,7,599,150\" href=\"https://sale.jd.com/act/4dhmwvu6rpc.html\" target=\"_blank\" />\r\n<area shape=\"rect\" coords=\"604,8,749,147\" href=\"https://sale.jd.com/act/IeGA2F5vSpBjaWxV.html\" target=\"_blank\" /></map></div>\r\n</div>\r\n<div id=\"J-detail-content\" style=\"margin: 0px; padding: 0px;\">\r\n<div style=\"margin: 0px; padding: 0px; text-align: center;\">\r\n<div class=\"content_tpl\" style=\"margin: 0px auto; padding: 0px; width: 750px;\">\r\n<div class=\"formwork\" style=\"margin: 0px; padding: 10px 0px; overflow: hidden; width: 750px; border-bottom: 1px dashed rgb(230, 230, 230); line-height: 23px; text-align: left; font-family: Arial, Helvetica, sans-serif; font-size: 14px;\">\r\n<div class=\"formwork_img\" style=\"margin: 0px auto; padding: 0px; width: 750px; text-align: center;\"><a href=\"https://item.jd.com/2831554.html\" target=\"_blank\" style=\"margin: 0px; padding: 0px; color: rgb(102, 102, 102); text-decoration: none;\"><img alt=\"\" width=\"750\" height=\"281\" border=\"0\" usemap=\"#Map\" src=\"https://img20.360buyimg.com/vc/jfs/t4018/119/2476830723/85771/c46c1912/58aac214N8abac45e.jpg\" style=\"margin: 0px; padding: 0px; border: 0px; vertical-align: middle;\" /></a></div>\r\n</div>\r\n</div>\r\n<div class=\"content_tpl\" style=\"margin: 0px auto; padding: 0px; width: 750px;\">\r\n<div class=\"formwork\" style=\"margin: 0px; padding: 10px 0px; overflow: hidden; width: 750px; border-bottom: 1px dashed rgb(230, 230, 230); line-height: 23px; text-align: left; font-family: Arial, Helvetica, sans-serif; font-size: 14px;\">\r\n<div class=\"formwork_img\" style=\"margin: 0px auto; padding: 0px; width: 750px; text-align: center;\"><img alt=\"\" src=\"https://img30.360buyimg.com/jgsq-productsoa/jfs/t3964/309/1573072847/1310984/4c07f15d/587f38eaNf0507a69.jpg\" style=\"margin: 0px; padding: 0px; border: 0px; vertical-align: middle;\" /></div>\r\n<div> </div>\r\n</div>\r\n</div>\r\n</div>\r\n</div>\r\n</div>\r\n</div>\r\n</div>',1,6,0.00,2500.00,2750.00,1243785600,1417276800,'huawei3.png','huawei3_thumb.png',301,0,0,0,1,1,1,0,1241422082),(20,'','apple7','','apple7',0,0,0.00,5700.00,0.00,0,0,'./Public/upload/2017-04-29/59049f37d46f6.jpg','./Public/upload/2017-04-29/small_59049f37d46f6.jpg',123,0,0,0,0,0,0,1,0),(1,'','小米','',NULL,0,1,0.00,1999.00,0.00,0,0,'','',1234,0,0,0,0,0,0,1,1243221231),(2,'','华为','',NULL,0,2,0.00,2500.00,0.00,0,0,'','',2000,0,0,0,0,0,0,1,1243333123),(3,'','苹果','',NULL,0,3,0.00,5999.00,0.00,0,0,'','',0,0,0,0,0,0,0,1,1232222133),(4,'','一加','',NULL,0,4,0.00,3200.00,0.00,0,0,'','',0,0,0,0,0,0,0,1,1241123111),(10,'','samsung6s','',NULL,0,0,0.00,5600.00,0.00,0,0,'','',126,0,0,0,0,0,0,1,0),(11,'','samsung6s','',NULL,0,0,0.00,5600.00,0.00,0,0,'','',126,0,0,0,0,0,0,1,0),(12,'','huaweiP9','',NULL,0,0,0.00,2500.00,0.00,0,0,'','',301,0,0,0,0,0,0,1,0),(13,'','huaweiP9','',NULL,0,0,0.00,2500.00,0.00,0,0,'','',301,0,0,0,0,0,0,1,0),(14,'','huaweiP9','',NULL,0,0,0.00,2500.00,0.00,0,0,'','',301,0,0,0,0,0,0,1,0),(15,'','huaweiP9','',NULL,0,0,0.00,2500.00,0.00,0,0,'','',301,0,0,0,0,0,0,1,0),(16,'','huaweiMate10','','very very good',0,0,0.00,4500.00,0.00,0,0,'','',300,0,0,0,0,0,0,1,0),(17,'','oppoR9','','',0,0,0.00,2799.00,0.00,0,0,'','',354,0,0,0,0,0,0,1,0),(18,'','vivoX9','','很不错的手机',0,0,0.00,3000.00,0.00,0,0,'','',450,0,0,0,0,0,0,1,0),(19,'','xiaomi6S','','为发烧友而生',0,0,0.00,1999.00,0.00,0,0,'','',234,0,0,0,0,0,0,1,0),(21,'','samsung','','good',0,0,0.00,5700.00,0.00,0,0,'Public/upload/2017-04-29/5904a54ac3547.jpg','Public/upload/2017-04-29/small_5904a54ac3547.jpg',200,0,0,0,0,0,0,1,0);
/*!40000 ALTER TABLE `ci_goods` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ci_goods_attr`
--

DROP TABLE IF EXISTS `ci_goods_attr`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ci_goods_attr` (
  `goods_attr_id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT '编号ID',
  `goods_id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '商品ID',
  `attr_id` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT '属性ID',
  `attr_value` varchar(255) NOT NULL DEFAULT '' COMMENT '属性值',
  `attr_price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '属性价格',
  PRIMARY KEY (`goods_attr_id`),
  KEY `goods_id` (`goods_id`),
  KEY `attr_id` (`attr_id`)
) ENGINE=MyISAM AUTO_INCREMENT=16 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ci_goods_attr`
--

LOCK TABLES `ci_goods_attr` WRITE;
/*!40000 ALTER TABLE `ci_goods_attr` DISABLE KEYS */;
INSERT INTO `ci_goods_attr` VALUES (1,3,4,'爱仕达',0.00),(2,3,5,'机械出版社',0.00),(3,3,6,'平装',0.00),(4,4,2,'XXL',0.00),(5,4,3,'热武器 而是',0.00),(6,5,4,'dsf ',0.00),(7,5,5,'dfas  ',0.00),(8,5,6,'精装',0.00),(9,6,4,'无人区',0.00),(10,6,5,'任务',0.00),(11,6,6,'平装',0.00),(12,8,6,'平装',0.00),(13,9,4,'21 3',0.00),(14,9,5,'21314',0.00),(15,9,6,'平装',0.00);
/*!40000 ALTER TABLE `ci_goods_attr` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ci_goods_type`
--

DROP TABLE IF EXISTS `ci_goods_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ci_goods_type` (
  `type_id` smallint(5) unsigned NOT NULL AUTO_INCREMENT COMMENT '商品类型ID',
  `type_name` varchar(50) NOT NULL DEFAULT '' COMMENT '商品类型名称',
  PRIMARY KEY (`type_id`)
) ENGINE=MyISAM AUTO_INCREMENT=15 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ci_goods_type`
--

LOCK TABLES `ci_goods_type` WRITE;
/*!40000 ALTER TABLE `ci_goods_type` DISABLE KEYS */;
INSERT INTO `ci_goods_type` VALUES (1,'音乐'),(2,'书'),(3,'电影'),(4,'手机'),(5,'笔记本电脑'),(6,'数码相机'),(7,'数码摄像机'),(8,'化妆品'),(9,'精品手机'),(10,'我的商品'),(11,'尺寸'),(12,'鞋帽'),(13,'篮球'),(14,'服装');
/*!40000 ALTER TABLE `ci_goods_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ci_manager`
--

DROP TABLE IF EXISTS `ci_manager`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ci_manager` (
  `mg_id` int(11) NOT NULL AUTO_INCREMENT,
  `mg_name` varchar(32) NOT NULL,
  `mg_pwd` varchar(32) NOT NULL,
  `mg_time` int(10) unsigned NOT NULL COMMENT '时间',
  `mg_role_id` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT '角色id',
  PRIMARY KEY (`mg_id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ci_manager`
--

LOCK TABLES `ci_manager` WRITE;
/*!40000 ALTER TABLE `ci_manager` DISABLE KEYS */;
INSERT INTO `ci_manager` VALUES (1,'admin','123456',0,0),(2,'tom','123456',0,10),(3,'linken','123456',0,11);
/*!40000 ALTER TABLE `ci_manager` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ci_role`
--

DROP TABLE IF EXISTS `ci_role`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ci_role` (
  `role_id` smallint(6) unsigned NOT NULL AUTO_INCREMENT,
  `role_name` varchar(20) NOT NULL COMMENT '角色名称',
  `role_auth_ids` varchar(128) NOT NULL DEFAULT '' COMMENT '权限ids,1,2,5',
  `role_auth_ac` text COMMENT '控制器-操作，控制器-操作，控制器-操作',
  PRIMARY KEY (`role_id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ci_role`
--

LOCK TABLES `ci_role` WRITE;
/*!40000 ALTER TABLE `ci_role` DISABLE KEYS */;
INSERT INTO `ci_role` VALUES (10,'主管','100,103,104,105,101,106,107,108,109,110,120','Goods-showlist,Goods-tianjia,Goods-category,Order-showlist,Order-look,Order-dayin,Manager-showlist,Role-showlist,User-showlist'),(11,'经理','100,104,101,106,107,108','Goods-tianjia,Order-showlist,Order-look,Order-dayin');
/*!40000 ALTER TABLE `ci_role` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ci_user`
--

DROP TABLE IF EXISTS `ci_user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ci_user` (
  `user_id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT '用户编号',
  `user_name` varchar(50) NOT NULL DEFAULT '' COMMENT '用户名',
  `password` char(32) NOT NULL DEFAULT '' COMMENT '用户密码,md5加密',
  `user_email` varchar(50) NOT NULL DEFAULT '' COMMENT '电子邮箱',
  `user_sex` enum('1','2','3') NOT NULL,
  `user_qq` int(10) NOT NULL,
  `user_tel` int(11) NOT NULL,
  `user_xueli` enum('1','2','3','4','5') NOT NULL,
  `user_hobby` set('1','2','3','4') NOT NULL,
  `user_introduce` text NOT NULL,
  PRIMARY KEY (`user_id`)
) ENGINE=MyISAM AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ci_user`
--

LOCK TABLES `ci_user` WRITE;
/*!40000 ALTER TABLE `ci_user` DISABLE KEYS */;
INSERT INTO `ci_user` VALUES (1,'txs','123456','123@qq.com','',0,0,'','',''),(2,'txs','e10adc3949ba59abbe56e057f20f883e','123@qq.com','',0,0,'','',''),(8,'xiaoming','123','xiaoli@163.com','',123456,2147483647,'','1,3','I am xiaoli'),(9,'xiaoming','123','xiaoli@163.com','2',123456,2147483647,'5','1,3','I am xiaoli'),(10,'aobma','123','aobma@whitehouse.com','1',12424,2147483647,'5','','I am aobma'),(11,'xiaoshan','123','xiaoshan@163.com','1',123456,2147483647,'2','','esw e'),(12,'xiaofang','123','xiaofang@163.com','2',12314412,2147483647,'3','1,2','wq rq');
/*!40000 ALTER TABLE `ci_user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-09-03 10:01:40
