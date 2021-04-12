// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;
int main()
    {
        MYSQL* conectar;
        conectar = mysql_init(0);
        conectar = mysql_real_connect(conectar, "localhost", "usr_kardex", "k@rdex123", "db_kardex", 3306, NULL, 0);
        if (conectar)
            //cout << "Conexion Exitosa..." << endl;
        string marca;
        cout << "Ingrese Marca:";
        cin >> marca;
        string insert = "insert into marcas(marca) values('" + marca + "')";
        const char* i = insert.c_str();
        // executar el query
        q_estado = mysql_query(conectar, i);
        if (!q_estado) {
            cout << "Ingreso Exitoso ..." << endl;
        }
        else {
            cout << "Error al ingresar ..." << endl;
        }

        string consulta = "select * from marcas";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << "." << fila[1] << endl;
            }
        }
        else {
            cout << "Error al consultar ..." << endl;
        }
        {
            string producto, descripcion, fecha_ingreso = "now()";
            string idmarca, existencia, precio_costo, precio_venta;
            int idmarca, existencia;
            double precio_costo, precio_venta;

            cout << "\ningrese el producto: ";
            getline(cin, producto);
            cout << "\ningrese el idmarca: ";
            cin >> idmarca;
            cin.ignore();
            cout << "\ningrese la descripcion: ";
            getline(cin, descripcion);
            cout << "\ningrese el precio costo: ";
            cin >> precio_costo;
            cin.ignore();
            cout << "\ningrese el precio venta: ";
            cin >> precio_venta;
            cin.ignore();
            cout << "\ningrese las existencias: ";
            cin >> existencia;
            cout << "\nla fecha de ingreso será esta hora en la que se estan ingresando datos" << endl;

            string insert = "insert into productos(producto,idmarca,descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) values ('" + producto + "' , " + idmarca + " , '" + descripcion + "' , " + precio_costo + "," + precio_venta + "," + existencia + "," + fecha_ingreso + ")";
            const char* i = insert.c_str();
            q_estado = mysql_query(conectar, i);
            if (!q_estado)
            {
                cout << "Ingreso exitoso" << endl;
            }
            else
            {
                cout << "error al ingresar registro" << endl;
            }
        }
    }
    void update_marcas()
    {
        MYSQL* conectar;
        conectar = mysql_init(0);
        conectar = mysql_real_connect(conectar, "localhost", "usr_kardex", "k@rdex123", "db_kardex", 3306, NULL, 0);
        if (conectar)
        {
            string marca, idmarca;
            cout << "ingrese el id del registro que desea modificar: ";
            cin >> idmarca;
            cin.ignore();
            cout << "ingrese la nueva marca: ";
            getline(cin, marca);
            string update = "update marcas set marca= '" + marca + "' where idmarca= " + idmarca;
            const char* i = update.c_str();
            q_estado = mysql_query(conectar, i);
            if (!q_estado)
            {
                cout << "modificacion exitosa" << endl;
            }
            else
            {
                cout << "Error al modificar" << endl;
            }
        }
    }

    void update_productos()
    {
        MYSQL* conectar;

        conectar = mysql_init(0);
        conectar = mysql_real_connect(conectar, "localhost", "usr_kardex", "k@rdex123", "db_kardex", 3306, NULL, 0);
        cout << endl << endl;
        if (conectar)
        {
            string producto, idmarca, descripcion, precio_costo, precio_venta, existencias, idproducto, update_idproducto, update;
            int opcion;
            cout << "Ingrese el id del registro que desea modificar: ";
            cin >> idproducto;
            cin.ignore();
            Sleep(500);
            system("cls");
            cout << "   1. Producto" << endl;
            cout << "   2. Descripcion" << endl;
            cout << "   3. Precio costo" << endl;
            cout << "   4. Precio venta" << endl;
            cout << "   5. Existencias" << endl;
            cout << "Que registro desea modificar: ";
            cin >> opcion;
            cin.ignore();
            switch (opcion)
            {
            case 1:
                cout << "Modifique el producto: ";
                getline(cin, producto);
                update = "update productos set producto= '" + producto + "' where idproducto= " + idproducto;
                break;
            case 2:
                cout << "modifique la descripcion: ";
                getline(cin, descripcion);
                update = "update productos set descripcion= '" + descripcion + "' where idproducto= " + idproducto;
                break;
            case 3:
                cout << "modifique el precio_costo: ";
                cin >> precio_costo;
                update = "update productos set precio_costo= " + precio_costo + " where idproducto= " + idproducto;
                break;
            case 4:
                cout << "ingrese la modificacion de precio_venta: ";
                cin >> precio_venta;
                update = "update productos set precio_venta= " + precio_venta + " where idproducto= " + idproducto;
                break;
            case 5:
                cout << "ingrese la modificacion de existencias: ";
                cin >> existencias;
                update = "update productos set existencia= " + existencias + " where idproducto= " + idproducto;
                break;
            default:
                cout << "esa opcion no existe" << endl;
                break;
            }

            const char* q = update.c_str();
            q_estado = mysql_query(conectar, q);
            if (!q_estado)
            {
                cout << "Modificacion exitosa" << endl;
            }
            else
            {
                cout << "Modificacion exitosa" << endl;
            }
        }
    }
    void delete_marcas()
    {
        MYSQL* conectar;
        conectar = mysql_init(0);
        conectar = mysql_real_connect(conectar, "localhost", "usr_kardex", "k@rdex123", "db_kardex", 3306, NULL, 0);
        if (conectar)
        {
            string marca, id;
            cout << "ingrese el id del registro que desea eliminar: ";
            cin >> id;
            cin.ignore();
            string update = "delete from marcas where idmarca= " + id;
            const char* i = update.c_str();
            q_estado = mysql_query(conectar, i);
            if (!q_estado)
            {
                cout << "Eliminacion exitosa" << endl;
            }
            else
            {
                cout << "Error al eliminar" << endl;
            }
        }
        else {
            cout << "Error al consultar ..." << endl;
        }*/
    }
    else {
    cout << "Error en la Conexion..." << endl;
    }
    system("pause");
    return 0;
}
