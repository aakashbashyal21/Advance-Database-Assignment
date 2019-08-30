package com.company;

import java.sql.*;

public class MySQLDbAccess {

    private Connection connection = null;
    private Statement statement = null;
    private ResultSet resultSet = null;

    private Connection createConnection() throws SQLException {
        return DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/kusims_db", "root", "");
    }

    //read databae
    public  void readDatabase(){
        try {
            Class.forName("com.mysql.jdbc.Driver"); /*Loading mysql driver*/

            /*Making JDBC connection*/
            connection = this.createConnection();

            //Creating a statement object for executing query
            statement = connection.createStatement();

            //Create a ResultSet object to store the query
            resultSet = statement.executeQuery("select * from users");

            System.out.println("-----------------------------------------------------------------------------");
            System.out.printf("%5s %30s %20s %10s %10s", "ID", "EMAIL", "USER TYPE", "FIRSTNAME", "LASTNAME");
            System.out.println();
            System.out.println("-----------------------------------------------------------------------------");
            while (resultSet.next()){

                //Prepare the result set to print
                int id  = resultSet.getInt("id");
                String firstName = resultSet.getString("first_name");
                String lastName = resultSet.getString("last_name");
                String email = resultSet.getString("email");
                String userType = resultSet.getString("user_type");

                //Display the result
                System.out.format("%5s %30s %20s %10s %10s",
                        id, email, userType, firstName, lastName);
                System.out.println();
            }
        }
        catch(Exception ex){

        }
        finally {
            close(); //invoke the function for clossing the connection
        }
    }
    //close the connection
    private void close(){
        if (resultSet != null)
            try
            {
                resultSet.close();
            } catch (SQLException ignore) {}
        if (statement != null)
            try
            {
                statement.close();
            } catch (SQLException ignore) {}
        if (connection != null)
            try
            {
                connection.close();
            } catch (SQLException ignore) {}
    }

}
