#include "modelviewsample.h"

ModelViewSample::ModelViewSample(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	// Create model
    model = new QStringListModel(this);

    // Make data
    QStringList List;
    List << "Clair de Lune" << "Reverie" << "Prelude";

    // Populate our model
    model->setStringList(List);

    // Glue model and view together
    ui.listView->setModel(model);
    ui.comboBox->setModel(model);

    // Add additional feature so that
    // we can manually modify the data in ListView
    // It may be triggered by hitting any key or double-click etc.
    ui.listView->
            setEditTriggers(QAbstractItemView::AnyKeyPressed |
                            QAbstractItemView::DoubleClicked);
}

ModelViewSample::~ModelViewSample()
{

}

void ModelViewSample::on_addPB_clicked()
{
    // Add button clicked
    // Adding at the end

    // Get the position
    int row = model->rowCount();

    // Enable add one or more rows
    model->insertRows(row,1);

    // Get the row for Edit mode
    QModelIndex index = model->index(row);

    // Enable item selection and put it edit mode
    ui.listView->setCurrentIndex(index);
    ui.listView->edit(index);
}

void ModelViewSample::on_insertPB_clicked()
{
    // Insert button clicked

    // Get the position
    int row = ui.listView->currentIndex().row();

    // Enable add one or more rows
    model->insertRows(row,1);

    // Get row for Edit mode
    QModelIndex index = model->index(row);

    // Enable item selection and put it edit mode
    ui.listView->setCurrentIndex(index);
    ui.listView->edit(index);
}

void ModelViewSample::on_deletePB_clicked()
{
    // Delete button clicked
    // For delete operation,
    // we're dealing with a Model not a View
    // Get the position
    model->removeRows(ui.listView->currentIndex().row(),1);
}