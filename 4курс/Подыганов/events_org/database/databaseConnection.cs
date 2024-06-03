using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data.MySqlClient;

namespace events_org.database
{
    class databaseConnection
    {
        static string connectionString = "host=127.0.01;port=3306;" +
           "userid=root;password=root;database=mydb;sslmode=none";
        static MySqlConnection myConnection =
            new MySqlConnection(connectionString);

        static MySqlCommand myCommand =
               new MySqlCommand();

        static public void OpenConnection()
        {
            myConnection.Open();
            myCommand.Connection = myConnection;
        }

        static public void CloseConnection()
        {
            myConnection.Close();
        }

        static public int ExecuteNonQuery(string SQL)
        {
            myCommand.CommandText = SQL;
            return myCommand.ExecuteNonQuery();
        }

        static public object ExecuteScalar(string SQL)
        {
            myCommand.CommandText = SQL;
            return myCommand.ExecuteScalar();
        }

        static public DataTable ExecuteDataQuery(string SQL)
        {
            MySqlDataAdapter myAdapter =
                new MySqlDataAdapter(SQL, myConnection);
            DataTable dataTable = new DataTable();
            myAdapter.Fill(dataTable);
            return dataTable;
        }

        static public DataTable ExecuteDataQuery(string SQL, out int RowsCount)
        {
            MySqlDataAdapter myAdapter =
                new MySqlDataAdapter(SQL, myConnection);
            DataTable dataTable = new DataTable();
            myAdapter.Fill(dataTable);
            RowsCount = dataTable.Rows.Count;
            return dataTable;
        }
    }
}
