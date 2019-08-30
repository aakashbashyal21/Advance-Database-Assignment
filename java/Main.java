package com.company;

import dnl.utils.text.table.TextTable;

import java.sql.*;

class MysqlCon {
    public static void main(String[] args) {
        try {
            /*Invoke the dbAccessObj in class MySQLDbAccess*/
            MySQLDbAccess dbAccessObj = new MySQLDbAccess();
            dbAccessObj.readDatabase();
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
