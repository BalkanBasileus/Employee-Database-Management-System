#pragma once

namespace EployeeDatabase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		// MySql Data
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		MySqlDataAdapter^ sqlAdapt = gcnew MySqlDataAdapter();
		DataTable^ sqlDataTable = gcnew DataTable();
		MySqlDataReader^ sqlReader;// = gcnew MySqlDataReader();




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textBoxHireDate;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxDOB;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBoxLastName;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxFirstName;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ textBoxEmployeeNum;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBoxGender;

	private: System::Windows::Forms::Label^ label5;




	private: System::Windows::Forms::Button^ buttonReset;

	private: System::Windows::Forms::Button^ buttonExit;
	private: System::Windows::Forms::Button^ buttonRefresh;
	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Button^ buttonUpdate;
	private: System::Windows::Forms::Button^ buttonAdd;

	private: System::Windows::Forms::Panel^ panel3;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			EmployeeConnector(); // Establish connection to database.
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonUpdate = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonRefresh = (gcnew System::Windows::Forms::Button());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBoxEmployeeNum = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxGender = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxHireDate = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxDOB = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBoxLastName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxFirstName = (gcnew System::Windows::Forms::TextBox());
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->buttonAdd);
			this->panel3->Controls->Add(this->buttonUpdate);
			this->panel3->Controls->Add(this->buttonDelete);
			this->panel3->Controls->Add(this->buttonRefresh);
			this->panel3->Controls->Add(this->buttonReset);
			this->panel3->Controls->Add(this->buttonExit);
			this->panel3->Controls->Add(this->dataGridView1);
			this->panel3->Location = System::Drawing::Point(12, 256);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(658, 284);
			this->panel3->TabIndex = 1;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAdd->Location = System::Drawing::Point(223, 247);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(82, 34);
			this->buttonAdd->TabIndex = 9;
			this->buttonAdd->Text = L"Add";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonAdd_Clicked);
			// 
			// buttonUpdate
			// 
			this->buttonUpdate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonUpdate->Location = System::Drawing::Point(135, 247);
			this->buttonUpdate->Name = L"buttonUpdate";
			this->buttonUpdate->Size = System::Drawing::Size(82, 34);
			this->buttonUpdate->TabIndex = 8;
			this->buttonUpdate->Text = L"Update";
			this->buttonUpdate->UseVisualStyleBackColor = true;
			this->buttonUpdate->Click += gcnew System::EventHandler(this, &MyForm::buttonUpdate_Clicked);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonDelete->Location = System::Drawing::Point(311, 247);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(82, 34);
			this->buttonDelete->TabIndex = 7;
			this->buttonDelete->Text = L"Delete";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &MyForm::buttonDelete_Clicked);
			// 
			// buttonRefresh
			// 
			this->buttonRefresh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonRefresh->Location = System::Drawing::Point(399, 247);
			this->buttonRefresh->Name = L"buttonRefresh";
			this->buttonRefresh->Size = System::Drawing::Size(82, 34);
			this->buttonRefresh->TabIndex = 6;
			this->buttonRefresh->Text = L"Refresh";
			this->buttonRefresh->UseVisualStyleBackColor = true;
			this->buttonRefresh->Click += gcnew System::EventHandler(this, &MyForm::buttonRefresh_Clicked);
			// 
			// buttonReset
			// 
			this->buttonReset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonReset->Location = System::Drawing::Point(487, 247);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(82, 34);
			this->buttonReset->TabIndex = 3;
			this->buttonReset->Text = L"Reset";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &MyForm::buttonReset_Clicked);
			// 
			// buttonExit
			// 
			this->buttonExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonExit->Location = System::Drawing::Point(575, 247);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(82, 34);
			this->buttonExit->TabIndex = 2;
			this->buttonExit->Text = L"Exit";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &MyForm::buttonExit_Clicked);
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->NullValue = nullptr;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(0, 3);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle2->NullValue = nullptr;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->RowTemplate->DefaultCellStyle->NullValue = nullptr;
			this->dataGridView1->Size = System::Drawing::Size(658, 238);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::gridViewCell_Clicked);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(3, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 30);
			this->label1->TabIndex = 2;
			this->label1->Text = L"First Name";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->textBoxEmployeeNum);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->textBoxGender);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->textBoxHireDate);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->textBoxDOB);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->textBoxLastName);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBoxFirstName);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(378, 238);
			this->panel1->TabIndex = 0;
			// 
			// textBoxEmployeeNum
			// 
			this->textBoxEmployeeNum->Location = System::Drawing::Point(137, 200);
			this->textBoxEmployeeNum->Multiline = true;
			this->textBoxEmployeeNum->Name = L"textBoxEmployeeNum";
			this->textBoxEmployeeNum->Size = System::Drawing::Size(226, 30);
			this->textBoxEmployeeNum->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(3, 200);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(128, 30);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Emp Number";
			// 
			// textBoxGender
			// 
			this->textBoxGender->Location = System::Drawing::Point(137, 92);
			this->textBoxGender->Multiline = true;
			this->textBoxGender->Name = L"textBoxGender";
			this->textBoxGender->Size = System::Drawing::Size(226, 30);
			this->textBoxGender->TabIndex = 11;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(3, 92);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(128, 30);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Gender";
			// 
			// textBoxHireDate
			// 
			this->textBoxHireDate->Location = System::Drawing::Point(137, 164);
			this->textBoxHireDate->Multiline = true;
			this->textBoxHireDate->Name = L"textBoxHireDate";
			this->textBoxHireDate->Size = System::Drawing::Size(226, 30);
			this->textBoxHireDate->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(3, 164);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(128, 30);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Hire Date ";
			// 
			// textBoxDOB
			// 
			this->textBoxDOB->Location = System::Drawing::Point(137, 128);
			this->textBoxDOB->Multiline = true;
			this->textBoxDOB->Name = L"textBoxDOB";
			this->textBoxDOB->Size = System::Drawing::Size(226, 30);
			this->textBoxDOB->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(3, 128);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(128, 30);
			this->label4->TabIndex = 6;
			this->label4->Text = L"DOB";
			// 
			// textBoxLastName
			// 
			this->textBoxLastName->Location = System::Drawing::Point(137, 56);
			this->textBoxLastName->Multiline = true;
			this->textBoxLastName->Name = L"textBoxLastName";
			this->textBoxLastName->Size = System::Drawing::Size(226, 30);
			this->textBoxLastName->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(3, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 30);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Last Name";
			// 
			// textBoxFirstName
			// 
			this->textBoxFirstName->Location = System::Drawing::Point(137, 20);
			this->textBoxFirstName->Multiline = true;
			this->textBoxFirstName->Name = L"textBoxFirstName";
			this->textBoxFirstName->Size = System::Drawing::Size(226, 30);
			this->textBoxFirstName->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(683, 561);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle; // Prevent App resize by user.

		}
#pragma endregion



		//============================================================================================================================== 
		private: System::Void EmployeeConnector() { // Initial Data SQL connection
			
			sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=Password01;database=employees";
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "Select * from employees";
			sqlReader = sqlCmd->ExecuteReader();
			sqlDataTable->Load(sqlReader);  // Fill table with database contents
			sqlReader->Close();
			sqlConn->Close();
			dataGridView1->DataSource = sqlDataTable;

			// Format gridcell with birth_day and hire_date to match formate of database. Windows forms displays it in MM-dd-yyyy. 
			// Updating does not work unless format is the same.
			this->dataGridView1->Columns[1]->DefaultCellStyle->Format = L"yyyy-MM-dd";
			this->dataGridView1->Columns[5]->DefaultCellStyle->Format = L"yyyy-MM-dd";
		}

			   private: System::Void RefreshButton() { // REFRESH BUTTON PRESSED.

				   sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=Password01;database=employees";

				   sqlCmd->Connection = sqlConn;

				   String^ ID = buttonRefresh->Text; 
				   MySqlDataAdapter^ sqlDataAdapter = gcnew MySqlDataAdapter("select * from employees",sqlConn);
				   DataTable^ sqlDataTable = gcnew DataTable();
				   sqlDataAdapter->Fill(sqlDataTable); // Fill table with database contents
				   dataGridView1->DataSource = sqlDataTable;
				   sqlConn->Close(); // Must always close
				  
			   }
		//==============================================================================================================================



// Exit Button
private: System::Void buttonExit_Clicked(System::Object^ sender, System::EventArgs^ e) {
	// Exit Application

	System::Windows::Forms::DialogResult iExit;

	iExit = MessageBox::Show("Confirm if you want to exit", "Employee System", MessageBoxButtons::YesNo,MessageBoxIcon::Question);

	if(iExit == System::Windows::Forms::DialogResult::Yes){
		Application::Exit();
	}
}



// Refresh Button Pressed
private: System::Void buttonRefresh_Clicked(System::Object^ sender, System::EventArgs^ e) {
	// Calls Function to recconect to sql database

	RefreshButton();
}

// Button Reset Pressed
private: System::Void buttonReset_Clicked(System::Object^ sender, System::EventArgs^ e) {
	// Resets proile display

	textBoxFirstName->Text = "";
	textBoxLastName->Text = "";
	textBoxGender->Text = "";
	textBoxDOB->Text = "";
	textBoxHireDate->Text = "";
	textBoxEmployeeNum->Text = "";
}


private: System::Void gridViewCell_Clicked(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	// Display particular account onto profile display
	// Dob and HireDate Formatted to yyyy-MM-dd. Format originally done in EmployeeConnector().

	try{
		textBoxFirstName->Text = dataGridView1->SelectedRows[0]->Cells[2]->Value->ToString();
		textBoxLastName->Text = dataGridView1->SelectedRows[0]->Cells[3]->Value->ToString();
		textBoxEmployeeNum->Text = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();
		textBoxDOB->Text = dataGridView1->SelectedRows[0]->Cells[1]->FormattedValue->ToString();  //Formatted to yyyy-MM-dd.
		textBoxGender->Text = dataGridView1->SelectedRows[0]->Cells[4]->Value->ToString();
		textBoxHireDate->Text = dataGridView1->SelectedRows[0]->Cells[5]->FormattedValue->ToString(); //Formatted to yyyy-MM-dd


	}
	catch (Exception^ e) {
		// Do Nothing.

		//MessageBox::Show(e->ToString());

	}
}

private: System::Void buttonDelete_Clicked(System::Object^ sender, System::EventArgs^ e) {
	// Delete employee from database

	try {
		// Establish connection to db
		sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=Password01;database=employees";
		sqlCmd->Connection = sqlConn;

		// Get employee number and set mysql command to delete account
		String^ emp_no = textBoxEmployeeNum->Text;
		MySqlCommand^ sqlCommand = gcnew MySqlCommand("delete from employees where emp_no =" + emp_no + "", sqlConn);

		// Window::Form dialog confirmation
		System::Windows::Forms::DialogResult iConfirm;
		iConfirm = MessageBox::Show("Are you sure you want to delete? Cannot be undone.", "Employee System", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

		if (iConfirm == System::Windows::Forms::DialogResult::Yes) {
			// Proceed to delete account

			sqlConn->Open();
			sqlReader = sqlCommand->ExecuteReader();

			MessageBox::Show("Record Deleted");
			sqlConn->Close();

			//Refresh sql connection and gridview
			RefreshButton();
		}
		else { // Do nothing.
			
		}

	}
	catch (Exception^ e) {
		// Do Nothing.
		sqlConn->Close();
		MessageBox::Show(e->ToString());

	}

}
private: System::Void buttonUpdate_Clicked(System::Object^ sender, System::EventArgs^ e) {
	// 

	try {
		//sqlConn->Close();
		sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=Password01;database=employees";

		sqlCmd->Connection = sqlConn;

		String^ hireDate = textBoxHireDate->Text;
		String^ firstName = textBoxFirstName->Text;
		String^ lastName = textBoxLastName->Text;
		String^ gender = textBoxGender->Text;
		String^ dob = textBoxDOB->Text;
		String^ empNum = textBoxEmployeeNum->Text;

		

		sqlCmd->CommandText = "Update employees set  emp_no ='" + empNum + "', birth_date ='" + dob + "', first_name ='" + firstName + "', last_name ='" + lastName + "', gender ='"
			+ gender + "', hire_date ='" + hireDate + "' WHERE emp_no =" + empNum + "", sqlConn;

		sqlConn->Open();
		sqlReader = sqlCmd->ExecuteReader();  

		MessageBox::Show("Record Updated");
		sqlConn->Close();

		//EmployeeConnector();
		RefreshButton();

	}
	catch (Exception^ e) {
		// Do Nothing.
		sqlConn->Close();
		MessageBox::Show(e->ToString());

	}

}

private: System::Void buttonAdd_Clicked(System::Object^ sender, System::EventArgs^ e) {
	// Update mysql database with new account.

	sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=Password01;database=employees";
	sqlConn->Open();

	sqlCmd->Connection = sqlConn;

	try{
		// Obtain employee file from display
		String^ hireDate = textBoxHireDate->Text;
		String^ firstName = textBoxFirstName->Text;
		String^ lastName = textBoxLastName->Text;
		String^ gender = textBoxGender->Text;
		String^ dob = textBoxDOB->Text;
		String^ empNum = textBoxEmployeeNum->Text;

		// Update commandtext
		sqlCmd->CommandText = "insert into employees (emp_no, birth_date, first_name, last_name, gender, hire_date)"
			"values('" + empNum + "','" + dob + "', '" + firstName + "', '" + lastName + "', '" + gender + "', '" + hireDate + "')";
	
		// Execute, close, and refresh grid.
		sqlCmd->ExecuteNonQuery();
		sqlConn->Close();
		dataGridView1->DataSource = sqlDataTable;
		RefreshButton();


	}
	catch (Exception^ e){
		sqlConn->Close();
		MessageBox::Show(e->ToString());
	}

}
};
}
