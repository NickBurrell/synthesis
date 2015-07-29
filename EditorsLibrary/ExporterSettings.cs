﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EditorsLibrary
{
    public partial class ExporterSettings : Form
    {

        public ExporterSettingsValues values;

        public ExporterSettings(ExporterSettingsValues defaultValues)
        {
            InitializeComponent();

            values = defaultValues;

            LoadValues();

            buttonOK.Click += delegate(object sender, EventArgs e)
            {
                SaveValues();

                Close();
            };

            buttonCancel.Click += delegate(object sender, EventArgs e)
            {
                Close();
            };
        }

        private void LoadValues()
        {
            checkboxSaveLog.Checked = values.generalSaveLog;
            textboxLogLocation.Text = values.generalSaveLogLocation;
            buttonChooseText.BackColor = Color.FromArgb((int) values.generalTextColor);
            buttonChooseBackground.BackColor = Color.FromArgb((int) values.generalBackgroundColor);

            checkboxSoftBodies.Checked = values.skeletonExportSoft;

            trackbarMeshResolution.Value = values.meshResolutionValue;
            checkboxFancyColors.Checked = values.meshFancyColors;

            checkboxSaveLog_CheckedChanged(null, null); //To make sure things are enabled/disabled correctly
        }

        private void SaveValues()
        {
            values.generalSaveLog = checkboxSaveLog.Checked;
            values.generalSaveLogLocation = textboxLogLocation.Text;
            values.generalTextColor = (uint) buttonChooseText.BackColor.ToArgb();
            values.generalBackgroundColor = (uint)buttonChooseBackground.BackColor.ToArgb();

            values.skeletonExportSoft = checkboxSoftBodies.Checked;

            values.meshResolutionValue = trackbarMeshResolution.Value;
            values.meshFancyColors = checkboxFancyColors.Checked;
        }

        private void checkboxSaveLog_CheckedChanged(object sender, EventArgs e)
        {
            textboxLogLocation.Enabled = checkboxSaveLog.Checked;
            buttonChooseFolder.Enabled = checkboxSaveLog.Checked;
        }

        private void buttonChooseFolder_Click(object sender, EventArgs e)
        {
            string dirPath = null;

            var dialogThread = new Thread(() =>
            {
                FolderBrowserDialog openDialog = new FolderBrowserDialog();
                openDialog.RootFolder = Environment.SpecialFolder.UserProfile;
                openDialog.ShowNewFolderButton = true;
                openDialog.Description = "Choose log folder";
                DialogResult openResult = openDialog.ShowDialog();

                if (openResult == DialogResult.OK) dirPath = openDialog.SelectedPath;
            });

            dialogThread.SetApartmentState(ApartmentState.STA);
            dialogThread.Start();
            dialogThread.Join();

            textboxLogLocation.Text = dirPath;
        }

        private void buttonChooseText_Click(object sender, EventArgs e)
        {
            ColorDialog colorChooser = new ColorDialog();
            colorChooser.ShowDialog();
            buttonChooseText.BackColor = colorChooser.Color;
        }

        private void buttonChooseBackground_Click(object sender, EventArgs e)
        {
            ColorDialog colorChooser = new ColorDialog();
            colorChooser.ShowDialog();
            buttonChooseBackground.BackColor = colorChooser.Color;
        }

        public static ExporterSettingsValues GetDefaultSettings()
        {
            ExporterSettingsValues defaultValues = new ExporterSettingsValues();

            defaultValues.generalSaveLog = true;
            defaultValues.generalSaveLogLocation = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\BXD_Aardvark";
            defaultValues.generalTextColor = (uint) Color.Lime.ToArgb();
            defaultValues.generalBackgroundColor = 0xFF000000;

            defaultValues.skeletonExportSoft = false;

            defaultValues.meshResolutionValue = 0;
            defaultValues.meshFancyColors = false;

            return defaultValues;
        }

        public struct ExporterSettingsValues
        {
            public bool generalSaveLog;
            public string generalSaveLogLocation;
            public uint generalTextColor;
            public uint generalBackgroundColor;

            public bool skeletonExportSoft; //Not actually a thing yet

            public int meshResolutionValue;
            public bool meshFancyColors;
        }
        
    }
}