<template>
  <div class="container">
    <Header>
    </Header>
    <b-container>
      <b-row class="mt-4">
        <b-col>
          <b-form inline>
            <b-form-file
              id="inline-form-input-file"
              @change="onFileChange"
              placeholder="Выберите файл с результатами..."
            ></b-form-file>
          </b-form>
        </b-col>
      </b-row>
      <b-row class="mt-4">
        <b-col>
          <b-card variant="info">
            <p class="mb-0"><strong>Всего заявок обработано:</strong> 3</p>
          </b-card>
        </b-col>
      </b-row>
      <b-row class="mt-4">
        <b-container>
          <b-card no-body>
            <b-tabs pills card>
              <b-tab title="График отпусков" active><b-card-text>
                <b-form-input class="mb-4" type="search" v-model="currentSearchQuery" placeholder="Введите номер сотрудника"></b-form-input>
                <div v-for="(month, key) in computedState">
                  <b-container class="mb-2">
                    <b-row>
                      <b-col cols="2"><h4>{{ months[key] }}</h4></b-col>
                      <b-col cols="10"><b-container>
                        <b-row>
                          <b-col v-for="leave in month" :key="leave.id" cols="4" class="mb-4">
                            <b-card :title="'Сотрудник ' + leave.id" bg-variant="light" class="shadow-sm">
                              <p><span class="text-muted">Часы отпуска: </span>{{leave.hours}}</p>
                            </b-card>
                          </b-col>
                        </b-row>
                      </b-container>
                      </b-col>
                    </b-row>
                  </b-container>
                  <hr>
                </div>
              </b-card-text></b-tab>
              <b-tab title="Работодатель"><b-card-text>
                <b-form-input type="search" model="currentEmployeeQuery" placeholder="Введите номер сотрудника"></b-form-input>
                <div>
                <h4 class="mt-4 mb-3">Сотрудник 1</h4>
                <p><span class="text-muted">Рабочие дни в год: </span>234</p>
                <p><span class="text-muted">Отпуски в год: </span>30</p>
                <p><span class="text-muted">Нераспределенные отпуски: </span>13</p>
                <p><span class="text-muted">Коэффициент удовлетворенности: </span>1.2</p>
                <b-button v-b-toggle.collapse-1-inner size="sm">Показать отпуски</b-button>
                <b-collapse id="collapse-1-inner" class="mt-2">
                  <div>
                    <div>
                      <h5>Февраль</h5>
                      <p><span class="text-muted">Продолжительность отпуска: </span>42</p>
                    </div>
                    <div>
                      <h5>Март</h5>
                      <p><span class="text-muted">Продолжительность отпуска: </span>38</p>
                    </div>
                  </div>
                </b-collapse>
                </div>
                <hr />
                <div>
                <h4 class="mt-4 mb-3">Сотрудник 2</h4>
                <p><span class="text-muted">Рабочие дни в год: </span>234</p>
                <p><span class="text-muted">Отпуски в год: </span>30</p>
                <p><span class="text-muted">Нераспределенные отпуски: </span>13</p>
                <p><span class="text-muted">Коэффициент удовлетворенности: </span>1.2</p>
                <b-button v-b-toggle.collapse-2-inner size="sm">Показать отпуски</b-button>
                <b-collapse id="collapse-2-inner" class="mt-2">
                  <div>
                    <div>
                      <h5>Февраль</h5>
                      <p><span class="text-muted">Продолжительность отпуска: </span>42</p>
                    </div>
                    <div>
                      <h5>Март</h5>
                      <p><span class="text-muted">Продолжительность отпуска: </span>38</p>
                    </div>
                  </div>
                </b-collapse>
                </div>
                <hr />
              </b-card-text></b-tab>
              <b-tab title="Производитель"><b-card-text>
                <b-table :items="currentState.manufacturer" :fields="fields"></b-table>
              </b-card-text></b-tab>
            </b-tabs>
          </b-card>
        </b-container>
      </b-row>
    </b-container>
  </div>
</template>

<script>
import Vue from 'vue'

export default {
  methods: {
    onFileChange(e) {
      let files = e.target.files || e.dataTransfer.files
      if (!files.length) return
      console.log(files[0])
    }
  },
  computed: {
    computedState: function() {
      return this.currentState.summary.map(
        (value) => {
          return value.filter(
            (value) => {
              console.log(value.id)
              return String(value.id).includes(this.currentSearchQuery)
            }
          )
        }
      )
    }
  },
  data() {
    return {
      currentSearchQuery: "",
      fields: [
      {
        key: "month",
        label: "Месяц"
      },
      {
        key: "qualification",
        label: "Квалификация",
      },
      {
        key: "requiredHours",
        label: "Необходимые часы"
      },
      {
        key: "hoursAllocated",
        label: "Часы выделены"
      }
    ],
    months: {
      0: "Январь",
      1: "Февраль",
      2: "Март",
      3: "Апрель",
      4: "Май",
      5: "Июнь",
      6: "Июль",
      7: "Август",
      8: "Сентябрь",
      9: "Октябрь",
      10: "Ноябрь",
      11: "Декабрь"
    },
    currentFile: {},
    currentState: {
      summary: [
        [
          {
            "id": 432,
            "hours": 36
          }
        ],
        [
          {
            "id": 2,
            "hours": 12,
            "comment": "И так далее, все колонки из таблицы можно передавать"
          }
        ],
        [
          {
            "id": 2,
            "hours": 12,
            "comment": "И так далее, все колонки из таблицы можно передавать"
          },
          {
            "id": 4,
            "hours": 12,
            "comment": "И так далее, все колонки из таблицы можно передавать"
          }
        ],
        [],
        [
          {
            "id": 6,
            "hours": 14
          },
          {
          "id": 8,
          "hours": 14
          }
        ],
        [],
        [],
        [],
        [],
        [],
        [],
        []
      ],
      "employer": {
        "leaves": [
          {
            "month": 3,
            "comment": "Другие поля сущности отпуска"
          }
        ],
        "workDaysPerYear": 234,
        "leavesPerYear": 30,
        "unallocatedLeaves": 13,
        "fulfillmentCoefficient": 1.2
      },
      "manufacturer": [
        {
          "month": "Январь",
          "qualification": "Q1",
          "requiredHours": 15568,
          "hoursAllocated": 16000,
        }
      ]
      }
    }
  }
}
</script>

<style>
</style>
