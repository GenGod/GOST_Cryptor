object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Enctiptor(Kuznechick)'
  ClientHeight = 531
  ClientWidth = 395
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LabelFileName: TLabel
    Left = 100
    Top = 92
    Width = 157
    Height = 19
    Caption = 'Select File for Enc/Dec'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelTableName: TLabel
    Left = 100
    Top = 10
    Width = 123
    Height = 19
    Caption = 'Select Crypt table'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelKeyName: TLabel
    Left = 96
    Top = 163
    Width = 100
    Height = 19
    Caption = 'Select Key File'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelReverseTableName: TLabel
    Left = 100
    Top = 43
    Width = 183
    Height = 19
    Caption = 'Select Reverse Crypt table'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 138
    Width = 369
    Height = 81
    Caption = 'Key'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    Items.Strings = (
      ''
      'or Enter')
    ParentFont = False
    TabOrder = 3
    OnClick = RadioGroup1Click
  end
  object LogMemo: TMemo
    Left = 8
    Top = 298
    Width = 345
    Height = 188
    Lines.Strings = (
      'Log:')
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 2
  end
  object OpenFileButton: TButton
    Left = 32
    Top = 90
    Width = 62
    Height = 25
    Caption = 'Sellect'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = OpenFileButtonClick
  end
  object OpenTableButton: TButton
    Left = 32
    Top = 8
    Width = 62
    Height = 25
    Caption = 'Sellect'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = OpenTableButtonClick
  end
  object OpenKeyButton: TButton
    Left = 32
    Top = 159
    Width = 62
    Height = 25
    Caption = 'Sellect'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = OpenKeyButtonClick
  end
  object KeyEdit: TEdit
    Left = 96
    Top = 190
    Width = 273
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    MaxLength = 32
    ParentFont = False
    TabOrder = 5
    OnChange = KeyEditChange
  end
  object CryptButton: TButton
    Left = 8
    Top = 242
    Width = 97
    Height = 50
    Caption = 'Crypt'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = CryptButtonClick
  end
  object DecryptButton: TButton
    Left = 144
    Top = 242
    Width = 97
    Height = 50
    Caption = 'Decrypt'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = DecryptButtonClick
  end
  object Button2: TButton
    Left = 352
    Top = 298
    Width = 25
    Height = 26
    Caption = 'X'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = Button2Click
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 512
    Width = 395
    Height = 19
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    Panels = <>
    ParentShowHint = False
    ShowHint = False
    SimplePanel = True
    SimpleText = 'Ready'
    UseSystemFont = False
  end
  object TableButton: TButton
    Left = 280
    Top = 242
    Width = 97
    Height = 50
    Caption = 'UpdateTable'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = TableButtonClick
  end
  object OpenReverseTableButton: TButton
    Left = 32
    Top = 41
    Width = 62
    Height = 25
    Caption = 'Sellect'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    OnClick = OpenReverseTableButtonClick
  end
  object ProgressBar: TProgressBar
    Left = 0
    Top = 492
    Width = 395
    Height = 17
    MarqueeInterval = 1
    Step = 1
    TabOrder = 12
  end
  object OpenDialogFile: TOpenDialog
    Left = 72
    Top = 82
  end
  object OpenDialogTable: TOpenDialog
    Left = 72
  end
  object OpenDialogKey: TOpenDialog
    Left = 64
    Top = 154
  end
  object SaveDialog1: TSaveDialog
    Left = 176
    Top = 218
  end
  object OpenDialogReverseTable: TOpenDialog
    Left = 72
    Top = 33
  end
end